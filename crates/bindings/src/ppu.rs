use crate::bindings::{get_lcdc, get_stat};
use enum_iterator::IntoEnumIterator;

#[derive(Debug, IntoEnumIterator, PartialEq, Clone, Copy)]
pub enum Registers {
    Lcdc,
    State
}

#[derive(Debug, Default)]
pub struct Data {
    lcdc: u8,
    state: u8
}

impl Data {
    pub fn refresh(&mut self, register: Registers) {
        match register {
            Registers::Lcdc => self.lcdc = register.get(),
            Registers::State => self.state = register.get(),
        }
    }

    pub fn get(&self, register: Registers) -> u8 {
        match register{
            Registers::Lcdc => self.lcdc,
            Registers::State => self.state,
        }
    }
}

impl Registers {
    pub fn get(&self) -> u8 {
        unsafe {
            match self {
                Registers::Lcdc => get_lcdc(),
                Registers::State => get_stat(),
            }
        }
    }

    pub fn get_name(&self) -> String {
        format!("{:?}", self)
    }

    pub fn get_data(&self, data: &Data) -> String{
        format!("{:#X}", data.get(*self))
    }
}
