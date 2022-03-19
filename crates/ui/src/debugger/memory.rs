pub mod view;

use iced::{Column, Element};
//use ppu::Ppu;
use bindings::gb_global;

use crate::style::Theme;
use crate::widgets::Hexdump;
use std::slice;
use view::View;

pub struct Memory {
    rom: Hexdump,
}

#[derive(Debug, Clone)]
pub enum MemoryMsg {
    ActiveTab(usize),
}

impl Memory {
    pub fn new() -> Self {
        let rom: &[u8] = unsafe {
            let ptr = (*gb_global.rom_ptr).ptr as *const _ as *const u8;
            slice::from_raw_parts(
                ptr,
                (*gb_global.rom_ptr).st.st_size as usize,
            )
        };
        let rom = Hexdump::new("rom".to_string(), rom);
        Self {
            rom,
        }
    }

    // pub fn update(&mut self, message: MemoryMsg) {
    //     match message {
    //         MemoryMsg::ActiveTab(tab) => self.active_tab = tab,
    //     }
    // }

    pub fn view(&mut self, theme: Theme) -> Element<MemoryMsg> {
        Column::new().push(self.rom.view(theme)).into()
    }

    /// Get a reference to the memory's bios.
    pub fn rom(&self) -> &Hexdump {
        &self.rom
    }
}

impl Default for Memory {
    fn default() -> Self {
        Self::new()
    }
}
