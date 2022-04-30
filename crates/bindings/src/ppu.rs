use crate::bindings::{get_lcdc, get_stat, get_scy, get_scx, get_ly, get_lyc, get_dma, get_bgp, get_obp0, get_obp1, get_wy, get_wx};
use enum_iterator::IntoEnumIterator;

#[derive(Debug, IntoEnumIterator, PartialEq, Clone, Copy)]
pub enum Registers {
    Lcdc,
    State,
    Scy,
    Scx,
    Ly,
    Lyc,
    Dma,
    Bgp,
    Obp0,
    Obp1,
    Wy,
    Wx
}

#[derive(Debug, Default)]
pub struct Data {
    lcdc: u8,
    state: u8,
    scy: u8,
    scx: u8,
    ly: u8,
    lyc: u8,
    dma: u8,
    bgp: u8,
    obp0: u8,
    obp1: u8,
    wy: u8,
    wx: u8
}

impl Data {
    pub fn refresh(&mut self, register: Registers) {
        match register {
            Registers::Lcdc => self.lcdc = register.get(),
            Registers::State => self.state = register.get(),
            Registers::Scy => self.scy = register.get(),
            Registers::Scx => self.scx = register.get(),
            Registers::Ly => self.ly = register.get(),
            Registers::Lyc => self.lyc = register.get(),
            Registers::Dma => self.dma = register.get(),
            Registers::Bgp => self.bgp = register.get(),
            Registers::Obp0 => self.obp0 = register.get(),
            Registers::Obp1 => self.obp1 = register.get(),
            Registers::Wy => self.wy = register.get(),
            Registers::Wx => self.wx = register.get()
        }
    }

    pub fn get(&self, register: Registers) -> u8 {
        match register{
            Registers::Lcdc => self.lcdc,
            Registers::State => self.state,
            Registers::Scx => self.scx,
            Registers::Scy => self.scy,
            Registers::Ly => self.ly,
            Registers::Lyc => self.lyc,
            Registers::Dma => self.dma,
            Registers::Bgp => self.bgp,
            Registers::Obp0 => self.obp0,
            Registers::Obp1 => self.obp1,
            Registers::Wy => self.wy,
            Registers::Wx => self.wx
        }
    }
}

impl Registers {
    pub fn get(&self) -> u8 {
        unsafe {
            match self {
                Registers::Lcdc => get_lcdc(),
                Registers::State => get_stat(),
                Registers::Scy => get_scy(),
                Registers::Scx => get_scx(),
                Registers::Ly => get_ly(),
                Registers::Lyc => get_lyc(),
                Registers::Dma => get_dma(),
                Registers::Bgp => get_bgp(),
                Registers::Obp0 => get_obp0(),
                Registers::Obp1 => get_obp1(),
                Registers::Wy => get_wy(),
                Registers::Wx => get_wx(),
            }
        }
    }

    pub fn get_name(&self) -> String {
        format!("{:^10}",format!("{:?}", self))
    }

    pub fn get_data(&self, data: &Data) -> String{
        format!("{:#X}", data.get(*self))
    }
}
