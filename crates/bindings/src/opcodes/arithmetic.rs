use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;

/// [ADD | ADC] A,n
/// Description:
///  Add [n | n + Carry flag] to A.
/// Use with:
///  n = A,B,C,D,E,H,L,(HL),8b
/// Flags affected:
///  Z - Set if result is zero.
///  N - Reset.
///  H - Set if carry from bit 3.
///  C - Set if carry from bit 7.
/// Opcodes:
/// Instruction Parameters Opcode Cycles | Instruction Parameters Opcode Cycles
/// ADD         A,A        0x87   4        ADC         A,A        0x8F   4
/// ADD         A,B        0x80   4        ADC         A,B        0x88   4
/// ADD         A,C        0x81   4        ADC         A,C        0x89   4
/// ADD         A,D        0x82   4        ADC         A,D        0x8A   4
/// ADD         A,8b       0xC6   8        ADC         A,8b       0xCE   8
/// ADD         A,E        0x83   4        ADC         A,E        0x8B   4
/// ADD         A,H        0x84   4        ADC         A,H        0x8C   4
/// ADD         A,L        0x85   4        ADC         A,L        0x8D   4
/// ADD         A,(HL)     0x86   8        ADC         A,(HL)     0x8E   8

/// [SUB | SBC] n
/// Description:
///  Subtract [n | n + Carry flag] from A.
/// Use with:
///  n = A,B,C,D,E,H,L,(HL),8b
/// Flags affected:
///  Z - Set if result is zero.
///  N - Set.
///  H - Set if no borrow from bit 4.
///  C - Set if no borrow.
/// Opcodes:
/// Instruction Parameters Opcode Cycles | Instruction Parameters Opcode Cycles
///  SUB        A,A          0x97   4        SBC         A,A        0x9F   4
///  SUB        A,B          0x90   4        SBC         A,B        0x98   4
///  SUB        A,C          0x91   4        SBC         A,C        0x99   4
///  SUB        A,D          0x92   4        SBC         A,D        0x9A   4
///  SUB        A,E          0x93   4        SBC         A,E        0x9B   4
///  SUB        A,H          0x94   4        SBC         A,H        0x9C   4
///  SUB        A,L          0x95   4        SBC         A,L        0x9D   4
///  SUB        A,(HL)       0x96   8        SBC         A,(HL)     0x9E   8
///  SUB        A,8b         0xD6   8        SBC         A,8b       0xDE     ?
#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Arithmetic {
    AAA = 0x87,
    AAB = 0x80,
    AAC = 0x81,
    AAD = 0x82,
    AA8b = 0xC6,
    AAE = 0x83,
    AAH = 0x84,
    AAL = 0x85,
    AAHL = 0x86,
    AAcA = 0x8F,
    AAcB = 0x88,
    AAcC = 0x89,
    AAcD = 0x8A,
    AAc8b = 0xCE,
    AAcE = 0x8B,
    AAcH = 0x8C,
    AAcL = 0x8D,
    AAcHL = 0x8E,
    SAA = 0x97,
    SAB = 0x90,
    SAC = 0x91,
    SAD = 0x92,
    SAE = 0x93,
    SAH = 0x94,
    SAL = 0x95,
    SAHL = 0x96,
    SA8b = 0xD6,
    SAcA = 0x9F,
    SAcB = 0x98,
    SAcC = 0x99,
    SAcD = 0x9A,
    SAcE = 0x9B,
    SAcH = 0x9C,
    SAcL = 0x9D,
    SAcHL = 0x9E,
    SAc8b = 0xDE,
    IncB = 0x04,
    IncD = 0x14,
    IncH = 0x24,
    IncHL = 0x34,
    DecB = 0x05,
    DecD = 0x15,
    DecH = 0x25,
    DecHL = 0x35,
    IncC = 0x0C,
    IncE = 0x1C,
    IncL = 0x2C,
    IncA = 0x3C,
    DecC = 0x0D,
    DecE = 0x1D,
    DecL = 0x2D,
    DecA = 0x3D,
    DAA = 0x27,
    SCF = 0x37,
    CPL = 0x2F,
    CCF = 0x3F,
}


