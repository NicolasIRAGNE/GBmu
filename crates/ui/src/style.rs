pub(crate) mod fonts;
pub(crate) mod theme;
pub(crate) mod register;

pub use register::Register;
pub use theme::Theme;

pub trait Style {
    fn style(theme: Theme) -> Self;
}
