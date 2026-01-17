# Lesson 03 - Variable Scope, Pass by Value, and C Types

**Video:** [Watch on YouTube](https://www.youtube.com/watch?v=YNsXyasn4R4&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=4)

---

## Overview

This lesson explores variable scope (local, global, static), how C passes arguments by value, and introduces the C type system including integers, floats, and overflow behavior.

---

## Side Effects

A **side effect** is when a function does something observable without returning a value:

```c
void inc(void) {
    int x = 1;
    x = x + 1;
    printf("X: %d\n", x);  // Side effect: prints to screen
}
```

This function returns `void` and takes `void` — it only has side effects.

### `=` vs `==`

- `=` → **Assignment** (sets a value)
- `==` → **Comparison** (checks equality)

---

## Variable Scope

### Local Variables

```c
void inc(void) {
    int x = 1;
    x = x + 1;
    printf("X: %d\n", x);
}

int main(void) {
    inc();  // prints 2
    inc();  // prints 2
    inc();  // prints 2
}
```

**Always prints 2.** `x` is created fresh each call, destroyed when the function returns.

### Global Variables

```c
int x = 0;  // Global — exists for entire program lifetime

void inc(void) {
    x = x + 1;
    printf("X: %d\n", x);
}

int main(void) {
    inc();  // prints 1
    inc();  // prints 2
    inc();  // prints 3
}
```

**Scope resolution:** Compiler first looks locally, then globally.

### Static Variables

```c
void inc(void) {
    static int x = 0;  // Initialized once, persists between calls
    x = x + 1;
    printf("X: %d\n", x);
}
```

`static` inside a function = **global lifetime** + **local visibility**.

```
┌─────────────────────────────────────────────────────────┐
│                  VARIABLE TYPES                         │
├─────────────┬─────────────┬─────────────────────────────┤
│   Type      │  Lifetime   │  Visibility                 │
├─────────────┼─────────────┼─────────────────────────────┤
│   Local     │  Function   │  Function only              │
│   Global    │  Program    │  All functions              │
│   Static    │  Program    │  Function only              │
└─────────────┴─────────────┴─────────────────────────────┘
```

---

## Pass by Value

C passes arguments **by value** — functions receive a copy, not the original:

```c
int inc(int x) {
    x = x + 1;
    return x;
}

int main(void) {
    int a = 10;
    inc(a);
    printf("A: %d\n", a);  // prints 10 — unchanged!
}
```

### To Modify: Capture the Return Value

```c
int main(void) {
    int a = 10;
    a = inc(a);  // a = 11
    a = inc(a);  // a = 12
}
```

**Pass by reference** is only possible with **pointers** (next lesson).

---

## C Data Types

### Integer Types

| Type | Size (typical) | Range |
|------|----------------|-------|
| `char` | 1 byte | -128 to 127 |
| `unsigned char` | 1 byte | 0 to 255 |
| `short` | 2 bytes | -32,768 to 32,767 |
| `int` | 4 bytes | ≈ ±2 billion |

### Floating Point Types

| Type | Size | Precision |
|------|------|-----------|
| `float` | 4 bytes | ~7 decimal digits |
| `double` | 8 bytes | ~15 decimal digits |

Both use mantissa + exponent representation (IEEE 754).

---

## Type Promotion

C automatically promotes smaller types in certain contexts:

**In variadic functions (like `printf`):**
- `char`, `short` → `int`
- `float` → `double`

```c
short s = 400;
printf("%d\n", s);  // Works: short promoted to int
```

This is why `printf` warns about `double` when you pass a `float`.

---

## Overflow Behavior

### Unsigned: Defined Wraparound

```c
unsigned char c = 255;
c++;  // c = 0 (wraps around predictably)
```

### Signed: Undefined Behavior ⚠️

```c
char c = 127;
c++;  // UNDEFINED — could be -128, could crash, could be anything
```

**Never rely on signed overflow behavior.**

---

## The `++` Operator

```c
x++;      // Increment x by 1 (same as x = x + 1)
++x;      // Also increments (subtle difference)
```

The name "C++" comes from this operator — "C incremented."

---

## Quick Reference

| Format | Type |
|--------|------|
| `%d` | int, short, char |
| `%f` | float, double |
| `%x` | int (hexadecimal) |
| `%.3f` | float with 3 decimal places |

```bash
man 3 printf    # Full format specifier documentation
```

---

## Code Files

- [`incr.c`](./incr.c) — Scope and type examples

<!-- IMPROVEMENTS: Add diagram showing stack frames for pass-by-value -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
