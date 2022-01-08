use std::{thread, time::{Duration, Instant}};
use std::ffi::CString;

use shared::{error::Result, GbmuError};

use crate::bindings::{cpu_step, destroy_gb, init_gb, m_TextureData};

pub enum Frame {
    Processing,
    Ready,
}

pub fn init(rom: String) -> Result<()> {
    let rom = CString::new(rom).expect("Cstring allocation failed");

    unsafe {
        if init_gb(rom.as_ptr()) != 0 {
            Err(GbmuError::RomLoad)
        } else {
            println!("Cpu Init succeeded");
            Ok(())
        }
    }
}

pub fn step() -> Result<Frame> {
    unsafe {
        match cpu_step() {
            1 => Ok(Frame::Ready),
            0 => Ok(Frame::Processing),
            _ => Err(GbmuError::CpuStep),
        }
    }
}

pub fn render(frame: &mut [u8]) {
    for (i, pixel) in frame.chunks_exact_mut(4).enumerate() {
        let x = i % 144;
        let y = i / 144;

        let mut data = unsafe {
            let data = m_TextureData[y][x];
            data.to_le_bytes()
        };
        data[3] = 0xFF;
        pixel.copy_from_slice(&data);
    }
}

pub fn cleanup() {
    unsafe {
        destroy_gb()
    }
}

pub fn frame() -> bool {
    let start_time = Instant::now();
    let frame_time = Duration::new(0, 16600000); // 16.6 ms as nanoseconds

    loop {
        match step() {
            Ok(Frame::Processing) => (),
            Ok(Frame::Ready) => break,
            Err(_) => return false,
        }
    }

    let elapsed_time = start_time.elapsed();
    if elapsed_time < frame_time {
        let remaining_time = frame_time - elapsed_time;
        thread::sleep(remaining_time);
    }
    true
}
