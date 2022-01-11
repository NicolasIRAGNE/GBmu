use super::{CpuMsg, View};
use enum_iterator::IntoEnumIterator;
use bindings::cpu::{self, Bus};
use iced::{Alignment, Column, Element, Row};
use itertools::Itertools;

use crate::{
    widgets::{Flag, Text},
    style::Theme,
};

#[derive(Default)]
pub struct Flags {
    flags: Vec<cpu::registers::Flag>,
}

impl Flags {
    pub fn new() -> Self {
        let mut flags = Vec::new();
        for flag in cpu::Flag::into_enum_iter() {
            flags.push(flag);
        }
        Self { flags }
    }

    pub fn view(&self, registers: &cpu::Registers, theme: Theme) -> Element<CpuMsg> {
        let title = Text::new("Flags").medium_it(20);
        let mut column = Column::new().push(title).align_items(Alignment::Center);
        for (left, right) in self.flags.iter().tuples() {
            let mut row = Row::new().spacing(15);
            row = row.push(left.view(registers, theme));
            row = row.push(right.view(registers, theme));
            column = column.push(row);
        }
        column.into()
    }
}

impl View<CpuMsg> for cpu::Flag {
    fn get_data(&self, registers: &cpu::Registers) -> String {
        format!("{}", registers.get(*self))
    }

    fn get_name(&self) -> String {
        format!("{:?}", *self)
    }

    fn view(&self, registers: &cpu::Registers, theme: Theme) -> Element<CpuMsg> {
        let builder = Flag::new(20, 1, 5, theme);
        builder
            .render(self.get_name(), self.get_data(registers), registers.get(*self))
            .into()
    }
}
