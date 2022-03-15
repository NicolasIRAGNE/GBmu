extern crate bindgen;
extern crate cmake;

use cmake::Config;
use std::env;
use std::path::PathBuf;

fn main() {
    // Tell cargo to invalidate the built crate whenever the wrapper changes
    println!("cargo:rerun-if-changed=../../includes/lib.h");
    println!("cargo:rerun-if-changed=../../srcs");
    println!("current dir: {:?}", env::current_dir());

    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
        // The input header we would like to generate
        // bindings for.
        .header("../../includes/lib.h")
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        // use cty to prefix c types
        .ctypes_prefix("cty")
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");

    // Build libgb.a
    let dst = Config::new("../../")
        .define("BUILD_GBCLODO", "OFF")
        .define("WITH_ASAN", "OFF")
        .define("CMAKE_EXPORT_COMPILE_COMMANDS", "ON")
        .define("CMAKE_INSTALL_PREFIX", "../../")
        .build_target("install")
        .build();

    // Search lib in the correct folder, build
    println!("cargo:rustc-link-search=native={}/../../bin", dst.display());

    // Finally link the cmake build library
    // println!("cargo:rustc-link-lib=asan");
    println!("cargo:rustc-link-lib=static=gb");

    println!("{}", out_path.display());
}
