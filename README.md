# Castbug

This repository demonstrates a cast handler bug in PHP.

The interesting bit is the function `castbug_cast` in [castbug.c](castbug.c).
The test can be found in [tests/castbug.phpt](tests/castbug.phpt).

Build and test via:

    phpize
    ./configure
    make
    make test
