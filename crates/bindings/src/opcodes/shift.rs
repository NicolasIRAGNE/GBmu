use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// SLA r8 | [HL]
/// Shift Left Arithmetic register r8 | byte pointed to by HL.
///
/// C <- [7 <- 0] <- 0

/// SRA r8 | [HL]
/// Shift Right Arithmetic register r8 | byte pointed to by HL.
///
/// [7] -> [7 -> 0] -> C

/// Swap r8 | [HL]
/// Swap upper 4 bits in register r8 | HL and the lower 4 ones.
///
/// C <- [7 <- 0] <- 0

/// SRL r8 | [HL]
/// Shift Right Logic register r8 | byte pointed to by HL.
///
/// [0] -> [7 -> 0] -> C

/// Cycles: 2
///
/// Bytes: 2
///
/// Flags:
///
/// Z - Set if result is 0.
/// N - Unused
/// H - Unused
/// C - Set according to result.

#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Shift {
    LB = 0x20,
    LC = 0x21,
    LD = 0x22,
    LE = 0x23,
    LH = 0x24,
    LL = 0x25,
    LHL = 0x26,
    LA = 0x27,
    RAB = 0x28,
    RAC = 0x29,
    RAD = 0x2A,
    RAE = 0x2B,
    RAH = 0x2C,
    RAL = 0x2D,
    RAHL = 0x2E,
    RAA = 0x2F,
    SB = 0x30,
    SC = 0x31,
    SD = 0x32,
    SE = 0x33,
    SH = 0x34,
    SL = 0x35,
    SHL = 0x36,
    SA = 0x37,
    RLB = 0x38,
    RLC = 0x39,
    RLD = 0x3A,
    RLE = 0x3B,
    RLH = 0x3C,
    RLL = 0x3D,
    RLHL = 0x3E,
    RLA = 0x3F,
}

impl fmt::Display for Shift {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Shift::LB => write!(f, "Shift L B"),
            Shift::LC => write!(f, "Shift L C"),
            Shift::LD => write!(f, "Shift L D"),
            Shift::LE => write!(f, "Shift L E"),
            Shift::LH => write!(f, "Shift L H"),
            Shift::LL => write!(f, "Shift L L"),
            Shift::LHL => write!(f, "Shift L [HL]"),
            Shift::LA => write!(f, "Shift L A"),
            Shift::RAB => write!(f, "Shift R B (Arithmetic)"),
            Shift::RAC => write!(f, "Shift R C (Arithmetic)"),
            Shift::RAD => write!(f, "Shift R D (Arithmetic)"),
            Shift::RAE => write!(f, "Shift R E (Arithmetic)"),
            Shift::RAH => write!(f, "Shift R H (Arithmetic)"),
            Shift::RAL => write!(f, "Shift R L (Arithmetic)"),
            Shift::RAHL => write!(f, "Shift R [HL] (Arithmetic)"),
            Shift::RAA => write!(f, "Shift R A (Arithmetic)"),
            Shift::SB => write!(f, "Swap B"),
            Shift::SC => write!(f, "Swap C"),
            Shift::SD => write!(f, "Swap D"),
            Shift::SE => write!(f, "Swap E"),
            Shift::SH => write!(f, "Swap H"),
            Shift::SL => write!(f, "Swap L"),
            Shift::SHL => write!(f, "Swap [HL]"),
            Shift::SA => write!(f, "Swap A"),
            Shift::RLB => write!(f, "Shift R B (Logical)"),
            Shift::RLC => write!(f, "Shift R C (Logical)"),
            Shift::RLD => write!(f, "Shift R D (Logical)"),
            Shift::RLE => write!(f, "Shift R E (Logical)"),
            Shift::RLH => write!(f, "Shift R H (Logical)"),
            Shift::RLL => write!(f, "Shift R L (Logical)"),
            Shift::RLHL => write!(f, "Shift R [ HL] (Logical)"),
            Shift::RLA => write!(f, "Shift R A (Logical)"),
        }
    }
}
