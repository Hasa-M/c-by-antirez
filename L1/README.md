# Lesson 01 - Introduction to C and the Compiler

**Video:** [Watch on YouTube](https://www.youtube.com/watch?v=HjXBXBgfKyk&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=1)

---

## Overview

This lesson introduces C as a compiled language and walks through the compilation process using a simple Hello World program. We explore how C code transforms into executable machine code.

**Prerequisites:** Basic programming experience in any language (Python, JavaScript, etc.).

---

## The Compilation Process

Unlike interpreted languages, C requires compilation before execution:

```
┌────────────┐     ┌────────────┐     ┌────────────┐     ┌────────────┐
│  hello.c   │────▶│ Preprocessor────▶│  Compiler  │────▶│   Linker   │────▶ a.out
│ (source)   │     │ (#include) │     │ (C → asm)  │     │ (→ binary) │
└────────────┘     └────────────┘     └────────────┘     └────────────┘
```

```bash
cc hello.c      # Compile → creates a.out
./a.out         # Execute the binary
```

---

## Hello World Breakdown

```c
#include <stdio.h>

int main(void) {
    printf("Hello World\n");
    return 0;
}
```

| Line | Purpose |
|------|---------|
| `#include <stdio.h>` | Preprocessor directive: includes standard I/O function declarations |
| `int main(void)` | Entry point function, returns int to OS, takes no parameters |
| `printf(...)` | Library function (not part of C language itself) |
| `return 0` | Returns success status to operating system |

---

## Compiler Optimization

The `-O2` flag enables optimizations that can significantly transform your code:

```bash
cc -S hello.c           # Generate assembly (no optimization)
cc -O2 -S hello.c       # Generate optimized assembly
```

**Example:** With `-O2`, the compiler replaces `printf("Hello World\n")` with the simpler `puts("Hello World")` — it even removes the `\n` since `puts` adds one automatically.

---

## Language vs Library

**C Language keywords:** `int`, `void`, `return`, `if`, `while`, `for`, etc.

**C Standard Library:** `printf`, `puts`, `malloc`, `scanf` — these are functions defined in library headers, not part of the language itself.

---

## Header Files (.h) vs Source Files (.c)

| .c Files | .h Files |
|----------|----------|
| Implementation code | Declarations (prototypes) |
| Function bodies | Function signatures |
| Compiled into objects | Included via `#include` |

**Function Prototype** — declares a function without implementing it:
```c
int printf(const char *format, ...);  // Prototype (ends with ;)
```

This tells the compiler what types the function expects/returns, without needing the actual code.

---

## The Manual (man)

```bash
man 3 printf    # Section 3 = C library functions
man 3 puts      # Always use section 3 for C functions
```

| Section | Content |
|---------|---------|
| 1 | Shell commands |
| 3 | C library functions |

---

## Quick Reference

```bash
cc hello.c                # Compile to a.out
cc hello.c -o hello       # Compile with custom name
cc -O2 hello.c            # Compile with optimization
cc -S hello.c             # Generate assembly only
./a.out                   # Run the program
man 3 printf              # View C function documentation
```

---

## Code Files

- [`hello_world.c`](./hello_world.c) - Hello World program

<!-- IMPROVEMENTS: Add compilation error examples, assembly output screenshot -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
