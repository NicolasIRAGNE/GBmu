use iced_wgpu::wgpu::util::StagingBelt;

use bindings::cpu;
use bindings::joypad::{Joypad, Control};
use gilrs::Gilrs;
use iced_winit::winit::dpi::PhysicalSize;
use log::error;
use pixels::SurfaceTexture;

use iced_winit::{
    futures::executor::LocalPool,
    winit::{
        dpi::LogicalSize,
        event::{
            ElementState::{self, Pressed, Released},
            ModifiersState, VirtualKeyCode, WindowEvent,
        },
        event_loop::{ControlFlow, EventLoop},
        window::{Window, WindowBuilder, WindowId},
    },
};
use pixels::Pixels;

const WIDTH: u32 = 160;
const HEIGHT: u32 = 144;

pub struct Emulator {
    pub id: WindowId,
    pub window: Window,
    //pub state: ui::Emulator,
    pub size: PhysicalSize<u32>,
    pub modifiers: ModifiersState,
    pub resized: bool,
    pub factor: f64,
    pub staging_belt: StagingBelt,
    pub format_pool: LocalPool,
    pub pixels: Pixels,
    pub gilrs: Gilrs,
}

impl Emulator {
    pub fn new(event_loop: &EventLoop<()>) -> Self {
        let title = "GBMU";
        let gilrs = Gilrs::new().unwrap();
        let window = {
            let size = LogicalSize::new(WIDTH as f64, HEIGHT as f64);
            WindowBuilder::new()
                .with_title(title)
                .with_inner_size(size)
                .with_min_inner_size(size)
                .build(event_loop)
                .unwrap()
        };
        let modifiers = ModifiersState::default();
        let factor = window.scale_factor();

        let id = window.id();
        let resized = false;

        // Initialize wgpu
        let size = window.inner_size();
        let surface_texture = SurfaceTexture::new(size.width, size.height, &window);
        let pixels = Pixels::new(WIDTH, HEIGHT, surface_texture).unwrap();

        // Initialize staging belt and local pool
        let staging_belt = StagingBelt::new(5 * 1024);
        let format_pool = LocalPool::new();

        Self {
            id,
            window,
            modifiers,
            size,
            //   state,
            resized,
            factor,
            staging_belt,
            format_pool,
            pixels,
            gilrs,
        }
    }

    pub fn process_event(&mut self, event: WindowEvent, control_flow: &mut ControlFlow) {
        match event {
            WindowEvent::Resized(size) => {
                //      self.state.resize(size, self.window.scale_factor());
                self.size = size;
                self.resized = true;
            }
            WindowEvent::CloseRequested => {
                println!("Request to close on Emulator");
                *control_flow = ControlFlow::Exit;
            }
            WindowEvent::ModifiersChanged(new_modifiers) => {
                self.modifiers = new_modifiers;
            }
            WindowEvent::KeyboardInput {
                device_id: _,
                input,
                is_synthetic: _,
            } => {
                if let Some(key) = input.virtual_keycode {
                    Emulator::handle_input(key, input.state);
                }
            }
            _ => (),
        };
    }

    pub fn handle_input(key: VirtualKeyCode, state: ElementState) {
        match (key, state) {
            (VirtualKeyCode::Space, Pressed) => Joypad::Select.handle_input(true),
            (VirtualKeyCode::Space, Released) => Joypad::Select.handle_input(false),
            (VirtualKeyCode::Return, Pressed) => Joypad::Start.handle_input(true),
            (VirtualKeyCode::Return, Released) => Joypad::Start.handle_input(false),
            (VirtualKeyCode::A, Pressed) => Joypad::A.handle_input(true),
            (VirtualKeyCode::A, Released) => Joypad::A.handle_input(false),
            (VirtualKeyCode::S, Pressed) => Joypad::B.handle_input(true),
            (VirtualKeyCode::S, Released) => Joypad::B.handle_input(false),
            (VirtualKeyCode::Up, Pressed) => Joypad::Up.handle_input(true),
            (VirtualKeyCode::Up, Released) => Joypad::Up.handle_input(false),
            (VirtualKeyCode::Down, Pressed) => Joypad::Down.handle_input(true),
            (VirtualKeyCode::Down, Released) => Joypad::Down.handle_input(false),
            (VirtualKeyCode::Left, Pressed) => Joypad::Left.handle_input(true),
            (VirtualKeyCode::Left, Released) => Joypad::Left.handle_input(false),
            (VirtualKeyCode::Right, Pressed) => Joypad::Right.handle_input(true),
            (VirtualKeyCode::Right, Released) => Joypad::Right.handle_input(false),
            (VirtualKeyCode::C, Pressed) => Control::DebugPalette.handle_control(),
            _ => (),
        }
    }

    pub fn resize(&mut self) {
        if self.resized {
            self.pixels
                .resize_surface(self.size.width, self.size.height);
            self.resized = false;
        }
    }

    pub fn request_redraw(&mut self) {
        self.window.request_redraw();
    }

    pub fn redraw(&mut self, control_flow: &mut ControlFlow) {
        self.resize();
        let frame = self.pixels.get_frame();

        cpu::render(frame);

        if let Err(e) = self.pixels.render() {
            *control_flow = ControlFlow::Exit;
            error!("unable to render: {}", e);
        }
    }
}
