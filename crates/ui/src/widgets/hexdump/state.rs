use super::super::Text;

use crate::debugger::memory::MemoryMsg;
use ascii::{AsciiChar, AsciiString, ToAsciiChar};
use iced::{Column, Row};

const TEXT_SIZE: u16 = 20;

pub struct State {
    name: String,
    pub data: Vec<String>,
    header: Header,
    offset: u32
}

struct Header {
    address: String,
    bytes: String,
    ascii: String,
}

impl Header {
    pub fn new() -> Self {
        let address = " ".repeat(8);
        let bytes = " ".to_string() + &"FF ".repeat(16);
        let ascii = "0123456789ABCDEF".to_string();
        Self {
            address,
            bytes,
            ascii,
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

impl State {
    pub fn new(name: String, data: &[u8]) -> Self {
        let header = Header::new();
        let data = Self::generate(data);
        Self { name, data, header, offset: 0 }
    }

    pub fn title(&self) -> iced_wgpu::Text {
        Text::new(self.name.clone()).bold(10)
    }

    fn generate(data: &[u8]) -> Vec<String> {
        let mut hexdump = Vec::new();

        for (i, line) in data.chunks(16).enumerate() {
            let mut byte_str = " ".to_string();
            let mut ascii_str: AsciiString = AsciiString::with_capacity(16);
            for data in line {
                byte_str.push_str(&format! {"{:02X} ", data});
                match data.to_ascii_char() {
                    Ok(char) if char.is_ascii_printable() => ascii_str.push(char),
                    _ => ascii_str.push(AsciiChar::Dot),
                }
            }
            let row = format!("{:#08X}", i * 0x10) + &byte_str + &ascii_str.to_string();
            hexdump.push(row);
        }
        hexdump
    }

    pub fn _name(&self) -> String {
        self.name.clone()
    }

    pub fn render(&mut self) -> Column<MemoryMsg> {
        Column::new().push(self.header.view())
    }
}
