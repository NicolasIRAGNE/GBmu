mod system;
mod emulator;

use std::fs;
use std::path::PathBuf;
use std::process;

use log::*;
use anyhow::{Context, Ok, Result};
use structopt::StructOpt;
use structopt::clap::AppSettings::*;

use system::System;
use bindings::gb::*;

#[derive(Debug, StructOpt)]
#[structopt(setting(ColorAuto), setting(ColoredHelp))]
#[structopt(author, about)]
struct Opt {
    /// A file containing a ROM to load into the emulator.
    #[structopt(long, short, parse(from_os_str))]
    rom: PathBuf,

    /// A file containing a binary dump of the Game Boy BIOS.
    ///
    /// If not supplied, the emulator will begin executing the ROM as if the BIOS had succeeded.
    #[structopt(long)]
    bios: Option<PathBuf>,

    /// Enable debug mode.
    #[structopt(short, long)]
    debug: bool,
}

fn run(opt: Opt) -> Result<()> {
    //let mut builder = Emulator::builder();

    //let mut emulator = builder.build();

    if let Some(bios) = &opt.bios {
        info!("loading BIOS from file '{}'", bios.display());
        let bios = fs::read(&bios).context("could not read BIOS")?;
        //emulator.load_bios(&bios).context("could not load BIOS")?;
    }

    info!("loading ROM from file '{}'", opt.rom.display());
    let rom = opt.rom.into_os_string().into_string().unwrap();
    //emulator.load_rom(&rom).context("could not load ROM")?;

    System::init(rom)?;
    System::run();
    Ok(())
}

fn main() {
    pretty_env_logger::init();
    let opt = Opt::from_args();

    if let Err(e) = run(opt) {
        eprintln!("fatal error: {:?}", e);

        // if let Some(pixels::Error::AdapterNotFound) = e.downcast_ref() {
        //     eprintln!("help: ensure your graphics adapter supports Vulkan");
        // }

        process::exit(1);
    }
}
