pub mod view;

use ouroboros::self_referencing;
use iced::{Column, Element, scrollable};
//use ppu::Ppu;

use crate::style::Theme;
use crate::widgets::Hexdump;
use view::View;

#[self_referencing(pub_extras)]
pub struct Memory {
    state: scrollable::State,
    #[borrows(mut state)]
    #[not_covariant]
    rom: Hexdump<'this>,
}

#[derive(Debug, Clone)]
pub enum MemoryMsg {
    ActiveTab(usize),
}

impl Memory {
    // pub fn new() -> Self {
    //     let rom: &[u8] = unsafe {
    //         let ptr = (*gb_global.rom_ptr).ptr as *const _ as *const u8;
    //         slice::from_raw_parts(
    //             ptr,
    //             (*gb_global.rom_ptr).st.st_size as usize,
    //         )
    //     };
    //     let state = scrollable::State::default();
    //     let rom = Hexdump::new("rom".to_string(), rom, );
    //     Self {
    //         state,
    //         rom,
    //     }
    // }

    // pub fn update(&mut self, message: MemoryMsg) {
    //     match message {
    //         MemoryMsg::ActiveTab(tab) => self.active_tab = tab,
    //     }
    // }

    pub fn view(&mut self, theme: Theme) -> Element<MemoryMsg> {
        Column::new().push(self.rom().view(theme)).into()
    }

    /// Get a reference to the memory's bios.
    pub fn rom(&self) -> &Hexdump {
        &self.rom()
    }
}
