# GBmu

GBmu is an experimental Game Boy emulator built from the C/C++ code in
this repository.

## Dependencies

- CMake 3.28 or newer
- A C11/C++17 compiler
- OpenGL
- GNU Readline on Linux and macOS

CMake downloads SDL2, GLEW, cxxopts, and the Windows EditLine implementation
when they are needed.

## Build and install

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cmake --install build --config Release --component gbmu
```

Set `CMAKE_INSTALL_PREFIX` during configuration to choose the install location:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=dist
```

## Usage

```sh
gbmu path/to/game.gb
```

Pass `-DWITH_TESTS=ON` to build the tests and run them with:

```sh
ctest --test-dir build --output-on-failure
```

The optional libyacc debugger can be enabled with `-DWITH_LIBYACC=ON`. The
fallback debugger is used by default because libyacc is less stable on some
architectures.
