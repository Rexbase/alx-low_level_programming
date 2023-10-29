
# 0x1C. C - Makefiles

## Description

This repository contains examples and exercises for understanding and working with Makefiles in C programming.

A Makefile is a build automation tool that manages dependencies and facilitates the building of complex projects. It is commonly used for compiling and linking C programs efficiently.

## Learning Objectives

- What are Makefiles and how to use them
- What are the rules and how to set and use them
- What are explicit and implicit rules
- What are the most common / useful rules
- What are variables and how to set and use them

## Files

- `0-Makefile`: A simple Makefile to compile a C program.
- `1-Makefile`: A Makefile to compile a C program with additional flags and to specify the output file.
- `2-Makefile`: A Makefile with variables for the compiler and flags.
- `3-Makefile`: A Makefile with rules for building an object file from multiple source files.
- `4-Makefile`: A Makefile with additional rules for building object files.
- `5-island_perimeter.py`: A Python script for calculating the perimeter of an island in a grid.
- `100-Makefile`: A more advanced Makefile to manage the build process.
- `README.md`: This file.

## Requirements

- A working knowledge of C programming.
- A Unix-based operating system (Linux or macOS) to run Makefiles.

## Usage

To compile the C programs, navigate to the respective exercise directory and use the `make` command. For example:

```bash
$ cd 0-Makefile
$ make
```

To clean up the generated files, you can use the `clean` target:

```bash
$ make clean
```

## Acknowledgements

This project is part of the [Holberton School] curriculum
