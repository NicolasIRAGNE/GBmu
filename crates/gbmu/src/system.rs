use anyhow::Result;
use bindings::cpu;
use iced_wgpu::wgpu::Instance;
use iced_winit::winit::event::{Event, StartCause};
use iced_winit::winit::event_loop::{ControlFlow, EventLoop};

use crate::{debugger, emulator};

pub struct System {}

struct Marker {}
impl Drop for Marker {
    fn drop(&mut self) {
        println!("Successfuly cleaning!");
        cpu::cleanup();
    }
}

impl System {
    pub fn run() {
        let event_loop = EventLoop::new();
        let marker = Marker {};

        //let mut debugger = debugger::Debugger::new(&event_loop, &instance, soc.clone());
        let instance = Instance::new(iced_wgpu::wgpu::Backends::PRIMARY);
        let mut debugger = debugger::Debugger::new(&event_loop, &instance);
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
                    if cpu::frame() {
                        emulator.request_redraw();
                    } else {
                        *flow = ControlFlow::Exit;
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

    pub fn init(rom: String) -> Result<()> {
        Ok(cpu::init(rom)?)
    }
}
