use iced::{Column, Element};
//use ppu::Ppu;

use crate::style::Theme;
use crate::widgets::hexdump;
use bindings::gb_global;

pub struct Memory {
    pub rom: hexdump::State,
}

#[derive(Debug, Clone)]
pub enum MemoryMsg {
    ActiveTab(usize),
}

impl Memory {
    pub fn new(data: &'static [u8], is_null: bool) -> Self {
        let mut rom = hexdump::State::default();
        if is_null {
            rom.load(&[0])
        } else {
            rom.load(data);
        }
        Self { rom }
    }

    // pub fn update(&mut self, message: MemoryMsg) {
    //     match message {
    //         MemoryMsg::ActiveTab(tab) => self.active_tab = tab,
    //     }
    // }

    pub fn view(&mut self, _theme: Theme) -> Element<MemoryMsg> {
        unsafe {
            if gb_global.loaded() != 0 {
                hexdump::Hexdump::new(&mut self.rom).into()
            } else {
                Column::new().into()
            }
        }
    }
}
