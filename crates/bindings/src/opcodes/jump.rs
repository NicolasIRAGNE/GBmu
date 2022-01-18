use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// Jump nn
/// Unconditional jump to the absolute address specified in the next 16-bits.
/// Cycle: 16
/// Bytes: 3

/// JP cc nn
/// Conditional jump to the absolute address specified by the 16-bit operand nn, depending on the condition cc.
/// Cycle: 16 / 12
/// Bytes: 3

/// JP r8
/// Unconditional jump to the relative address specified in the next 8-bits.
/// Cycle: 12

/// JP cc r8
/// Conditional jump to the relative address specified by the next 8-bits, depending on the condition cc.
/// Cycle: 12 / 8

/// Call nn
/// Unconditional function call to the absolute address specified by the 16-bit operand nn.
/// Cycle: 24

/// Call CC nn
/// Conditional function call to the absolute address specified by the 16-bit operand nn.
/// Cycle: 24 / 12

/// Return nn
/// Unconditional function call to the absolute address specified by the 16-bit operand nn.
/// Cycle: 16

/// Return CC nn
/// Conditional function call to the absolute address specified by the 16-bit operand nn.
/// Cycle: 20 / 8

/// Flags:
///
/// Z - Unuzed
/// N - Unused
/// H - Unused
/// C - Unused
#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Jump {
    NN = 0xC3,
    HL = 0xE9,
    NZNN = 0xC2,
    NCNN = 0xD2,
    ZNN = 0xCA,
    CNN = 0xDA,
    R8b = 0x18,
    NZR8b = 0x20,
    NCR8b = 0x30,
    ZR8b = 0x28,
    CR8b = 0x38,
    Call = 0xCD,
    CallZ = 0xCC,
    CallC = 0xDC,
    CallNZ = 0xC4,
    CallNC = 0xD4,
    Return = 0xC9,
    ReturnZ = 0xC8,
    ReturnC = 0xD8,
    ReturnNZ = 0xC0,
    ReturnNC = 0xD0,
    ReturnInterrupt = 0xD9,
    Reset00 = 0xC7,
    Reset10 = 0xD7,
    Reset20 = 0xE7,
    Reset30 = 0xF7,
    Reset08 = 0xCF,
    Reset18 = 0xDF,
    Reset28 = 0xEF,
    Reset38 = 0xFF,
}

impl fmt::Display for Jump {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Jump::NN => write!(f, "Jump NN(16b)"),
            Jump::HL => write!(f, "Jump HL"),
            Jump::NZNN => write!(f, "Jump NN(16b) if (!Z)"),
            Jump::NCNN => write!(f, "Jump NN(16b) if (!C)"),
            Jump::ZNN => write!(f, "Jump NN(16b) if (Z)"),
            Jump::CNN => write!(f, "Jump NN(16b) if (C)"),
            Jump::R8b => write!(f, "Jump R(8b)"),
            Jump::NZR8b => write!(f, "Jump R(8b) if (!Z)"),
            Jump::NCR8b => write!(f, "Jump R(8b) if (!C)"),
            Jump::ZR8b => write!(f, "Jump R(8b) if (Z)"),
            Jump::CR8b => write!(f, "Jump R(8b) if (C)"),
            Jump::Call => write!(f, "Call"),
            Jump::CallZ => write!(f, "Call if (Z)"),
            Jump::CallC => write!(f, "Call if (C)"),
            Jump::CallNZ => write!(f, "Call if (!Z)"),
            Jump::CallNC => write!(f, "Call if (!C)"),
            Jump::Return => write!(f, "Return"),
            Jump::ReturnZ => write!(f, "Return if (Z)"),
            Jump::ReturnC => write!(f, "Return if (C)"),
            Jump::ReturnNZ => write!(f, "Return if (!Z)"),
            Jump::ReturnNC => write!(f, "Return if (!C)"),
            Jump::ReturnInterrupt => write!(f, "Return Interrupt"),
            Jump::Reset00 => write!(f, "Reset H00"),
            Jump::Reset10 => write!(f, "Reset H10"),
            Jump::Reset20 => write!(f, "Reset H20"),
            Jump::Reset30 => write!(f, "Reset H30"),
            Jump::Reset08 => write!(f, "Reset H08"),
            Jump::Reset18 => write!(f, "Reset H18"),
            Jump::Reset28 => write!(f, "Reset H28"),
            Jump::Reset38 => write!(f, "Reset H38"),
        }
    }
}
