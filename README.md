# GBmu

Trying to write a GameBoy emulator from scratch with no prior experience in electronics / emulation in general.
One of the dumbest ideas i've had so far.

`gbclodo` is now the default (and only) executable built by CMake; the previous Rust workspace has been removed in favor of the C/C++ renderer.

## Dependencies

- CMake 3.20+ (for presets)
- [Ninja](https://ninja-build.org/) or another CMake generator
- OpenGL development files
- If available, [GNU readline](https://tiswww.case.edu/php/chet/readline/rltop.html) on Linux/macOS (Windows uses WinEditLine)
- Optional but recommended for faster builds: SDL2 and GLEW development files

SDL2 and GLEW are fetched automatically via CMake when not present on the
system; installing the development packages locally simply skips the download
and speeds up the configure step. All other dependencies are handled
automatically. Windows builds use WinEditLine instead of readline.

## Building

The project ships with CMake presets for a predictable, cross-platform build.
Release build:

```
cmake --preset default
cmake --build --preset default
```

Debug build:

```
cmake --preset dev
cmake --build --preset dev
```

## Running

After building, the gbclodo executable lives under the preset directory (for
example `build/release`). Run it with a ROM file:

```
./build/release/gbclodo <rom_file>
```

## Debugger

This program ships with [libyacc](https://github.com/ldedier/libyacc). However, it can cause crashes on some architectures, so it
also includes a fallback, much more rudimentary debugger. Use the CMake variable `WITH_LIBYACC` to choose which one to include.

## Does it work?

Not really. Maybe sometimes.

## Will it work one day?

Maybe.
