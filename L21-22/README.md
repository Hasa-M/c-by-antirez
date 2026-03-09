# Lessons 21-22 - Unions, Bitfields and Function Pointers

**Video Lesson 21:** [Unions and Bitfields](https://www.youtube.com/watch?v=TM4jgODgdFY&t=320s)

**Video Lesson 22:** [Function Pointers](https://www.youtube.com/watch?v=OIseV5lcx8w&t=74s)

---

## Overview

Three C features that unlock advanced patterns. **Unions** overlay variables in the same memory — saving space for multi-type data. **Bitfields** pack integers into specific bit widths. **Function pointers** let you pass behavior as data — enabling callbacks, generic algorithms, and higher-order functions in C.

---

## Unions

A `union` declares fields that **share the same memory address**. Writing to one overwrites the other.

```c
struct foo {
    union {
        int i;
        unsigned char a[4];
    };
};
```

```
Struct (sequential):          Union (overlapping):
┌──────┬──────────────┐      ┌──────────────────┐
│  i   │  a[0..3]     │      │  i  overlaps a[] │
│ 4B   │  4B          │      │  same 4 bytes    │
└──────┴──────────────┘      └──────────────────┘
Total: 8 bytes               Total: 4 bytes
```

### Exploring Byte Representation

Since `i` and `a[]` share memory, writing an integer lets you inspect its bytes:

```c
struct foo f;
f.i = INT_MAX;  // 2147483647
printf("%d %d %d %d\n", f.a[0], f.a[1], f.a[2], f.a[3]);
// Output (little-endian): 255 255 255 127
```

### The Real Use Case: Tagged Unions

The primary purpose is saving memory when fields are **mutually exclusive**. From Redis vector sets:

```c
struct ExprToken {
    int ref_count;
    int token_type;   // Determines which union member is valid
    int offset;
    union {
        double number;          // if token_type == TOKEN_NUMBER
        struct { char *s; int len; } str;  // if token_type == TOKEN_STRING
        int op_code;            // if token_type == TOKEN_OP
    };
};
```

Without the union, every token would pay the size of **all** fields. With the union, it only pays the size of the **largest** field.

### Anonymous vs Named Unions

```c
// Anonymous (C99+) — fields accessed directly
union { int i; char a[4]; };
f.i = 10;

// Named — requires extra accessor
union { int i; char a[4]; } u;
f.u.i = 10;
```

---

## Bitfields

Bitfields specify how many **bits** a struct field uses:

```c
struct foo {
    unsigned char a : 4;  // 4 bits → 0..15
    unsigned char b : 4;  // 4 bits → 0..15
    unsigned char c : 8;  // 8 bits → 0..255
};
// sizeof: 2 bytes (instead of 3 separate chars)
```

### Overflow Behavior

Values exceeding the bit width are truncated:

```c
f.a = 16;  // 16 = 10000 in binary → only 4 bits kept → 0
f.a = 17;  // 17 = 10001 → bit 0 survives → 1
```

For `unsigned` types, this wrapping is well-defined. For `signed` types, it's **undefined behavior**.

### Real-World: Redis Object Header

```c
typedef struct redisObject {
    unsigned type     : 4;   // Object type
    unsigned encoding : 4;   // Internal encoding
    unsigned lru      : 24;  // LRU/LFU eviction data
    int refcount;
    void *ptr;
} robj;
```

When you have millions of objects, saving a few bytes per object matters.

### Bitfield Caveats

- **Memory layout is implementation-defined** — bit ordering depends on compiler and endianness
- **Don't use for serialization** — reading a bitfield struct from a file won't be portable
- **Safe for in-memory use** — same architecture guarantees consistent layout
- For portable binary formats, use `unsigned char[]` with manual bit shifting instead

---

## Function Pointers

Functions live in memory at specific addresses. A function pointer stores that address:

```c
printf("%p\n", main);  // Prints address of main function
```

### Declaration Syntax

Take the function prototype, wrap the name in parentheses, add `*`:

```c
// Function:          void hello(void)
// Function pointer:  void (*fp)(void)

void (*fp)(void) = hello;
fp();  // Calls hello()
```

### Passing Functions as Arguments

This is where function pointers become powerful — **functions that take functions**:

```c
void call_n_times(int n, void (*fn)(void)) {
    while (n--) {
        fn();
    }
}

call_n_times(10, hello);   // Calls hello() 10 times
call_n_times(10, baubau);  // Calls baubau() 10 times
```

### Practical Example: qsort

The standard library `qsort` sorts any array — it just needs a comparator function:

```c
#include <stdlib.h>

int compare_integers(const void *a, const void *b) {
    const int *ap = a;
    const int *bp = b;
    if (ap[0] > bp[0]) return 1;
    else if (ap[0] < bp[0]) return -1;
    else return 0;
}

int a[10] = { /* ... random values ... */ };
qsort(a, 10, sizeof(int), compare_integers);
```

`qsort` doesn't know what your data looks like — it just calls your comparator and swaps elements by size. The function pointer is what makes this generic.

### Comparator Contract

| Return | Meaning |
|--------|---------|
| `< 0` | a comes before b |
| `0` | a equals b |
| `> 0` | a comes after b |

> **Warning:** Don't use `return *ap - *bp` — it overflows when values are far apart (e.g. `10 - INT_MAX`). Use explicit comparisons instead.

### The `const` Qualifier

`const void *a` means: "I promise not to modify what `a` points to." The compiler enforces this — attempting to write through a `const` pointer is an error.

---

## Why Function Pointers Matter

Function pointers give C **higher-order functions** — the ability to parameterize behavior:

- **Callbacks** — notify me when something happens
- **Generic algorithms** — sort anything with a custom comparator
- **Plugin systems** — load behavior at runtime
- **Structs with function pointers** — the closest C gets to objects (next lesson)

---

## Quick Reference

### Union

| Feature | Syntax |
|---------|--------|
| Named union | `union name { int a; float b; };` |
| Anonymous (in struct) | `union { int a; float b; };` |
| Size | Equals the largest member |

### Bitfield

| Feature | Syntax |
|---------|--------|
| Declaration | `unsigned int flags : 4;` |
| Max value | 2^bits - 1 |
| Overflow (unsigned) | Wraps around (defined) |
| Overflow (signed) | Undefined behavior |

### Function Pointer

| Operation | Syntax |
|-----------|--------|
| Declare | `void (*fp)(int, int)` |
| Assign | `fp = my_function` |
| Call | `fp(1, 2)` |
| As parameter | `void sort(int n, int (*cmp)(void*, void*))` |

---

## Code Files

- [`union.c`](./union.c) — Union basics and byte inspection
- [`bitfield.c`](./bitfield.c) — Bitfield declaration and size
- [`function-pointers.c`](./function-pointers.c) — Function pointers and call_n_times
- [`function-pointers-2.c`](./function-pointers-2.c) — qsort with comparator callback


*Notes from Salvatore Sanfilippo's C Programming Course.*
