mod cpu;

use iced::Column;
use iced_wgpu::Renderer;
use iced_winit::{Color, Command, Element,  Program};

use cpu::{Cpu, CpuMsg};

use crate::style::Theme;

pub struct Debugger {
    theme: Theme,
    cpu: Cpu,
}

#[derive(Debug, Clone)]
pub enum Message {
    Cpu(CpuMsg),
    Refresh,
}

impl Debugger {
    pub fn new() -> Self {
        Self {
            theme: Theme::Light,
            cpu: Cpu::new(),
        }
    }

    pub fn background_color(&self) -> Color {
        self.theme.background_color()
    }

    pub fn refresh(&mut self) {
        self.cpu.refresh();
    }
}

impl Default for Debugger {
    fn default() -> Self {
        Self::new()
    }
}

impl Program for Debugger {
    type Renderer = Renderer;
    type Message = Message;

    fn update(&mut self, message: Message) -> Command<Message> {
        match message {
            Message::Cpu(message) => self.cpu.update(message),
            Message::Refresh => self.refresh(),
        }

        Command::none()
    }

    fn view(&mut self) -> Element<Message, Self::Renderer> {
        let cpu = self
            .cpu
            .view(self.theme)
            .map(Message::Cpu);
        Column::new().push(cpu).into()
    }
}
