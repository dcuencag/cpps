# CPP Module 02 — Study Plan

4 sessions of 45-60 minutes each. Goal: understand ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form through a fixed-point number class.

Method: each session starts from what you already know in C and previous modules, bridges to C++ through questions, and has you write code that proves understanding — not reproduce patterns. No full solutions shown before you try.

---

## Session 1 — Ex00: Orthodox Canonical Form + fixed-point numbers
**Status:** [ ]
**Goal:** Understand WHY the OCF exists and WHAT fixed-point numbers are.

### Part A: The Orthodox Canonical Form (~20 min)
Starting point — in CPP01 you wrote classes with constructors and destructors. Now there are two new mandatory members.

1. Create a simple class with an `int` member. Now write this in main:
   ```cpp
   MyClass a;
   a.setValue(42);
   MyClass b = a;   // What constructor runs here?
   MyClass c;
   c = a;           // What function runs here?
   ```
   Compile and check: did `b` and `c` get the value 42? The compiler generated a **copy constructor** and a **copy assignment operator** for you automatically.
2. Now change your `int` member to an `int *` that you allocate with `new` in the constructor and `delete` in the destructor. Repeat the test above. What happens when the program ends? (Hint: think about what gets copied — the pointer or the data?)
3. **Check yourself:** Why does the compiler-generated copy NOT work with pointers? What's a "shallow copy" vs a "deep copy"? This is WHY the OCF requires you to write these four functions explicitly.

### Part B: What is a fixed-point number? (~15 min)
Starting point — you know `int` (exact, limited range) and `float` (approximate, large range).

1. Imagine you have an `int` that stores cents instead of euros. You know `150` means `1.50€`. You're already doing fixed-point! How would you convert `150` cents to a float in euros? How would you convert `3.75€` to cents?
2. Now generalize: instead of 2 decimal digits, imagine 8 binary digits. If you have an `int` value and the last 8 bits are the "fractional part", how do you convert to float? (Hint: divide by 2^8 = 256). How do you store a float as fixed-point? (Hint: multiply by 256 and round).
3. **Check yourself:** Why would someone use fixed-point instead of float? (Think about: embedded systems, consistent precision, no floating-point hardware)

### Part C: Code ex00 (~20 min)
Build the basic `Fixed` class: just an `int` value, a `static const int` for fractional bits (8), getRawBits, setRawBits, and all four OCF functions. Each one prints a trace message.

**Before coding:** The subject shows expected output with specific constructor/destructor messages. Look at `Fixed c; c = b;` — how many constructors and operators run? What about `Fixed b(a);`? Make sure you understand the difference before writing code.

---

## Session 2 — Ex01: Conversions and your first operator overload
**Status:** [ ]
**Goal:** Understand implicit/explicit type conversion and overloading `<<`.

### Part A: Conversion constructors (~15 min)
Starting point — in ex00 your Fixed class can only hold 0. Time to make it useful.

1. You already figured out the math in Session 1 Part B. Now think about it in code: if someone writes `Fixed a(42);`, what do you store internally? And `Fixed b(3.14f);`?
2. Think about `roundf`: when you do `3.14 * 256 = 803.84`, you need to round to the nearest integer. Why? What happens if you just cast to int? Try both and compare.
3. **Check yourself:** Your int constructor does `value = n << 8`. Your float constructor does `value = roundf(n * 256)`. Why is bit-shifting equivalent to multiplying by 256? From your C experience with bitwise operators — what does `<< 1` do to a number?

### Part B: Overloading `<<` (~15 min)
Starting point — in CPP00/CPP01 you used `std::cout << myString`. Now you'll make YOUR class work with `<<`.

1. When you write `std::cout << a`, the compiler looks for `operator<<(std::ostream&, const Fixed&)`. This is a **free function**, not a member function. Why can't it be a member of Fixed? (Hint: who is on the LEFT side of `<<`?)
2. This function needs to access `toFloat()` from your class. Since `toFloat()` is public, no problem. But what if it needed private access? That's when you'd use `friend` — which is forbidden in this module. Keep it public.
3. **Check yourself:** What does this function return and why? (Hint: what happens when you chain `cout << a << b`?)

### Part C: Code ex01 (~25 min)
Add the int constructor, float constructor, `toFloat()`, `toInt()`, and `operator<<`. Test with the subject's main.

