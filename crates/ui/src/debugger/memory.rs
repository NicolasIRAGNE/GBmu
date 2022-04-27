use iced::Element;
//use ppu::Ppu;

use crate::style::Theme;
use crate::widgets::hexdump;

pub struct Memory {
    pub rom: hexdump::State,
}

#[derive(Debug, Clone)]
pub enum MemoryMsg {
    ActiveTab(usize),
}

impl Memory {
    pub fn new(data: &'static[u8]) -> Self {
        let mut rom = hexdump::State::default();
        rom.load(data);
        Self {
            rom,
        }
    }

    // pub fn update(&mut self, message: MemoryMsg) {
    //     match message {
    //         MemoryMsg::ActiveTab(tab) => self.active_tab = tab,
    //     }
    // }

    pub fn view(&mut self, _theme: Theme) -> Element<MemoryMsg> {
        hexdump::Hexdump::new(&mut self.rom).into()
    }
}
