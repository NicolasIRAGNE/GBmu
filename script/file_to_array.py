#!/usr/bin/env python3
################################################################################
# File: file_to_array.py
# Created Date: Thu Dec 30 2021
# Author: Nicolas IRAGNE (nicolas.iragne@alyce.fr)
# -----
# Convert an arbitrary file to a C compatible array.
# -----
################################################################################

import sys
import argparse
from pathlib import Path

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file', help='File to convert', required=True)
    parser.add_argument('-o', '--output', help='Output file', required=False)
    parser.add_argument('-n', help='Number of bytes to convert', type=int, required=False)
    args = parser.parse_args()

    if args.output is None:
        args.output = args.file + '.h'

    with open(args.file, 'rb') as f:
        data = f.read()

    filename = Path(args.file).stem
    with open(args.output, 'w') as f:
        f.write("#pragma once\n\n")
        f.write("#include <stdint.h>\n\n")
        f.write("const uint8_t " + filename + "[] =\n {\n")
        if (args.n is not None):
            bytes_to_convert = min(len(data), args.n)
        else:
            bytes_to_convert = len(data)
        for i in range(0, bytes_to_convert):
            if (i % 16 == 0):
                f.write("    ")
            f.write("0x{:02x}, ".format(data[i]))
            if (i+1) % 16 == 0 or i+1 == bytes_to_convert:
                f.write("\n")
        f.write("};\n\n")
        f.write("const size_t {}_size = 0x{:x};".format(filename, bytes_to_convert))

    print('File converted to array.')
    print('Output file: ' + args.output)
    print('Done.')
