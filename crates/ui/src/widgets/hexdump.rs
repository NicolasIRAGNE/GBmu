use super::Text;
use crate::debugger::memory::MemoryMsg;
use ascii::{AsciiChar, AsciiString, ToAsciiChar};
use iced::{scrollable, Column, Length, Row, Scrollable};

const TEXT_SIZE: u16 = 20;

pub struct Hexdump<'a> {
    name: String,
    data: Scrollable<'a, MemoryMsg>,
    header: Header
}

struct Header {
    address: String,
    bytes: String,
    ascii: String
}

impl Header {
    pub fn new() -> Self {
        let address = " ".repeat(8);
        let bytes = " ".to_string() + &"FF ".repeat(16);
        let ascii = "0123456789ABCDEF".to_string();
        Self {
            address,
            bytes,
            ascii
        }
    }

    pub fn view(&self) -> Row<MemoryMsg> {
        let address = Text::new(&self.address).bold(TEXT_SIZE);
        let bytes = Text::new(&self.bytes).bold(TEXT_SIZE);

        // Ascii representation layout
        let ascii = Text::new(&self.ascii).bold(TEXT_SIZE);
        Row::new().push(address).push(bytes).push(ascii)
    }
}

impl<'a> Hexdump<'a> {
    pub fn new(name: String, data: &'static [u8], state: &'a mut scrollable::State) -> Self {
        let header = Header::new();
        let data = Self::generate(data, state);
        Self { name, data, header }
    }

    pub fn title(&self) -> iced_wgpu::Text {
        Text::new(self.name.clone()).bold(10)
    }

    fn generate(data: &'static [u8], state: &'a mut scrollable::State) -> Scrollable<'a, MemoryMsg> {
        let mut hexdump = Scrollable::new(state)
            .width(Length::Shrink)
            .height(Length::Shrink);

        for (i, line) in data.chunks(16).enumerate() {
            let mut byte_str = " ".to_string();
            let mut ascii_str: AsciiString = AsciiString::with_capacity(16);
            let mut row = Row::new();
            for data in line {
                byte_str.push_str(&format! {"{:02X} ", data});
                match data.to_ascii_char() {
                    Ok(char) if char.is_ascii_printable() => ascii_str.push(char),
                    _ => ascii_str.push(AsciiChar::Dot),
                }
            }
            row = row.push(Text::new(format!("{:#08X}", i * 0x10) + &byte_str + &ascii_str.to_string()).light(TEXT_SIZE));
            hexdump = hexdump.push(row);

        }
        hexdump
    }

    pub fn _name(&self) -> String {
        self.name.clone()
    }

    pub fn render(&mut self) -> Column<MemoryMsg> {
        Column::new().push(self.header.view()).push(&self.data)
    }

}
