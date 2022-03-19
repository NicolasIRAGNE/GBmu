#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Mode {
    Run,
    Pause,
    Idle,
    Frame
}

impl Default for Mode {
    fn default() -> Self {
        Mode::Run
    }
}
