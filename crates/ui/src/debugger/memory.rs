pub mod view;

use iced::{Column, Element, Length, Scrollable, scrollable};
//use ppu::Ppu;

use crate::style::Theme;
use crate::widgets::{Text, Hexdump};
use view::View;

pub struct Memory {
    pub state: scrollable::State,
    pub rom: Hexdump,
}

#[derive(Debug, Clone)]
pub enum MemoryMsg {
    ActiveTab(usize),
}

impl Memory {
    pub fn new(rom: &'static[u8]) -> Self {
        let state = scrollable::State::default();
        let rom = Hexdump::new("rom".to_string(), rom, );
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

    pub fn view(&mut self, theme: Theme) -> Element<MemoryMsg> {
        let mut hexdump = Scrollable::new(&mut self.state)
            .width(Length::Shrink)
            .height(Length::Shrink);
        for data in &self.rom.data {
            hexdump = hexdump.push(Text::new(data).light(20));
        };
        Column::new().push(self.rom.view(theme)).push(hexdump).into()
    }
}
