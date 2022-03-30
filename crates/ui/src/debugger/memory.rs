
use iced::{Column, Element, scrollable};
//use ppu::Ppu;

use crate::style::Theme;
use crate::widgets::Hexdump;
use crate::widgets::hexdump;

pub struct Memory {
    pub state: scrollable::State,
    pub rom: hexdump::State,
}

#[derive(Debug, Clone)]
pub enum MemoryMsg {
    ActiveTab(usize),
}

impl Memory {
    pub fn new(rom: &'static[u8]) -> Self {
        let state = scrollable::State::default();
        let rom = hexdump::State::new("rom".to_string(), rom, );
        Self {
            state,
            rom,
        }
    }

    // pub fn update(&mut self, message: MemoryMsg) {
    //     match message {
    //         MemoryMsg::ActiveTab(tab) => self.active_tab = tab,
    //     }
    // }

    pub fn view(&mut self, _theme: Theme) -> Element<MemoryMsg> {
        let hexdump = Hexdump::new(&mut self.rom);
        Column::new().push(hexdump).into()
    }
}
