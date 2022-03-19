mod cpu;
mod disassembler;
mod menu;
pub mod memory;
use std::slice;
use bindings::gb_global;

use std::{cell::RefCell, rc::Rc};
use bindings::system::Mode;
use iced::{Column, Row};
use iced_wgpu::Renderer;
use iced_winit::{Color, Command, Element, Program, widget::scrollable};

use cpu::{Cpu, CpuMsg};
use disassembler::{Disassembler, DisassMsg};
use menu::{Menu, MenuMsg};
use memory::{Memory, MemoryBuilder, MemoryMsg};

use crate::{style::Theme, widgets::Hexdump};

pub struct Debugger {
    theme: Theme,
    cpu: Cpu,
    disassembler: Disassembler,
    memory: Memory,
    menu: Menu
}

#[derive(Debug, Clone)]
pub enum Message {
    Cpu(CpuMsg),
    Disassembler(DisassMsg),
    Menu(MenuMsg),
    Memory(MemoryMsg),
    Refresh,
}

impl Debugger {
    pub fn new(mode: Rc<RefCell<Mode>>) -> Self {
        let rom: &[u8] = unsafe {
            let ptr = (*gb_global.rom_ptr).ptr as *const _ as *const u8;
            slice::from_raw_parts(
                ptr,
                (*gb_global.rom_ptr).st.st_size as usize,
            )
        };

        let memory = MemoryBuilder {
            state: scrollable::State::default(),
            rom_builder: |st: &mut scrollable::State| Hexdump::new("rom".to_string(), rom, st),
        }.build();



        Self {
            theme: Theme::Light,
            cpu: Cpu::new(),
            memory,
            disassembler: Disassembler::new(),
            menu: Menu::new(mode)
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
            Message::Memory(_) => todo!(),
        }

        Command::none()
    }

    fn view(&mut self) -> Element<Message, Self::Renderer> {
        let cpu = self
            .cpu
            .view(self.theme)
            .map(Message::Cpu);
        let disassembler = self.disassembler.view().map(Message::Disassembler);
        let memory = self.memory.view(self.theme).map(Message::Memory);
        let menu = self.menu.view(self.theme).map(Message::Menu);
        let middle = Row::new().push(cpu).push(disassembler);
        Column::new().push(menu).push(middle).push(memory).into()
    }
}
