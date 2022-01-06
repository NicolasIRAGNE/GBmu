mod system;
mod emulator;

use std::path::PathBuf;
use std::process;

use log::*;
use anyhow::{Ok, Result};
use structopt::StructOpt;
use structopt::clap::AppSettings::*;

use system::System;

#[derive(Debug, StructOpt)]
#[structopt(setting(ColorAuto), setting(ColoredHelp))]
#[structopt(author, about)]
struct Opt {
    /// A file containing a ROM to load into the emulator.
    #[structopt(long, short, parse(from_os_str))]
    rom: PathBuf,

}

fn run(opt: Opt) -> Result<()> {
    //let mut builder = Emulator::builder();

    //let mut emulator = builder.build();


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
