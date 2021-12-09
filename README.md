# GBmu

Trying to write a GameBoy emulator from scratch with no prior experience in electronics / emulation in general.
One of the dumbest ideas i've had so far.

### Dependencies.
Cmake version 3.13 minimum.

If you are building on `linux` or `macOs`: [GNU readline](https://tiswww.case.edu/php/chet/readline/rltop.html)

All other dependencies

### How to use
cd build && cmake .. && make install

usage: ./gbmu <rom_file>

### Debugger 
This program ships with [libyacc](https://github.com/ldedier/libyacc). However, it can cause crashes on some architectures, so it also includes a fallback, much more rudimentary debugger. Use the CMake variable `WITH_LIBYACC` to choose which one to include.

### Does it work ?
Not really. Maybe sometimes.

### Will it work one day ?
Maybe.
