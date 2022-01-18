use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// NOP
/// No OPeration.
///
/// Cycles: 4
///
/// Bytes: 1
///
/// Flags: None affected.

/// CB
/// CB Operations
///
/// Cycles: 4
///
/// Bytes: 1
///
/// Flags: See Operation.

// STOP
// Enter CPU very low power mode.
// Also used to switch between double and normal speed CPU modes in GBC.
//
// Cycles: -
//
// Bytes: 8
//
// Flags: None affected.

/// HALT
/// Enter CPU low-power consumption mode until an interrupt occurs.
/// The exact behavior of this instruction depends on the state of the IME flag.
///
/// IME set:
///     The CPU enters low-power mode until after an interrupt is about to be serviced.
///     The handler is executed normally, and the CPU resumes execution after
///     the HALT when that returns.
/// IME not set
///     The behavior depends on whether an interrupt is pending (i.e. Ô[IE] & [IF]Õ is non-zero).
///     None pending:
///         As soon as an interrupt becomes pending, the CPU resumes execution.
///         This is like the above, except that the handler is not called.
///     Some pending
///         The CPU continues execution after the HALT,
///         The byte after it is read twice in a row (PC is not incremented, due to a hardware bug).
///
/// Cycles: -
///
/// Bytes: 1
///
/// Flags: None affected.

/// DI
/// Disable Interrupts by clearing the IME flag.
///
/// Cycles: 4
///
/// Bytes: 1
/// Flags: None affected.

/// EI
/// Enable Interrupts by setting the IME flag.
/// The flag is only set AFTER the instruction following EI.
///
/// Cycles: 4
///
/// Bytes: 1
///
/// Flags: None affected.

#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Control {
    NOP = 0x00,
    CB = 0xCB,
    STOP = 0x10,
    HALT = 0x76,
    DI = 0xF3,
    EI = 0xFB,
}

impl fmt::Display for Control {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Control::NOP => write!(f, "NOP"),
            Control::CB => write!(f, "CB"),
            Control::STOP => write!(f, "STOP"),
            Control::HALT => write!(f, "HALT"),
            Control::DI => write!(f, "Dissable Interrupt"),
            Control::EI => write!(f, "Enable Interrupt"),
        }
    }
}
