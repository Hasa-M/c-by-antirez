# Lessons 09-10-11 - Pointers

**Video Lesson 9:** [Introduction to Pointers](https://www.youtube.com/watch?v=BBgZs-jd_QY&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=10)

**Video Lesson 10:** [Pointer Arithmetic and Strings](https://www.youtube.com/watch?v=lc7hL9Wt-ho&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=11)

**Video Lesson 11:** [Type Casting and Pointer Applications](https://www.youtube.com/watch?v=msGzuneFpDU&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=12)

---

## Overview

These three lessons cover pointers — one of C's most powerful and often misunderstood features. Pointers are fundamentally simple: they're variables that store memory addresses. Understanding them unlocks pass-by-reference, efficient array manipulation, and direct memory access.

---

## What Is a Pointer?

A pointer is a variable that holds a **memory address** instead of a direct value. The asterisk `*` before a variable name during declaration indicates it's a pointer:

```c
int x = 5;      // Regular integer variable
int *y;         // Pointer to an integer (holds an address)
```

```
┌─────────────────────────────────────────────────────────────┐
│                        MEMORY                               │
├─────────────┬─────────────┬─────────────────────────────────┤
│  Address    │   Value     │   Variable                      │
├─────────────┼─────────────┼─────────────────────────────────┤
│  0x7fff001  │      5      │   x (int, 4 bytes)              │
│  0x7fff010  │  0x7fff001  │   y (int*, 8 bytes on 64-bit)   │
└─────────────┴─────────────┴─────────────────────────────────┘
         ↑                              │
         └──────────────────────────────┘
                   y points to x
```

> **Key insight:** The pointer type (`int*`, `char*`) tells the compiler what kind of data lives at that address — not the size of the pointer itself. All pointers are the same size (8 bytes on 64-bit systems).

---

## Declaration Style

Sanfilippo recommends placing the asterisk next to the variable name, not the type:

```c
int *y, z;    // y is a pointer, z is an int (NOT a pointer!)
int *y, *z;   // Both are pointers
```

The asterisk grammatically binds to the variable name, not the type. Writing `int* y, z;` misleadingly suggests both are pointers.

---

## The Two Operators: `&` and `*`

| Operator | Name | Purpose |
|----------|------|---------|
| `&` | Address-of | Get the memory address of a variable |
| `*` | Dereference | Access the value at a memory address |

```c
int x = 5;
int *y = &x;    // y = address of x

printf("%p\n", y);    // Prints address (e.g., 0x7fff001)
printf("%d\n", *y);   // Prints 5 (value AT that address)

*y = 10;              // Write 10 to the address y points to
printf("%d\n", x);    // Prints 10 — x was modified!
```

### The `&` Operator Forces Memory Allocation

When you take the address of a variable, the compiler **must** store it in memory (not a register):

```c
int x = 5;
int *y = &x;  // Compiler now knows x must live in RAM, not a CPU register
```

---

## NULL: The Special Address

`NULL` (or `0`) represents an invalid address — a pointer that points nowhere:

```c
int *p = NULL;    // Safe initialization
int *q = 0;       // Equivalent

if (p == NULL) {
    printf("Pointer not set\n");
}
```

Always initialize pointers to `NULL` if you're not immediately assigning them.

---

## Dereferencing: Reading and Writing

**Dereferencing** means accessing the value at the address a pointer holds. It works for both reading and writing:

```c
int x = 5;
int *p = &x;

// Reading
int value = *p;     // value = 5

// Writing
*p = 10;            // x is now 10
```

---

## Pointer-Array Equivalence

In C, pointers and arrays are deeply connected. These are equivalent:

```c
char str[] = "Hello";
char *p = str;        // Array name IS a pointer to first element

// All equivalent ways to access characters:
str[2]      // 'l'
p[2]        // 'l'
*(p + 2)    // 'l'
*(str + 2)  // 'l'
```

```
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │  0  │
└─────┴─────┴─────┴─────┴─────┴─────┘
  ↑     ↑     ↑
 p[0]  p[1]  p[2]
 *p   *(p+1) *(p+2)
```

> **Important:** The array name `str` is already a pointer — you don't need `&str`.

---

## Pointer Arithmetic

When you increment a pointer, it advances by the **size of the type** it points to:

```c
char *cp;    // cp++ advances by 1 byte
int *ip;     // ip++ advances by 4 bytes
short *sp;   // sp++ advances by 2 bytes
```

```
Memory layout for char str[] = "AABBCCDD":

Address:  0x100  0x101  0x102  0x103  0x104  0x105  0x106  0x107
          ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
char*:    │  A   │  A   │  B   │  B   │  C   │  C   │  D   │  D   │
          └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
          cp     cp+1   cp+2   cp+3   cp+4   cp+5   cp+6   cp+7

short*:   │  AA  │      │  BB  │      │  CC  │      │  DD  │
          sp            sp+1          sp+2          sp+3
```

This is why pointer types matter — they determine the step size during arithmetic.

---

## Why Pointers Enable Pass-by-Reference

C passes arguments **by value** — functions receive copies. Pointers let you pass the address, enabling modification of the original:

```c
void incr(int *p) {
    *p = *p + 1;    // Modify the value AT address p
}

int main(void) {
    int x = 5;
    incr(&x);       // Pass address of x
    printf("%d\n", x);  // Prints 6 — x was modified!
    return 0;
}
```

Without pointers, `x` would remain 5 because `incr` would only modify a copy.

---

## Walking Through a String with Pointers

```c
char str[] = "Hello";
char *p = str;

while (*p != 0) {      // Until we hit the null terminator
    putchar(*p);       // Print current character
    p++;               // Move to next character
}
```

This is equivalent to `while (*p)` since `0` is falsy in C.

The pointer starts at `str[0]` and walks through memory until it finds the NUL terminator (`\0`).

---

## Pointer to Pointer

Since pointers are variables stored in memory, you can have pointers to pointers:

```c
int x = 5;
int *y = &x;      // Pointer to int
int **z = &y;     // Pointer to pointer to int

printf("%p\n", y);   // Address of x
printf("%p\n", z);   // Address of y
```

```
┌─────────┐     ┌─────────┐     ┌─────────┐
│    5    │ ←── │  &x     │ ←── │  &y     │
│   (x)   │     │   (y)   │     │   (z)   │
└─────────┘     └─────────┘     └─────────┘
   int           int*            int**
```

Each dereference "removes" one level of indirection: `*z` gives `y`, `**z` gives `x`.

---

## Type Casting with Pointers

You can reinterpret memory by casting pointers to different types:

```c
char str[] = "AABB";
short *sp = (short *)str;    // Cast char* to short*

printf("%d\n", sp[0]);   // Reads first 2 bytes as a short
printf("%d\n", sp[1]);   // Reads next 2 bytes as a short
```

The cast `(short *)` tells the compiler: "Trust me, treat this address as pointing to shorts."

> **Warning:** This is dangerous if you don't know exactly what you're doing. Reading/writing past your allocated memory causes undefined behavior or crashes.

---

## Character '0' vs. Byte Value 0

A common confusion:

```c
char str[] = "Hello00World";
```

The characters `'0'` have ASCII value **48**, not zero. The string continues past them.

To actually embed a null byte (value 0), use octal escape:

```c
char str[] = "Hello\0World";  // String ends at \0
```

```
'0' (character zero) = ASCII 48
'\0' (null byte)     = value 0   ← This terminates strings
```

---

## Prefix-Length Strings

C strings use a null terminator. An alternative is **prefix-length strings** where the first byte(s) store the length:

```c
char str[] = "\017Hello World!!!";  // \017 = octal 15
char *p = str;

int len = *p++;    // Read length, advance pointer
for (int j = 0; j < len; j++) {
    putchar(p[j]);
}
```

The first byte (`\017` = 15 in decimal) indicates the string length. This approach:
- Allows embedded null bytes
- Provides O(1) length lookup
- Limits length to 255 bytes with a single-byte prefix

---

## Practical Application: Pointer Swapping

From the Game of Life (Lesson 8), pointers enable elegant buffer swapping:

```c
char *old = old_grid;
char *new = new_grid;

while (1) {
    compute_new_state(old, new);
    print_grid(new);
    
    // Swap pointers instead of copying data
    char *temp = old;
    old = new;
    new = temp;
}
```

Swapping pointers is instant (just changing two 8-byte values), while copying entire arrays would be expensive.

---

## Common Pitfalls

### 1. Dereferencing NULL or Uninitialized Pointers

```c
int *p;           // Uninitialized — points to garbage
*p = 10;          // CRASH: Segmentation fault
```

### 2. Writing Out of Bounds

```c
int x = 5;
int *p = &x;
p[1] = 10;        // Writing past x — corrupts adjacent memory
```

### 3. Confusing Pointer Assignment vs. Dereferencing

```c
int *p = &x;
p = 10;     // WRONG: p now points to address 10 (invalid)
*p = 10;    // RIGHT: write 10 to the address p points to
```

---

## Quick Reference

| Syntax | Meaning |
|--------|---------|
| `int *p` | Declare pointer to int |
| `&x` | Get address of x |
| `*p` | Dereference: value at address p |
| `p[i]` | Same as `*(p + i)` |
| `p++` | Advance by sizeof(*p) bytes |
| `NULL` | Invalid/empty address (0) |
| `%p` | Printf format for pointers |

### Pointer Sizes (64-bit system)

| Declaration | Size of pointer | Size of pointed-to type |
|-------------|-----------------|-------------------------|
| `char *p` | 8 bytes | 1 byte |
| `int *p` | 8 bytes | 4 bytes |
| `int **p` | 8 bytes | 8 bytes (pointer) |

---

## Code Files

- [`pointers_base.c`](./pointers_base.c) — Basic pointer operations and pass-by-reference
- [`pointers_math.c`](./pointers_math.c) — Pointer arithmetic, type casting, prefix-length strings


*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
