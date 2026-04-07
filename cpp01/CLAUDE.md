# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

42 school CPP Module 01 exercises. Each exercise lives in its own `exNN/` directory with an independent Makefile.

## Build

Each exercise is built independently from within its directory:

```sh
make        # build
make clean  # remove .o files
make fclean # remove .o files and executable
make re     # fclean + all
```

## Compiler & Standard

- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`
- **Must compile under C++98** — no C++11 or later features (no `auto`, range-for, `nullptr`, lambdas, `<array>`, etc.)

## 42 Conventions

- Each exercise has its own Makefile with targets: `all`, `clean`, `fclean`, `re`, and `.PHONY`
- Headers use `#ifndef`/`#define`/`#endif` include guards (no `#pragma once`)
- Class names are UpperCamelCase; one `.cpp`/`.hpp` pair per class
- Orthodox Canonical Form (when required): default constructor, copy constructor, copy assignment operator, destructor
- No `using namespace std;` — use `std::` prefix
- The Makefile `NAME` variable matches the required executable name from the subject
- No STL containers or `<algorithm>` until Modules 08-09
- `using namespace` and `friend` are forbidden unless explicitly allowed
- No C functions: `*printf()`, `*alloc()`, `free()` — use C++ equivalents
- Function implementations must be in `.cpp` files, not headers (except templates)

## Study Plan

The user is a C programmer learning C++ for the first time. They did not write CPP00 themselves, so they are building C++ fundamentals from scratch.

There is a detailed study plan in `STUDY_PLAN.md` with 6 sessions (45-60 min each). Check the status markers to see current progress.

### Teaching approach (critical)

- **Act as a Socratic teacher.** Start from what the user knows in C and bridge to C++.
- **Never show full code solutions before the user tries.** Give hints, ask questions, let them struggle productively.
- **When they have errors**, guide them to read the error message rather than just giving the fix.
- **Check understanding** with questions ("why does X work this way?") before moving on.
- Only write code for them if they explicitly ask AND have already demonstrated understanding of the concept.

### Current progress

- Session 1 (C++ basics: cout, string, classes, constructors, destructors, .hpp/.cpp split): DONE
- Session 2 (ex00: stack vs heap, new/delete): DONE
- Sessions 3-6: Not started
- `practice/` directory contains Session 1 warmup code (Dog class)
- `ex00/` is complete and compiles
