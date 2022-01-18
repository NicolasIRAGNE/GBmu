use crate::bindings::copy_registers;
use enum_iterator::IntoEnumIterator;
use std::{ffi::c_void, fmt::Debug};
use std::ptr::addr_of_mut;


#[repr(C)]
#[derive(Default, Debug)]
pub struct Registers {
    pub f: cty::c_uchar,
    pub a: cty::c_uchar,
    pub c: cty::c_uchar,
    pub b: cty::c_uchar,
    pub e: cty::c_uchar,
    pub d: cty::c_uchar,
    pub l: cty::c_uchar,
    pub h: cty::c_uchar,
    pub sp: cty::c_ushort,
    pub pc: cty::c_ushort,
}

impl Registers {
    pub fn refresh(&mut self) {
        let raw = addr_of_mut!(*self);
        unsafe {
            copy_registers(raw as *mut c_void);
        }
    }
}

pub trait Bus<T, O>: Debug {
    fn get(&self, _: T) -> O;
}

impl Bus<Bits8, u8> for Registers {
    fn get(&self, area: Bits8) -> u8 {
        match area {
            Bits8::A => self.a,
            Bits8::F => 0,
            Bits8::B => self.b,
            Bits8::C => self.c,
            Bits8::D => self.d,
            Bits8::E => self.e,
            Bits8::H => self.h,
            Bits8::L => self.l,
        }
    }
}

impl Bus<Flag, bool> for Registers {
    fn get(&self, area: Flag) -> bool {
        self.f & area as u8 != 0
    }
}

impl Bus<Bits16, u16> for Registers {
    fn get(&self, area: Bits16) -> u16 {
        match area {
            Bits16::SP => self.sp,
            Bits16::PC => self.pc,
            Bits16::AF => ((self.a as u16) << 8) ,
            Bits16::BC => ((self.b as u16) << 8) | self.c as u16,
            Bits16::DE => ((self.d as u16) << 8) | self.e as u16,
            Bits16::HL => ((self.h as u16) << 8) | self.l as u16,
        }
    }

}

#[derive(Debug, IntoEnumIterator, PartialEq, Clone, Copy)]
pub enum Bits8 {
    A,
    F,
    B,
    C,
    D,
    E,
    H,
    L,
}

#[derive(Debug, Clone, Copy)]
pub enum Bits16 {
    AF,
    SP,
    PC,
    BC,
    DE,
    HL,
}

#[derive(Debug, IntoEnumIterator, PartialEq, Clone, Copy)]
pub enum Flag {
    /// Zero flag
    /// This flag is set when :
    /// - the result of a math op is zero
    /// - `Cmp` OP match 2 values
    Z = 0x80,

    /// Substract Flag
    /// This flag is set when the last math instruction was a substraction
    N = 0x40,

    /// Half Carry Flag
    /// This flag is set when a carry occurred in the lower nibble of the last math OP
    H = 0x20,

    /// Carry Flag
    /// This flag is set when :
    /// - a carry occurred in the last math OP
    /// - Reg A is the smaller value when doing a `Cmp` OP
    C = 0x10,
}



