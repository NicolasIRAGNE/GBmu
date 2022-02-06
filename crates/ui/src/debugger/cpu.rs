mod registers;
mod flags;

use enum_iterator::IntoEnumIterator;
use iced::{Alignment, Column, Element};
use itertools::Itertools;
use bindings::cpu::{self, Bits16, Bits8};

use registers::Registers;
use flags::Flags;

use crate::{style::theme::Theme, widgets::Text};

pub trait View<T> {
    fn get_data(&self, registers: &cpu::Registers) -> String;
    fn get_name(&self) -> String;

    fn view(&self, registers: &cpu::Registers, theme: Theme) -> Element<T>;
}

#[derive(Debug, Clone)]
pub enum CpuMsg {
    Merge(usize),
    Refresh,
}

#[derive(Default)]
pub struct Cpu {
    data: cpu::Registers,
    registers: Vec<Registers>,
    flags: Flags,
}

impl Cpu {
    pub fn new() -> Self {
        let data = cpu::Registers::default();
        let mut registers = Vec::new();
        Bits8::into_enum_iter().into_iter().tuples().for_each(|(left, right)| {
            if left == Bits8::H {
                registers.push(Registers::Merged(Bits16::HL));
            } else {
                registers.push(Registers::Splited(left, right));
            }
        });
        registers.push(Registers::NoSplit(Bits16::SP));
        registers.push(Registers::NoSplit(Bits16::PC));
        let flags = Flags::new();
        Self {
            data,
            registers,
            flags
        }
    }

    pub fn refresh(&mut self) {
        self.data.refresh();
    }

    pub fn update(&mut self, message: CpuMsg) {
        match message {
            CpuMsg::Merge(index) => {
                let ui = self.registers.remove(index);
                self.registers.insert(index, ui.swap());
            }
            CpuMsg::Refresh => (),
        }
    }

    pub fn view(&mut self, theme: Theme) -> Element<CpuMsg> {
        let title = Text::new("Cpu").medium_it(20);
        let cpu = Column::new().push(title).align_items(Alignment::Center);
        let registers = self.registers.iter().enumerate().fold(
            Column::new().padding(15).spacing(5),
            |column, (index, ui)| {
                let element = ui.view(&self.data, theme);
                column.push(element.map(move |_message| CpuMsg::Merge(index)))
            },
        );
        let flags = self.flags.view(&self.data, theme);
        cpu.push(registers).push(flags).into()
    }
}
