# CPP Module 01 — Study Plan

6 sessions of 45-60 minutes each. Goal: understand and build every exercise independently.

Method: each session starts from what you already know in C, bridges to C++ through questions, and has you write code that proves understanding — not reproduce patterns. No full solutions shown before you try.

---

## Session 1 — C++ is just C with extras
**Status:** [x] DONE
**Goal:** Understand HOW and WHY C++ changes what you already know in C.

### Part A: Output and strings (~15 min)
Starting point — you already know `printf` and `char *`. Now explore:
1. Write a C-style "hello world" program but using `#include <iostream>` and `std::cout` instead of printf. Look up `std::cout` on cplusplus.com if stuck.
2. Once that works: create a `std::string` variable and print it. Try concatenating two strings with `+`. Try getting its length. Compare mentally to how you'd do it with `char *` in C.
3. **Check yourself:** What happens if you use `<string.h>` instead of `<string>`? Why?

### Part B: Structs to classes (~20 min)
Starting point — you know C structs. A class is a struct that can also have functions and access control.
1. Write a struct in C style with a `name` field. Then turn it into a `class` with `private:` and `public:` sections. What breaks? Why?
2. Add a function inside the class that prints the name. This is a "member function." How do you call it?
3. **Check yourself:** What does `private` actually prevent? Try accessing a private member from main — read the error message carefully.

### Part C: Constructors and destructors (~20 min)
Starting point — in C, you initialize structs manually. C++ automates this.
1. Add a constructor to your class — a function with the same name as the class. Make it print something. When does it run?
2. Add a destructor (`~ClassName`). Make it print something. When does it run? Create an object inside `{ }` braces and watch what happens.
3. Split your class into a `.hpp` and `.cpp` file. Use `#ifndef` include guards. Make a Makefile that compiles it.
4. **Check yourself:** If you create 3 objects in a row, in what order are the destructors called? Try it.

---

## Session 2 — Ex00: Where does your object live? (stack vs heap)
**Status:** [x] DONE
**Goal:** Understand stack vs heap allocation and WHEN to use each.

### Part A: Explore the difference (~15 min)
Starting point — you know `malloc`/`free` in C. C++ replaces them with `new`/`delete`.
1. Create an object normally (stack): `Zombie z("Alice");` — when is it destroyed?
2. Create one on the heap: `Zombie *z = new Zombie("Bob");` — when is it destroyed? What happens if you never call `delete`?
3. Create an object inside a function and return it. What goes wrong with stack? What works with heap?
4. **Check yourself:** If a function needs to create an object that the CALLER will use later, should it use stack or heap? Why?

### Part B: Code ex00 (~30 min)
Now build it: Zombie class with `announce()`, `newZombie()` (heap), `randomChump()` (stack), and a main that proves you understand the difference.

**Before coding:** answer to yourself: why does `newZombie` return a pointer but `randomChump` returns void?

---

## Session 3 — Ex01 + Ex02: Arrays and references
**Status:** [~] In progress (ex01 DONE, ex02 not started)
**Goal:** Allocate object arrays, understand what a reference is.

### Part A: Array allocation (~10 min)
1. In C you'd do `malloc(sizeof(Zombie) * N)`. In C++ it's `new Zombie[N]`. What's `delete[]` and why is it different from `delete`?
2. Problem: `new Zombie[N]` calls the default constructor (no arguments). What does your Zombie class need for this to work?

### Part B: What is a reference? (~15 min)
1. Create a string. Create a pointer to it AND a reference to it. Print the address of all three. What do you notice?
2. Try to make a reference point to something else after creation. What happens?
3. Try to create a reference without initializing it. What happens?
4. **Check yourself:** A reference is like a pointer that _______ and _______ (two key restrictions).

### Part C: Code ex01 + ex02 (~30 min)
- ex01: `zombieHorde(int N, std::string name)` — allocates N zombies in one `new[]`
- ex02: Print addresses and values of a string, a pointer, and a reference

---

## Session 4 — Ex03: References vs pointers as class members
**Status:** [ ] Not started
**Goal:** Know WHEN to use a reference vs pointer inside a class.

### Part A: Experiment (~15 min)
1. Make a class that has a reference member. Try to compile without initializing it in the constructor. Read the error.
2. Make a class that has a pointer member. Set it to NULL. Is that valid? Now try that with a reference.
3. **Check yourself:** When MUST you use a pointer instead of a reference as a class member? (Think: what if the object doesn't always have one?)

### Part B: Code ex03 (~30 min)
Build Weapon, HumanA (always armed → reference), HumanB (maybe armed → pointer). Test with the subject's main().

**Before coding:** why does HumanA take the Weapon in its constructor but HumanB doesn't?

---

## Session 5 — Ex04: File I/O and string operations
**Status:** [ ] Not started
**Goal:** Read/write files in C++ and manipulate strings.

### Part A: File I/O basics (~10 min)
1. In C you use `fopen`/`fclose`. In C++ you use `std::ifstream`/`std::ofstream` from `<fstream>`. Open a file, read its content into a `std::string`, print it.
2. Write a string to a new file. Verify it worked.
3. **Check yourself:** What happens if the file doesn't exist when you try to open it for reading? How do you check?

### Part B: String manipulation (~10 min)
1. Look up `std::string::find()` and `std::string::substr()` on cplusplus.com.
2. Write a small test: find the position of a word in a string, extract everything before it, everything after it, and rebuild the string with a replacement. This is your replace algorithm.
3. What should happen if s1 appears multiple times? What if s1 is empty?

### Part C: Code ex04 (~25 min)
Build the mini-sed. Remember: `std::string::replace` is forbidden.

---

## Session 6 — Ex05 + Ex06: Pointers to member functions & switch
**Status:** [ ] Not started
**Goal:** Use function pointers inside a class, and the switch statement.

### Part A: Member function pointers (~15 min)
1. In C, you know function pointers: `void (*fn)(void) = &myFunc;`. In C++, pointers to MEMBER functions have a different syntax. Look it up.
2. Try storing 4 member function pointers in an array. Call one through the array.
3. **Check yourself:** Why can't you use regular function pointers for member functions? (Hint: what hidden parameter do member functions have?)

### Part B: Switch with fall-through (~10 min)
1. You know switch from C. What happens when you DON'T use `break`? This is called fall-through.
2. Think about: if the user says "WARNING", you want to print WARNING + ERROR. How does fall-through help?

### Part C: Code ex05 + ex06 (~30 min)
- ex05: Harl with `complain()` using an array of member function pointers
- ex06: harlFilter using switch with fall-through

---

## Progress notes

(Add notes here as you complete sessions — what clicked, what was hard, etc.)
