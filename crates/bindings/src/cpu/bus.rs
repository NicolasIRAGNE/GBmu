use crate::cpu::{Bits16, Bits8, Registers};

use std::fmt::Debug;

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
