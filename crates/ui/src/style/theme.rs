mod dark;
mod light;

use iced::{button, checkbox, container, Color};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Theme {
    Light,
    Dark,
}

impl Default for Theme {
    fn default() -> Theme {
        Theme::Light
    }
}

impl Theme {
    pub fn boolean(&self, value: bool) -> Color {
        match self {
            Theme::Light => light::boolean(value),
            Theme::Dark => dark::boolean(value),
        }
    }

    pub fn background_color(&self) -> Color {
        match self {
            Theme::Light => light::background_color(),
            Theme::Dark => dark::background_color(),
        }
    }
}

impl From<Theme> for Box<dyn container::StyleSheet> {
    fn from(theme: Theme) -> Self {
        match theme {
            Theme::Light => light::Container.into(),
            Theme::Dark => dark::Container.into(),
        }
    }
}

impl From<Theme> for Box<dyn checkbox::StyleSheet> {
    fn from(theme: Theme) -> Self {
        match theme {
            Theme::Light => light::Checkbox.into(),
            Theme::Dark => dark::Checkbox.into(),
        }
    }
}

impl From<Theme> for Box<dyn button::StyleSheet> {
    fn from(theme: Theme) -> Self {
        match theme {
            Theme::Light => light::Button.into(),
            Theme::Dark => dark::Button.into(),
        }
    }
}