**Before coding:** `toFloat` divides by 256.0, `toInt` shifts right by 8. Why does `toFloat` use `256.0` (float division) but `toInt` uses `>> 8` (bit shift)? What would go wrong if `toInt` divided by 256.0 and cast to int?

---

## Session 3 — Ex02: Full operator overloading
**Status:** [ ]
**Goal:** Understand ad-hoc polymorphism through operator overloading — comparison, arithmetic, and increment/decrement.

### Part A: Comparison operators (~10 min)
1. You need 6 comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`. Each takes a `const Fixed&` and returns `bool`. Since your fixed-point values are just ints internally, how do you compare them? Do you need to convert to float?
2. Think about it: if `a._value > b._value`, is `a > b` always true? Why? (Hint: the fractional bits count is the same for both)
3. **Check yourself:** Why should the parameter be `const Fixed&` and not `Fixed`? Two reasons — one is about copies, one is about promises.

### Part B: Arithmetic operators (~15 min)
1. Addition and subtraction with fixed-point: if both numbers use the same number of fractional bits, can you just add the raw values? Try on paper: `1.5 + 2.25` in fixed-point with 8 bits. `1.5 = 384`, `2.25 = 576`, `384 + 576 = 960`. What's `960 / 256`?
2. Multiplication is trickier. If you multiply two fixed-point raw values, you get DOUBLE the fractional bits (8 + 8 = 16). So you need to shift right by 8 after multiplying. Try on paper: `1.5 * 2 = ?`. `384 * 512 = 196608`. `196608 >> 8 = 768`. `768 / 256 = 3.0`. Correct!
3. Division: similar logic but opposite — you shift left BEFORE dividing to keep precision.
4. **Check yourself:** Why can't you just multiply two raw values and return the result directly? What goes wrong with the fractional bits?

### Part C: Increment/decrement + min/max + code ex02 (~30 min)
1. Pre-increment (`++a`) vs post-increment (`a++`): the difference is about WHEN the value changes relative to WHAT gets returned. In C you know `int a = 5; int b = a++;` gives `b=5, a=6`. Same idea but: how does C++ distinguish the two function signatures? (Hint: look up the dummy `int` parameter)
2. The increment value is ε such that `1 + ε > 1`. With 8 fractional bits, what's the smallest value that's "just above zero"? (It's 1 in raw value — what does `1/256` equal as a float?)
3. `min` and `max` are **static** member functions — you call them as `Fixed::min(a, b)`. You need both const and non-const versions. Why? (Think: what if someone passes two `const Fixed` objects?)

**Before coding:** You have ~20 functions to write. Before you start, sketch which ones are trivial (comparisons — all similar), which need math (arithmetic), and which have a trick (post-increment). Don't code them all at once — test each group.

---

## Session 4 — Ex03 (bonus): BSP — using your Fixed class
**Status:** [ ]
**Goal:** Build a Point class and implement a geometric algorithm using your Fixed class.

### Part A: The Point class (~10 min)
1. Point has two `Fixed const` attributes: x and y. The `const` here is key — what does it mean for your copy assignment operator? Can you actually assign one Point to another? Think about what happens and how to handle this in OCF.
2. The constructor takes two `const float` parameters. This will use your Fixed(float) constructor from ex01 — it's already done, you just use it.
3. **Check yourself:** How do you initialize `const` members in a constructor? You can't do `this->x = val;` because it's const. Look up "member initializer list" — you already have the syntax from how you handle references in CPP01.

### Part B: The BSP algorithm (~15 min)
1. To check if a point P is inside triangle ABC, you can use the cross-product method. For each edge of the triangle (AB, BC, CA), compute the cross product with the vector to P. If all three have the same sign → P is inside.
2. The cross product of vectors (x1,y1) and (x2,y2) in 2D is: `x1*y2 - y1*x2`. This gives a scalar that tells you which "side" of the line a point is on.
3. The subject says: point on edge or vertex → return false. How does the cross product help you detect this? (Hint: what value does the cross product give when points are collinear?)
4. **Check yourself:** Why does this algorithm work? Draw a triangle on paper, pick a point inside and outside, and compute the three cross products manually.

### Part C: Code ex03 (~30 min)
Implement Point class (OCF + float constructor) and `bsp()` function. Write your own test main with several cases: inside, outside, on edge, on vertex.

**Before coding:** The `bsp()` function takes Points by value (`Point const a`, not reference). This means copies are made. Does your Point class handle copies correctly with its const members?

---

## Progress notes

(Add notes here as you complete sessions — what clicked, what was hard, etc.)
