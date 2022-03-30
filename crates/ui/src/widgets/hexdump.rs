mod state;

use crate::style::fonts::{HASKLIG_BOLD, HASKLIG_MEDIUM};
use iced_native::layout::{self, Layout};
use iced_native::renderer;
use iced_native::{alignment, text, Color, Element, Length, Point, Rectangle, Size, Widget};
pub use state::State;

pub struct Hexdump<'a, Renderer: text::Renderer> {
    state: &'a mut State,
    width: Length,
    height: Length,
    font: Renderer::Font,
    size: u16,
}

impl<'a, Renderer: text::Renderer> Hexdump<'a, Renderer> {
    pub fn new(state: &'a mut State) -> Self {
        Self {
            state,
            width: Length::Shrink,
            height: Length::Shrink,
            font: Default::default(),
            size: 20,
        }
    }
}
impl<'a, Message, Renderer> Widget<Message, Renderer> for Hexdump<'a, Renderer>
where
    Renderer: renderer::Renderer + text::Renderer,
{
    fn width(&self) -> Length {
        self.width
    }

    fn height(&self) -> Length {
        self.height
    }

    fn layout(&self, renderer: &Renderer, limits: &layout::Limits) -> layout::Node {
        let limits = limits.width(self.width).height(self.height);
        let bounds = limits.max();

        let (width, height) =
            renderer.measure(&self.state.data[0], self.size, self.font.clone(), bounds);

        let size = limits.resolve(Size::new(width, height * 20.));
        layout::Node::new(size)
    }

    fn draw(
        &self,
        renderer: &mut Renderer,
        _style: &renderer::Style,
        layout: Layout<'_>,
        _cursor_position: Point,
        _viewport: &Rectangle,
    ) {
        let mut bounds = layout.bounds();
        let (_ , height) = renderer.measure("A", self.size, self.font.clone(), bounds.size());



        renderer.fill_text(text::Text {
            content: &self.state.data[0],
            size: f32::from(self.size),
            bounds,
            color: Color::BLACK,
            font: self.font.clone(),
            horizontal_alignment: alignment::Horizontal::Left,
            vertical_alignment: alignment::Vertical::Center,
        });
        bounds.y += height;
        renderer.fill_text(text::Text {
            content: &self.state.data[1],
            size: f32::from(self.size),
            bounds,
            color: Color::BLACK,
            font: self.font.clone(),
            horizontal_alignment: alignment::Horizontal::Left,
            vertical_alignment: alignment::Vertical::Center,
        });
    }
}

impl<'a, Message, Renderer> From<Hexdump<'a, Renderer>> for Element<'a, Message, Renderer>
where
    Renderer: 'a + renderer::Renderer + text::Renderer,
{
    fn from(val: Hexdump<'a, Renderer>) -> Self {
        Element::new(val)
    }
}
