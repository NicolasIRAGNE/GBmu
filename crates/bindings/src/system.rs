#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Mode {
    Run,
    Pause,
    Frame
}

impl Default for Mode {
    fn default() -> Self {
        Mode::Run
    }
}
