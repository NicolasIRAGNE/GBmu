
use super::MemoryMsg;
use crate::widgets::hexdump::Hexdump;
use crate::style::Theme;
use iced::{Column, Text};

pub trait View {
    fn title(&self) -> Text;

    fn view(&mut self, theme: Theme) -> Column<MemoryMsg> {
        Column::new()
            .spacing(20)
            .push(self.title())
            .push(self.content(theme))

        // Container::new(column)
        //     .width(Length::Fill)
        //     .height(Length::Fill)
        //     .align_x(Horizontal::Center)
        //     .align_y(Vertical::Center)
        //    .padding(TAB_PADDING)
    }

    fn content(&mut self, theme: Theme) -> Column<MemoryMsg>;
}

impl View for Hexdump {
    fn content(&mut self, _theme: crate::style::Theme) -> Column<MemoryMsg> {
        self.render()
    }

    fn title(&self) -> Text {
        self.title()
    }
}
