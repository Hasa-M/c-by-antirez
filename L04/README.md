# Lesson 04 - C Types Deep Dive and Fixed-Width Integers

**Video:** [Watch on YouTube](https://www.youtube.com/watch?v=SWWHqgSwQFw&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=5)

---

## Overview

This lesson explores C's type system in depth: why type sizes aren't guaranteed, how to discover them with `sizeof`, how to find min/max values with `limits.h`, and how to use fixed-width types from `stdint.h`.

---

## Platform-Dependent Types

Unlike modern languages where `int` has a fixed size everywhere, **C doesn't guarantee type sizes**. This was intentional — C was designed to run on everything from 8-bit microcontrollers to 64-bit supercomputers.

```c
int x = 5;  // Could be 16, 32, or 64 bits depending on platform
```

### The `sizeof` Operator

Use `sizeof` to discover actual sizes on your system:

```c
printf("int is %lu bytes\n", sizeof(x));    // Returns size in bytes
printf("long is %lu bytes\n", sizeof(long));
```

> **Note:** `sizeof` returns `unsigned long`, so use `%lu` format specifier.

---

## Typical Sizes (Modern Systems)

These are **not guaranteed** by the C standard, but hold true for ~99% of modern systems:

```
┌──────────┬────────────┬─────────────────────────────────┐
│   Type   │    Size    │    Range (signed)               │
├──────────┼────────────┼─────────────────────────────────┤
│   char   │   1 byte   │   -128 to 127                   │
│   short  │   2 bytes  │   -32,768 to 32,767             │
│   int    │   4 bytes  │   ≈ ±2 billion                  │
│   long   │   4 or 8*  │   Matches processor word size   │
└──────────┴────────────┴─────────────────────────────────┘
* long is 8 bytes on 64-bit systems, 4 bytes on 32-bit
```

### Why `long` Matters

`long` typically matches the processor's **word size** — it can usually hold a memory address. Old programs that stored pointers in `int` break on 64-bit systems.

---

## Finding Min/Max Values: `limits.h`

```c
#include <limits.h>

printf("int min: %d\n", INT_MIN);   // -2147483648
printf("int max: %d\n", INT_MAX);   // 2147483647
```

The preprocessor replaces `INT_MIN` and `INT_MAX` with the actual limits for your platform.

---

## Fixed-Width Types: `stdint.h`

When you need **guaranteed sizes**, use `stdint.h` (available since C99):

```c
#include <stdint.h>

uint64_t big = 1234567890123456789ULL;  // Exactly 64 bits, unsigned
int64_t sbig = -1234567890123456789LL;  // Exactly 64 bits, signed
int32_t precise = 42;                    // Exactly 32 bits
```

### Special Types

| Type | Purpose |
|------|---------|
| `size_t` | Size of objects (return type of `sizeof`) |
| `intptr_t` | Signed integer that can hold a pointer |
| `uintptr_t` | Unsigned integer that can hold a pointer |

**Why `intptr_t` exists:** Pointer subtraction can yield negative values, so a signed type is needed.

---

## Terminal Escape Sequences

C can send control sequences to terminals:

```c
void clear(void) {
    printf("\x1b[2J");   // Clear screen (hex notation)
    // or
    printf("\033[2J");   // Same thing (octal notation)
}
```

- `\x1b` or `\033` = ESC character (ASCII 27)
- `[2J` = Clear entire screen (VT100 sequence)
- `[H` = Move cursor to home position

---

## Program Structure Recap

```c
#include <stdio.h>    // Preprocessor directive

void clear(void) {    // Function: returns void, takes void
    printf("\x1b[H");
}

int main(void) {      // Entry point
    clear();          // Function call
    printf("Hi\n");   // Statement (ends with ;)
    return 0;         // Return statement
}
```

**Key points:**
- Statements end with `;`
- Indentation is for humans (compiler ignores it)
- Style is personal — develop your own

---

## Quick Reference

```c
#include <limits.h>   // INT_MIN, INT_MAX, CHAR_MAX, etc.
#include <stdint.h>   // int32_t, uint64_t, size_t, etc.

sizeof(x)             // Size in bytes (returns unsigned long)
```

| Suffix | Meaning |
|--------|---------|
| `U` | Unsigned literal |
| `L` | Long literal |
| `LL` | Long long literal |
| `ULL` | Unsigned long long |

---

## Code Files

- [`hello_world.c`](./hello_world.c) — Types and sizeof examples

<!-- IMPROVEMENTS: Add diagram showing memory layout of different types -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
