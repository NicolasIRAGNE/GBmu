use crate::bindings::{
    reset_a, reset_b, reset_down, reset_left, reset_right, reset_select, reset_start, reset_up,
    set_a, set_b, set_down, set_left, set_right, set_select, set_start, set_up,
    debug_palette_toogle
};

pub enum Joypad {
    Start,
    Select,
    A,
    B,
    Up,
    Down,
    Left,
    Right,
}

impl Joypad {
    pub fn handle_input(&self, pressed: bool) {
        unsafe {
            match (self, pressed) {
                (Joypad::Start, true) => set_start(),
                (Joypad::Start, false) => reset_start(),
                (Joypad::Select, true) => set_select(),
                (Joypad::Select, false) => reset_select(),
                (Joypad::A, true) => set_a(),
                (Joypad::A, false) => reset_a(),
                (Joypad::B, true) => set_b(),
                (Joypad::B, false) => reset_b(),
                (Joypad::Up, true) => set_up(),
                (Joypad::Up, false) => reset_up(),
                (Joypad::Down, true) => set_down(),
                (Joypad::Down, false) => reset_down(),
                (Joypad::Left, true) => set_left(),
                (Joypad::Left, false) => reset_left(),
                (Joypad::Right, true) => set_right(),
                (Joypad::Right, false) => reset_right(),
            }
        }
    }
}

pub enum Control {
    DebugPalette
}

impl Control {
    pub fn handle_control(&self) {
        unsafe {
            match self {
                Control::DebugPalette => debug_palette_toogle(),
            }
        }
    }
}
