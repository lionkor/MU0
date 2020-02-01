# `MU0`

A simple model emulator as preparation for a bigger project.
Open source, GPL-2.0

The `bitops.h` is part of this, although i didn't end up needing it at all. Tests in `tests` directory only test bitops. I'll probably pull that whole thing out into a seperate project, since it's basically deadweight here.


## How to build

1. Clone this repo recursively with `git clone [URL] --recursive`.

2. Run `cmake . && make MU0`.

This should compile the program into a binary called `MU0`.

## How to use

- You can run `./MU0` and it will load the `memory.bin` file (which you might fill however you like).

- You can run `./MU0 myfile.bin` to load `myfile.bin` and execute it.

There are examples supplied with the emulator, such as `multiply.bin` which will multiply 5x5.

