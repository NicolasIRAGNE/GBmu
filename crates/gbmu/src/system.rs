use anyhow::Result;
use std::{cell::RefCell, rc::Rc};
use bindings::{gb, system::Mode};
use iced_wgpu::wgpu::Instance;
use iced_winit::winit::event::{Event, StartCause};
use iced_winit::winit::event_loop::{ControlFlow, EventLoop};

use crate::{debugger, emulator};

#[derive(Debug, Default)]
pub struct System {
    mode: Rc<RefCell<Mode>>,
}

pub enum Process {
    Refresh,
    Idle,
    Exit,
}

struct Marker {}
impl Drop for Marker {
    fn drop(&mut self) {
        println!("Successfuly cleaning!");
        gb::cleanup();
    }
}

impl System {
    pub fn try_new(rom: String) -> Result<Self> {
        let system = Self::default();
        gb::init(rom)?;
        Ok(system)
    }

    pub fn run(mut self) {
        let event_loop = EventLoop::new();
        let marker = Marker {};

        //let mut debugger = debugger::Debugger::new(&event_loop, &instance, soc.clone());
        let instance = Instance::new(iced_wgpu::wgpu::Backends::PRIMARY);
        let mut debugger = debugger::Debugger::new(&event_loop, &instance, self.mode.clone());
        let mut emulator = emulator::Emulator::new(&event_loop);
        event_loop.run(move |event, _, flow| {
            let _mark = &marker;
            // Handle Events
            match event {
                Event::NewEvents(StartCause::Init) => {}
                Event::WindowEvent { event, window_id } if window_id == debugger.id => {
                    debugger.process_event(event, flow);
                }
                Event::WindowEvent { event, window_id } if window_id == emulator.id => {
                    emulator.process_event(event, flow);
                }
                Event::MainEventsCleared => {
                    // Run Emulator here
                    match self.process() {
                        Process::Refresh => {
                            debugger.refresh();
                            emulator.request_redraw();
                        }
                        Process::Idle => {}
                        Process::Exit => {
                            *flow = ControlFlow::Exit;
                        }
                    }
                    debugger.update();
                }
                Event::RedrawRequested(window_id) if window_id == debugger.id => {
                    debugger.redraw();
                }
                Event::RedrawRequested(window_id) if window_id == emulator.id => {
                    emulator.redraw(flow);
                }
                _ => (),
            };
        })
    }

    pub fn process(&mut self) -> Process {
        let mode = *self.mode.borrow();
        match mode {
            Mode::Run => {
                if gb::frame() {
                    Process::Refresh
                } else {
                    Process::Exit
                }
            }
            Mode::Pause => Process::Idle,
            Mode::Frame => {
                *self.mode.borrow_mut() = Mode::Pause;
                if gb::frame() {
                    Process::Refresh
                } else {
                    Process::Exit
                }
            }
        }
    }
}
