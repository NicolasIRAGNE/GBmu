mod register;

use iced::{Alignment, Column, Element, Row};
use enum_iterator::IntoEnumIterator;
use itertools::Itertools;

use crate::{style::Theme, widgets::Text};
use bindings::ppu::{Registers, Data};

pub trait View {
    fn view(&self, registers: &Data, theme: Theme) -> Element<PpuMsg>;
}

pub struct Ppu {
    data: Data,
    registers: Vec<Registers>
}

#[derive(Debug, Clone)]
pub enum PpuMsg {
}

impl Ppu {
    pub fn new() -> Self {
        let data = Data::default();
        let mut registers = Vec::new();

        for register in Registers::into_enum_iter() {
            registers.push(register);
        }

        Self {
            data,
            registers
        }
    }

    pub fn refresh(&mut self) {
        for register in self.registers.iter() {
            self.data.refresh(*register)
        }
    }

    pub fn view(&mut self, theme: Theme) -> Element<PpuMsg> {
        let title = Text::new("Ppu").medium_it(20);
        let ppu = Column::new().push(title).align_items(Alignment::Center);
        let registers = self.registers.iter().tuples().fold(
            Column::new().padding(15).spacing(5),
            |column, (right, left)| {
                let l = left.view(&self.data, theme);
                let r = right.view(&self.data, theme);
                column.push(Row::new().push(l).push(r))
            });

        ppu.push(registers).into()
    }
}
