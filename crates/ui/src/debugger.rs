mod cpu;
mod disassembler;
mod menu;

use iced::{Column, Row};
use iced_wgpu::Renderer;
use iced_winit::{Color, Command, Element,  Program};

use cpu::{Cpu, CpuMsg};
use disassembler::{Disassembler, DisassMsg};
use menu::{Menu, MenuMsg};

use crate::style::Theme;

pub struct Debugger {
    theme: Theme,
    cpu: Cpu,
    disassembler: Disassembler,
    menu: Menu
}

#[derive(Debug, Clone)]
pub enum Message {
    Cpu(CpuMsg),
    Disassembler(DisassMsg),
    Menu(MenuMsg),
    Refresh,
}

impl Debugger {
    pub fn new() -> Self {
        Self {
            theme: Theme::Light,
            cpu: Cpu::new(),
            disassembler: Disassembler::new(),
            menu: Menu::new()
        }
    }

    pub fn background_color(&self) -> Color {
        self.theme.background_color()
    }

    pub fn refresh(&mut self) {
        self.cpu.refresh();
        self.disassembler.refresh();
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
            Message::Disassembler(message) => {
                let _ = self.disassembler.update(message);
            },
            Message::Menu(message) => self.menu.update(message),
            Message::Refresh => self.refresh(),
        }

        Command::none()
    }

    fn view(&mut self) -> Element<Message, Self::Renderer> {
        let cpu = self
            .cpu
            .view(self.theme)
            .map(Message::Cpu);
        let disassembler = self.disassembler.view().map(Message::Disassembler);
        let menu = self.menu.view(self.theme).map(Message::Menu);
        let middle = Row::new().push(cpu).push(disassembler);
        Column::new().push(menu).push(middle).into()
        
    }
}
