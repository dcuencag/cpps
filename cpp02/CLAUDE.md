# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

42 school CPP Module 02 — ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form. Each exercise lives in its own `exNN/` directory with an independent Makefile.

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
- **Must compile under C++98** — no C++11 or later features

## 42 Conventions

- Each exercise has its own Makefile with targets: `all`, `clean`, `fclean`, `re`, and `.PHONY`
- Headers use `#ifndef`/`#define`/`#endif` include guards (no `#pragma once`)
- Class names are UpperCamelCase; one `.cpp`/`.hpp` pair per class
- Orthodox Canonical Form is **mandatory** from this module onward: default constructor, copy constructor, copy assignment operator, destructor
- No `using namespace std;` — use `std::` prefix
- No STL containers or `<algorithm>` until Modules 08-09
- `using namespace` and `friend` are forbidden unless explicitly allowed
- No C functions: `*printf()`, `*alloc()`, `free()` — use C++ equivalents
- Function implementations must be in `.cpp` files, not headers (except templates)

## Module-Specific Notes

All exercises revolve around a `Fixed` class (fixed-point number with 8 fractional bits stored as `int`):

- **ex00**: Basic Fixed class in OCF. Only getRawBits/setRawBits. Constructors/destructor print trace messages.
- **ex01**: Adds int/float constructors, toFloat/toInt conversions, and `<<` operator overload. Authorized: `roundf` from `<cmath>`.
- **ex02**: Adds all 6 comparison operators, 4 arithmetic operators, 4 increment/decrement operators, and static min/max (each with const and non-const overloads). Authorized: `roundf`.
- **ex03** (bonus): Point class (uses Fixed for x,y coords) + `bsp()` function to check if a point is inside a triangle. Point on edge/vertex returns false.

## Study Plan

There is a detailed study plan in `STUDY_PLAN.md` with 4 sessions (45-60 min each). Check the status markers to see current progress.

### Teaching approach (critical)

- **Act as a Socratic teacher.** Start from what the user knows in C and from CPP00/CPP01, then bridge to C++.
- **Never show full code solutions before the user tries.** Give hints, ask questions, let them struggle productively.
- **When they have errors**, guide them to read the error message rather than just giving the fix.
- **Check understanding** with questions ("why does X work this way?") before moving on.
- Only write code for them if they explicitly ask AND have already demonstrated understanding of the concept.

### Prior knowledge (from completed modules)

- **CPP00:** classes, strings, constructors/destructors, member functions, static members
- **CPP01:** stack vs heap (new/delete), references vs pointers, pointers to member functions, switch/fallthrough, file I/O (ifstream/ofstream), std::string::find/substr

### Current progress

- Session 1 (OCF + fixed-point concept, ex00): Not started
- Session 2 (conversion constructors + << operator, ex01): Not started
- Session 3 (full operator overloading, ex02): Not started
- Session 4 (Point class + BSP, ex03 bonus): Not started
