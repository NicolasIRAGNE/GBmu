use ui::debugger::Message;
use std::{cell::RefCell, sync::Arc};
use bindings::system::Mode;

use iced_wgpu::{
    wgpu::{
        self, util::StagingBelt,  Device, DeviceDescriptor, Features,
        Instance, Limits, PowerPreference, PresentMode, Queue, RequestAdapterOptions, Surface,
         TextureFormat, TextureUsages 
    },
    Backend, Color, Renderer, Settings, Viewport,
};

use iced_winit::{
    futures::{self, executor::LocalPool, task::SpawnExt},
    program,
    winit::{
        dpi::{PhysicalPosition, PhysicalSize},
        event::{ModifiersState, WindowEvent},
        event_loop::{ControlFlow, EventLoop},
        window::{Window, WindowBuilder, WindowId},
    },
    Clipboard, Debug,
};

pub struct Debugger {
    pub id: WindowId,
    pub window: Window,
    pub surface: Surface,
    pub device: Device,
    pub queue: Queue,
    pub clipboard: Clipboard,
    pub cursor: PhysicalPosition<f64>,
    pub state: program::State<ui::debugger::Debugger>,
    pub modifiers: ModifiersState,
    pub viewport: Viewport,
    pub resized: bool,
    pub staging_belt: StagingBelt,
    pub format: TextureFormat,
    pub format_pool: LocalPool,
    pub renderer: Renderer,
    pub debug: Debug,
}

fn init_device(
    window: &Window,
    instance: &Instance,
    surface: &Surface,
) -> (TextureFormat, Device, Queue) {
    let (format, (device, queue)) = futures::executor::block_on(async {
        let adapter = instance
            .request_adapter(&RequestAdapterOptions {
                power_preference: PowerPreference::HighPerformance,
                compatible_surface: Some(surface),
                force_fallback_adapter: false,
            })
            .await
            .expect("Request adapter");

        (
            surface
                .get_preferred_format(&adapter)
                .expect("Get preferred format"),
            adapter
                .request_device(
                    &DeviceDescriptor {
                        label: None,
                        features: Features::empty(),
                        limits: Limits::default(),
                    },
                    None,
                )
                .await
                .expect("Request device"),
        )
    });

    let size = window.inner_size();
    surface.configure(
        &device,
        &iced_wgpu::wgpu::SurfaceConfiguration {
            usage: TextureUsages::RENDER_ATTACHMENT,
            format,
            width: size.width,
            height: size.height,
            present_mode: PresentMode::Mailbox,
        },
    );
    (format, device, queue)
}

impl Debugger {
    pub fn new(event_loop: &EventLoop<()>, instance: &Instance, mode: Arc<RefCell<Mode>>) -> Self {
        let title = "Debugger";
        let size = iced_winit::winit::dpi::Size::Physical(PhysicalSize::new(1340, 768));
        let window = WindowBuilder::new()
            .with_title(title)
            .with_resizable(false)
            .with_inner_size(size)
            .build(event_loop)
            .unwrap();

        let physical_size = window.inner_size();
        let cursor = PhysicalPosition::new(-1.0, -1.0);
        let viewport = Viewport::with_physical_size(
            iced_winit::Size::new(physical_size.width, physical_size.height),
            window.scale_factor(),
        );
        let clipboard = Clipboard::connect(&window);
        let modifiers = ModifiersState::default();

        let id = window.id();
        let resized = false;

        // Initialize wgpu
        let surface = unsafe { instance.create_surface(&window) };
        let (format, device, queue) = init_device(&window, instance, &surface);

        // Initialize staging belt and local pool
        let staging_belt = StagingBelt::new(5 * 1024);
        let format_pool = LocalPool::new();

        let debugger = ui::debugger::Debugger::new(mode);
        let mut debug = Debug::new();
        let mut renderer = Renderer::new(Backend::new(&device, Settings::default(), format));
        let state =
            program::State::new(debugger, viewport.logical_size(), &mut renderer, &mut debug);
        //let state = ui::Debugger::new(&window, &device, format, soc);

        Self {
            id,
            window,
            surface,
            device,
            queue,
            viewport,
            cursor,
            modifiers,
            clipboard,
            state,
            resized,
            staging_belt,
            format,
            format_pool,
            renderer,
            debug,
        }
    }