impl fmt::Display for Arithmetic {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Arithmetic::AAA => write!(f, "Add A A(No Carry)"),
            Arithmetic::AAB => write!(f, "Add A B(No Carry)"),
            Arithmetic::AAC => write!(f, "Add A C(No Carry)"),
            Arithmetic::AAD => write!(f, "Add A D(No Carry)"),
            Arithmetic::AAE => write!(f, "Add A E(No Carry)"),
            Arithmetic::AAH => write!(f, "Add A H(No Carry)"),
            Arithmetic::AAL => write!(f, "Add A L(No Carry)"),
            Arithmetic::AAHL => write!(f, "Add A [HL](No Carry)"),
            Arithmetic::AA8b => write!(f, "Add A 8b(No Carry)"),
            Arithmetic::AAcA => write!(f, "Add A A(Carry)"),
            Arithmetic::AAcB => write!(f, "Add A B(Carry)"),
            Arithmetic::AAcC => write!(f, "Add A C(Carry)"),
            Arithmetic::AAcD => write!(f, "Add A D(Carry)"),
            Arithmetic::AAcE => write!(f, "Add A E(Carry)"),
            Arithmetic::AAcH => write!(f, "Add A H(Carry)"),
            Arithmetic::AAcL => write!(f, "Add A L(Carry)"),
            Arithmetic::AAcHL => write!(f, "Add A [HL](Carry)"),
            Arithmetic::AAc8b => write!(f, "Add A 8b(Carry)"),
            Arithmetic::SAB => write!(f, "Sub A B(No Carry)"),
            Arithmetic::SAC => write!(f, "Sub A C(No Carry)"),
            Arithmetic::SAD => write!(f, "Sub A D(No Carry)"),
            Arithmetic::SAE => write!(f, "Sub A E(No Carry)"),
            Arithmetic::SAH => write!(f, "Sub A H(No Carry)"),
            Arithmetic::SAL => write!(f, "Sub A L(No Carry)"),
            Arithmetic::SAHL => write!(f, "Sub A [HL](No Carry)"),
            Arithmetic::SAA => write!(f, "Sub A A(No Carry)"),
            Arithmetic::SAcB => write!(f, "Sub A B(Carry)"),
            Arithmetic::SAcC => write!(f, "Sub A C(Carry)"),
            Arithmetic::SAcD => write!(f, "Sub A D(Carry)"),
            Arithmetic::SAcE => write!(f, "Sub A E(Carry)"),
            Arithmetic::SAcH => write!(f, "Sub A H(Carry)"),
            Arithmetic::SAcL => write!(f, "Sub A L(Carry)"),
            Arithmetic::SAcHL => write!(f, "Sub A [HL](Carry)"),
            Arithmetic::SAcA => write!(f, "Sub A A (Carry)"),
            Arithmetic::SA8b => write!(f, "Sub A 8b (No Carry)"),
            Arithmetic::SAc8b => write!(f, "Sub A 8b(Carry)"),
            Arithmetic::IncB => write!(f, "Increase B"),
            Arithmetic::IncD => write!(f, "Increase D"),
            Arithmetic::IncH => write!(f, "Increase H"),
            Arithmetic::IncHL => write!(f, "Increase [HL]"),
            Arithmetic::DecB => write!(f, "Decrease B"),
            Arithmetic::DecD => write!(f, "Decrease D"),
            Arithmetic::DecH => write!(f, "Decrease H"),
            Arithmetic::DecHL => write!(f, "Decrease [HL]"),
            Arithmetic::IncC => write!(f, "Increase C"),
            Arithmetic::IncE => write!(f, "Increase E"),
            Arithmetic::IncL => write!(f, "Increase L"),
            Arithmetic::IncA => write!(f, "Increase A"),
            Arithmetic::DecC => write!(f, "Decrease C"),
            Arithmetic::DecE => write!(f, "Decrease E"),
            Arithmetic::DecL => write!(f, "Decrease L"),
            Arithmetic::DecA => write!(f, "Decrease A"),
            Arithmetic::DAA => write!(f, "Decimal Adjust (DAA)"),
            Arithmetic::SCF => write!(f, "Set Carry Flag"),
            Arithmetic::CPL => write!(f, "Complement Carry Flag"),
            Arithmetic::CCF => write!(f, "Clear Carry Flag"),
        }
    }
}
