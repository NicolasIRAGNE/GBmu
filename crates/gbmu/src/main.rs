mod system;
mod emulator;
mod debugger;

use std::path::PathBuf;
use std::process;
use std::env;

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
    #[structopt(long, short, parse(from_os_str), default_value = "")]
    rom: PathBuf,

    #[structopt(short, long, default_value = "auto")]
    mode: String,
}

fn run(opt: Opt) -> Result<()> {
    info!("loading ROM from file '{}'", opt.rom.display());
    let rom = opt.rom.into_os_string().into_string().unwrap();
    let mode = opt.mode;

    let system = System::try_new(rom, mode)?;
    system.run();
    Ok(())
}

fn main() {
    env::set_var("WGPU_BACKEND", "Gl");
    pretty_env_logger::init();
    let opt = Opt::from_args();

    if let Err(e) = run(opt) {
        eprintln!("fatal error: {:?}", e);
        process::exit(1);
    }
}
