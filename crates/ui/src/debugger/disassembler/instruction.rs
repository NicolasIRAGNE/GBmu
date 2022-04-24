use super::disass::Disass;
use crate::widgets::Cell;
use iced::button;
use iced::{Element, Row};
use num_enum::TryFromPrimitive;

use super::DisassMsg;
use bindings::opcodes::Arithmetic;
use bindings::opcodes::Arithmetic16b;
use bindings::opcodes::Bitset;
use bindings::opcodes::Control;
use bindings::opcodes::Jump;
use bindings::opcodes::Load;
use bindings::opcodes::Load16b;
use bindings::opcodes::Logic;
use bindings::opcodes::Reset;
use bindings::opcodes::Rotate;
use bindings::opcodes::Shift;
use bindings::opcodes::Test;
use shared::GbmuError;
use bindings::cpu::pc;

pub struct Instruction {
    breakpoint: button::State,
    bp_status: bool,
    address: u16,
    disass: Cycles,
    pub is_jump: bool,
    //is_next: bool,
}

impl Instruction {
    fn from_cb(opcode: u8) -> Cycles {
        if let Ok(opcode) = Rotate::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Shift::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Test::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Bitset::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else {
            let opcode = Reset::try_from_primitive(opcode).unwrap();
            Cycles::Absolute(Disass::<u8>::from(opcode))
        }
    }

    fn from_jump(jump: Jump) -> Result<Cycles, GbmuError> {
        if let Ok(disass) = Disass::<(u8, u8)>::try_from(jump) {
            Ok(Cycles::Conditionnal(disass))
        } else {
            Ok(Cycles::Absolute(Disass::<u8>::try_from(jump)?))
        }
    }

    fn from_opcode(opcode: u8) -> Cycles {
        if let Ok(opcode) = Load::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Load16b::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Arithmetic::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Logic::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Control::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else if let Ok(opcode) = Arithmetic16b::try_from_primitive(opcode) {
            Cycles::Absolute(Disass::<u8>::from(opcode))
        } else {
            Cycles::unimplemented(opcode)
        }
    }

    pub fn try_new(address: u16, _is_next: bool) -> Result<Self, GbmuError> {
        let opcode = pc::get_u8(address); //Get opcode
        let mut is_jump = false;

        let mut disass: Cycles = {
            if opcode == 0xCB {
                let opcode = pc::get_u8(address + 1); // Get opcode;
                Self::from_cb(opcode)
            } else if let Ok(opcode) = Jump::try_from_primitive(opcode) {
                is_jump = true;
                Self::from_jump(opcode)?
            } else {
                Self::from_opcode(opcode)
            }
        };
        disass.set(address)?;
        Ok(Self {
            breakpoint: button::State::default(),
            bp_status: false,
            address,
            disass,
            is_jump, // is_next,
        })
    }

    pub fn view(&mut self) -> Element<DisassMsg> {
        let address = format!("{:#04X}", self.address);
        let address = Cell::light(format!("{:^10}", address), 20);
        let line = if self.bp_status {
            Row::new().push(Cell::light("B".to_string(), 20))
        } else {
            Row::new().push(Cell::light(" ".to_string(), 20))
        };
        let line = line.push(address).push(self.disass.view());
        button::Button::new(&mut self.breakpoint, line)
            .on_press(DisassMsg::Breakpoint(self.address))
            .into()
    }

    pub fn fetched(&self) -> u16 {
        match &self.disass {
            Cycles::Absolute(disass) => disass.fetched(),
            Cycles::Conditionnal(disass) => disass.fetched(),
        }
    }
}

enum Cycles {
    Absolute(Disass<u8>),
    Conditionnal(Disass<(u8, u8)>),
}

impl Cycles {
    pub fn unimplemented(opcode: u8) -> Self {
        Self::Absolute(Disass::unimplemented(opcode))
    }

    pub fn set(&mut self, address: u16) -> Result<(), GbmuError> {
        match self {
            Cycles::Absolute(ref mut disass) => disass.data.set(address),
            Cycles::Conditionnal(ref mut disass) => disass.data.set(address),
        }
    }

    pub fn view(&mut self) -> Element<DisassMsg> {
        match self {
            Cycles::Absolute(ref mut disass) => Disass::<u8>::view(disass),
            Cycles::Conditionnal(ref mut disass) => Disass::<(u8, u8)>::view(disass),
        }
    }
}
