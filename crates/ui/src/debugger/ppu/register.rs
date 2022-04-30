use bindings::ppu::{Registers, Data};
use super::View;
use crate::style::fonts;
use iced::{Alignment, Container, Length, Row, Space, Text, alignment::{Horizontal, Vertical}};

impl View for Registers{
    fn view(&self, registers: &Data, _theme: crate::style::Theme) -> iced::Element<super::PpuMsg> {
        let name = Text::new(self.get_name()).font(fonts::HASKLIG_BOLD).size(20);
        let space = Space::new(Length::Units(10), Length::Units(5));
        let data = Text::new(self.get_data(registers))
            .font(fonts::HASKLIG_LIGHT)
            .width(Length::Fill)
            .horizontal_alignment(Horizontal::Center)
            .vertical_alignment(Vertical::Center);
        let number = Container::new(data)
            .align_x(Horizontal::Center)
            .align_y(Vertical::Center)
            .width(Length::Units(140))
            .height(Length::Units(25));
        Row::new()
            .push(name)
            .push(space)
            .push(number)
            .align_items(Alignment::Center)
            .into()
    }
}
