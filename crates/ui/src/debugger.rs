mod cpu;
mod disassembler;
pub mod memory;
mod ppu;
mod menu;
use bindings::gb_global;
use std::slice;

use bindings::system::Mode;
use iced::{Column, Row};
use iced_wgpu::Renderer;
use iced_winit::{Color, Command, Element, Program};
use std::{cell::RefCell, sync::Arc};

use cpu::{Cpu, CpuMsg};
use disassembler::{DisassMsg, Disassembler};
use memory::{Memory, MemoryMsg};
use menu::{Menu, MenuMsg};
use ppu::{Ppu, PpuMsg};

use crate::style::Theme;

pub struct Debugger {
    theme: Theme,
    cpu: Cpu,
    disassembler: Disassembler,
    memory: Memory,
    menu: Menu,
    ppu: Ppu
}

#[derive(Debug, Clone)]
pub enum Message {
    Cpu(CpuMsg),
    Disassembler(DisassMsg),
    Menu(MenuMsg),
    Memory(MemoryMsg),
    Ppu(PpuMsg),
    Refresh,
    Reload
}

impl Debugger {
    pub fn new(mode: Arc<RefCell<Mode>>) -> Self {
        let memory = unsafe {
            if gb_global.loaded() != 0  {
                let ptr = (*gb_global.rom_ptr).ptr as *const _ as *const u8;
                let rom = slice::from_raw_parts(ptr, (*gb_global.rom_ptr).st.st_size as usize);
                Memory::new(rom, false)
            } else {
                Memory::new(&[0], true)
            }
        };

        Self {
            theme: Theme::Light,
            cpu: Cpu::new(),
            memory,
            disassembler: Disassembler::new(),
            menu: Menu::new(mode),
            ppu: Ppu::new()
        }
    }
    pub fn reload(&mut self) {
        self.memory =  unsafe {
            if gb_global.loaded() != 0  {
                let ptr = (*gb_global.rom_ptr).ptr as *const _ as *const u8;
                let rom = slice::from_raw_parts(ptr, (*gb_global.rom_ptr).st.st_size as usize);
                Memory::new(rom, false)
            } else {
                Memory::new(&[0], true)
            }
        };
    }

    pub fn background_color(&self) -> Color {
        self.theme.background_color()
    }

    pub fn refresh(&mut self) {
        self.cpu.refresh();
        self.disassembler.refresh();
        self.ppu.refresh();
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
            }
            Message::Menu(message) => self.menu.update(message),
            Message::Refresh => self.refresh(),
            Message::Memory(_) => todo!(),
            Message::Reload => self.reload(),
            Message::Ppu(_) => todo!(),
        }

        Command::none()
    }

    fn view(&mut self) -> Element<Message, Self::Renderer> {
        let cpu = self.cpu.view(self.theme).map(Message::Cpu);
        let disassembler = self.disassembler.view().map(Message::Disassembler);
        let memory = self.memory.view(self.theme).map(Message::Memory);
        let ppu = self.ppu.view(self.theme).map(Message::Ppu);
        let menu = self.menu.view(self.theme).map(Message::Menu);
        let top = Row::new().push(cpu).push(disassembler).push(ppu);
        let low = Row::new().push(memory);
        Column::new().push(menu).push(top).push(low).into()
    }
}
