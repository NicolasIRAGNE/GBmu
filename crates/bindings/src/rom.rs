use shared::error::{GbmuError, Result};
use std::ffi::CString;

use crate::bindings::init_gb;

pub fn init(rom: String) -> Result<()> {
    let rom = CString::new(rom).expect("Cstring allocation failed");

    unsafe {
        if init_gb(rom.as_ptr()) != 0 {
            Err(GbmuError::RomLoad)
        } else {
           Ok(())
        }
    }
}
