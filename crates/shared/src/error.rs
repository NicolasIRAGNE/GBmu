use thiserror::Error;

pub type Result<T> = std::result::Result<T, GbmuError>;

#[derive(Error, Debug)]
pub enum GbmuError {
    #[error("Rom loading failed")]
    RomLoad,
}
