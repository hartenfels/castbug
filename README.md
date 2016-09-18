# Castbug

This repository demonstrates a cast handler bug in PHP for <https://bugs.php.net/bug.php?id=73108>.

The interesting bit is the function `castbug_cast` in [castbug.c](castbug.c).
The test can be found in [tests/castbug.phpt](tests/castbug.phpt).

Build and test via:

    phpize
    ./configure
    make
    make test
