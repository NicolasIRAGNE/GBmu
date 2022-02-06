use thiserror::Error;

pub type Result<T> = std::result::Result<T, GbmuError>;

#[derive(Error, Debug)]
pub enum GbmuError {
    #[error("Rom loading failed")]
    RomLoad,
    #[error("cpu_step failed")]
    CpuStep,
    #[error("Unimplemented opcode")]
    Unimplemented(u8),
    #[error("No update in pc")]
    NoUpdate,
}
