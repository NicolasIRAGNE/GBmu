use anyhow::Result;
use bindings::cpu;
use iced_winit::winit::event::{Event, StartCause};
use iced_winit::winit::event_loop::{ControlFlow, EventLoop};

use crate::emulator;

pub struct System {}

impl System {
    pub fn run() {
        let event_loop = EventLoop::new();

        //let mut debugger = debugger::Debugger::new(&event_loop, &instance, soc.clone());
        let mut emulator = emulator::Emulator::new(&event_loop);
        event_loop.run(move |event, _, flow| {
            // Handle Events
            match event {
                Event::NewEvents(StartCause::Init) => {}
                // Event::WindowEvent { event, window_id } if window_id == debugger.id => {
                //     debugger.process_event(event, flow);
                // }
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
                }
                // Event::RedrawRequested(window_id) if window_id == debugger.id => {
                //     debugger.redraw();
                // }
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
