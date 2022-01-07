use iced_wgpu::Renderer;
use iced_winit::widget::slider::{self, Slider};
use iced_winit::widget::{Column, Row, Text};
use iced_winit::{Alignment, Color, Command, Element, Length, Program};

pub struct Debugger {
    background_color: Color,
}

#[derive(Debug, Clone)]
pub enum Message {
    BackgroundColorChanged(Color),
}

impl Debugger {
    pub fn new() -> Self {
        Self {
            background_color: Color::WHITE,
        }
    }

    pub fn background_color(&self) -> Color {
        self.background_color
    }
}


impl Program for Debugger {
    type Renderer = Renderer;
    type Message = Message;

    fn update(&mut self, message: Message) -> Command<Message> {
        match message {
            Message::BackgroundColorChanged(color) => {
                self.background_color = color;
            }
        }

        Command::none()
    }

    fn view(&mut self) -> Element<Message, Renderer> {
        Column::new().push(Text::new("Hello Mate")).into()
    }
}
