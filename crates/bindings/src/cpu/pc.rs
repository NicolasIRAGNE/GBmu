use crate::bindings::{gb_global, get_data_8, get_data_16};

pub fn get_u8(address: u16) -> u8 {
    unsafe {
        get_data_8(address)
    }
}

pub fn get_u16(address: u16) -> u16 {
    unsafe {
        get_data_16(address)
    }
}

pub fn get_pc() -> u16 {
    unsafe {
        gb_global.reg.pc
    }
}
