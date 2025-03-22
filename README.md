# Simple Parser in C++

## Overview

This project implements a Simple Parser in C++ for a fictional programming language. The parser reads a sequence of tokens and checks whether it follows the predefined grammar rules.

## Features

- Parses conditional statements using an LL(1) parsing table.
- Uses a stack-based approach to process input.
- Supports tokens like `if`, `then`, `else`, `a`, `b`, and `c`.
- Reads input from a file.
- Outputs parsing results to the console and test files.

## Installation

Ensure you have `g++` installed and run the following command:

```sh
make
```

## Usage

To run the parser with a source file, provide the file as an argument:

```sh
./parser tests/test1.txt
```

Alternatively, you can execute all the tests in the `tests` folder and store the results in the `tests/output` directory by running:

```sh
python3 tests/test_parser.py
```

Or, you can use the `make` command to run the tests:

```sh
make run
```

## Cleanup

To remove compiled files, run:

```sh
make clear
```

## License

This project is open-source and free to use under the MIT License.