    pub fn reload(&mut self) {
        self.state.queue_message(Message::Reload);
    }

    pub fn refresh(&mut self) {
        self.state.queue_message(Message::Refresh);
    }

    pub fn process_event(&mut self, event: WindowEvent, control_flow: &mut ControlFlow) {
        match event {
            WindowEvent::Resized(new_size) => {
                self.viewport = Viewport::with_physical_size(
                    iced_winit::Size::new(new_size.width, new_size.height),
                    self.window.scale_factor(),
                );
                self.resized = true;
            }
            WindowEvent::CloseRequested => {
                println!("Request to close on debugger");
                *control_flow = ControlFlow::Exit;
                return;
            }
            WindowEvent::ModifiersChanged(new_modifiers) => {
                self.modifiers = new_modifiers;
            }
            WindowEvent::CursorMoved { position, .. } => {
                self.cursor = position;
            }
            _ => (),
        };
        // Map window event to iced event
        if let Some(event) =
            iced_winit::conversion::window_event(&event, self.window.scale_factor(), self.modifiers)
        {
            self.state.queue_event(event);
        }
    }

    pub fn update(&mut self) {
        if !self.state.is_queue_empty() {
            let _ = self.state.update(
                self.viewport.logical_size(),
                iced_winit::conversion::cursor_position(self.cursor, self.viewport.scale_factor()),
                &mut self.renderer,
                &mut self.clipboard,
                &mut self.debug,
            );
            self.window.request_redraw();
        }
    }

    pub fn resize(&mut self) {
        if self.resized {
            let size = self.window.inner_size();

            self.surface.configure(
                &self.device,
                &wgpu::SurfaceConfiguration {
                    usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
                    format: self.format,
                    width: size.width,
                    height: size.height,
                    present_mode: wgpu::PresentMode::Mailbox,
                },
            );

            self.resized = false;
        }
    }

    pub fn clear<'a>(
        &self,
        target: &'a wgpu::TextureView,
        encoder: &'a mut wgpu::CommandEncoder,
        background_color: Color,
    ) -> wgpu::RenderPass<'a> {
        encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
            label: None,
            color_attachments: &[wgpu::RenderPassColorAttachment {
                view: target,
                resolve_target: None,
                ops: wgpu::Operations {
                    load: wgpu::LoadOp::Clear({
                        let [r, g, b, a] = background_color.into_linear();

                        wgpu::Color {
                            r: r as f64,
                            g: g as f64,
                            b: b as f64,
                            a: a as f64,
                        }
                    }),
                    store: true,
                },
            }],
            depth_stencil_attachment: None,
        })
    }

    pub fn redraw(&mut self) {
        self.resize();
        match self.surface.get_current_texture() {
            Ok(frame) => {
                let mut encoder = self
                    .device
                    .create_command_encoder(&wgpu::CommandEncoderDescriptor { label: None });

                let program = self.state.program();

                let view = frame
                    .texture
                    .create_view(&wgpu::TextureViewDescriptor::default());

                // Clear screen to iced background color
                self.clear(&view, &mut encoder, program.background_color());

                //Draw iced
                self.renderer.with_primitives(|backend, primitive| {
                    backend.present(
                        &self.device,
                        &mut self.staging_belt,
                        &mut encoder,
                        &view,
                        primitive,
                        &self.viewport,
                        &self.debug.overlay(),
                    );
                });

                // Then we submit the work
                self.staging_belt.finish();
                self.queue.submit(Some(encoder.finish()));
                frame.present();

                // Update the mouse cursor
                self.window
                    .set_cursor_icon(iced_winit::conversion::mouse_interaction(
                        self.state.mouse_interaction(),
                    ));

                // And recall staging buffers
                self.format_pool
                    .spawner()
                    .spawn(self.staging_belt.recall())
                    .expect("Recall staging buffers");

                self.format_pool.run_until_stalled();
            }
            Err(error) => match error {
                wgpu::SurfaceError::OutOfMemory => {
                    panic!("Swapchain error: {}. Rendering cannot continue.", error)
                }
                _ => {
                    // Try rendering again next frame.
                    self.window.request_redraw();
                }
            },
        }
    }
}
