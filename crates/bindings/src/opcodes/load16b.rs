use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
///1. LD n,nn
/// Description:
///  Put value nn into n.
/// Use with:
///  n = BC,DE,HL,SP
///  nn = 16 bit immediate value
/// Opcodes:
/// Instruction Parameters Opcode Cycles
///  LD BC,nn 01 12
///  LD DE,nn 11 12
///  LD HL,nn 21 12
///  LD SP,nn 31 12

/// PUSH nn
/// Description:
///  Push register pair nn onto stack.
///  Decrement Stack Pointer (SP) twice.
/// Use with:
///  nn = AF,BC,DE,HL
/// Opcodes:
/// Instruction Parameters Opcode Cycles
///  PUSH AF F5 16
///  PUSH BC C5 16
///  PUSH DE D5 16
///  PUSH HL E5 16

/// POP nn
/// Description:
///  Pop two bytes off stack into register pair nn.
///  Increment Stack Pointer (SP) twice.
/// Use with:
///  nn = AF,BC,DE,HL
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// POP         AF         0xF1   12
/// POP         BC         0xC1   12
/// POP         DE         0xD1   12
/// POP         HL         0xE1   12

#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
pub enum Load16b {
    PushAF = 0xF5,
    PushBC = 0xC5,
    PushDE = 0xD5,
    PushHL = 0xE5,
    PopAF = 0xF1,
    PopBC = 0xC1,
    PopDE = 0xD1,
    PopHL = 0xE1,
    LoadBC = 0x01,
    LoadDE = 0x11,
    LoadHL = 0x21,
    LoadSP = 0x31,
    LoadA16SP = 0x08,
    LoadHLSPr8 = 0xF8,
    LoadSPHL = 0xF9,
}

impl fmt::Display for Load16b {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Load16b::PushAF => write!(f, "Push AF"),
            Load16b::PushBC => write!(f, "Push BC"),
            Load16b::PushDE => write!(f, "Push DE"),
            Load16b::PushHL => write!(f, "Push HL"),
            Load16b::PopAF => write!(f, "Pop AF"),
            Load16b::PopBC => write!(f, "Pop BC"),
            Load16b::PopDE => write!(f, "Pop DE"),
            Load16b::PopHL => write!(f, "Pop HL"),
            Load16b::LoadBC => write!(f, "Load BC (b16"),
            Load16b::LoadDE => write!(f, "Load DE (b16)"),
            Load16b::LoadHL => write!(f, "Load HL (b16)"),
            Load16b::LoadSP => write!(f, "Load SP (b16)"),
            Load16b::LoadA16SP => write!(f, "Load (b16) SP"),
            Load16b::LoadHLSPr8 => write!(f, "Load HL (SP + b8)"),
            Load16b::LoadSPHL => write!(f, "Load SP HL"),
        }
    }
}
