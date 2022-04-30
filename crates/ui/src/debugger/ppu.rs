mod register;

use iced::{Alignment, Column, Element};
use enum_iterator::IntoEnumIterator;

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
        let registers = self.registers.iter().fold(
            Column::new().padding(15).spacing(5),
            |column, ui| {
                let element = ui.view(&self.data, theme);
                column.push(element)
            });

        ppu.push(registers).into()
    }
}
