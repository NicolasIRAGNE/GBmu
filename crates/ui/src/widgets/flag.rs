use std::fmt::Display;

use crate::style::Theme;

use super::Text;
use iced::Row;

pub struct Flag {
    text_size: u16,
    theme: Theme,
    name_width: usize,
    data_width: usize,
}

impl Flag {
    pub fn new(text_size: u16, name_width: usize, data_width: usize, theme: Theme) -> Self {
        Self {
            text_size,
            name_width,
            data_width,
            theme,
        }
    }

    pub fn render<'a, Message: 'a, Str, Data>(
        &self,
        name: Str,
        data: Data,
        status: bool,
    ) -> Row<'a, Message>
    where
        Str: Into<String> + Display,
        Data: Into<String> + Display,
    {
        let name = format!("{:<width$}: ", name, width = self.name_width);
        let name = Text::new(name).bold(self.text_size);
        let color = match status {
            true => self.theme.boolean(true),
            false => self.theme.boolean(false),
        };
        let data = format!("{:^width$}", data, width = self.data_width);
        let data = Text::new(data).light(self.text_size).color(color);
        Row::new().push(name).push(data)
    }
}
