#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Mode {
    Run,
    Pause,
    Idle,
    Frame,
    Instruction,
}

impl Default for Mode {
    fn default() -> Self {
        Mode::Idle
    }
}
