# Lessons 14-15-16-17 - Structs and Data Structures

**Video Lesson 14:** [Introduction to Structs](https://www.youtube.com/watch?v=p4IMHau2lq8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=16)

**Video Lesson 15:** [Linked Lists and File I/O](https://www.youtube.com/watch?v=aTT2W5NACEY&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=16)

**Video Lesson 16:** [Reference Counting with Structs](https://www.youtube.com/watch?v=VPs_QtlLNcs&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=17)

**Video Lesson 17:** [Flexible Array Members and hexdump](https://www.youtube.com/watch?v=grkIJjw6o18&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=18)

---

## Overview

These four lessons introduce **structs** — C's mechanism for creating composite data types. Structs are fundamental to building abstractions: they let you group related data together and create objects. We also explore linked lists, reference counting, memory layout, and the difference between pointers and flexible array members.

---

## What Is a Struct?

A struct is a user-defined data type that groups multiple variables under one name:

```c
struct fract {
    int num;    // numerator
    int den;    // denominator
};
```

This declares a new type called `struct fract` containing two integers.

```
┌──────────────────────────────────────┐
│           struct fract               │
├──────────────┬───────────────────────┤
│     num      │         den           │
│   (4 bytes)  │      (4 bytes)        │
└──────────────┴───────────────────────┘
       Total: 8 bytes
```

> **Key Insight:** Structs are the only C construct that manipulates something other than numbers. Everything else (pointers, arrays, integers) is fundamentally numeric.

---

## Declaring and Using Structs

### Stack Allocation (Local Variable)

```c
struct fract a;        // Declare variable of type struct fract
a.num = 1;             // Use dot (.) to access fields
a.den = 2;
```

### Heap Allocation (with malloc)

```c
struct fract *f = malloc(sizeof(struct fract));
f->num = 1;            // Use arrow (->) for pointer access
f->den = 2;
free(f);
```

### The Dot vs Arrow Rule

| Variable Type | Access Operator | Example |
|--------------|-----------------|---------|
| `struct fract a` | `.` (dot) | `a.num` |
| `struct fract *p` | `->` (arrow) | `p->num` |

> **Why the distinction?** C is designed to be explicit. When you see `->`, you know you're dealing with a pointer.

---

## Memory Layout and Padding

Structs align each field to memory addresses that are multiples of the field's size:

```c
struct example {
    unsigned char color;  // 1 byte
    int num;              // 4 bytes (needs 4-byte alignment)
    int den;              // 4 bytes
};
```

```
Expected: 1 + 4 + 4 = 9 bytes
Actual:   12 bytes!

┌───────┬───────────┬──────────┬──────────┐
│ color │  PADDING  │   num    │   den    │
│ 1 byte│  3 bytes  │ 4 bytes  │ 4 bytes  │
└───────┴───────────┴──────────┴──────────┘
```

The compiler inserts **padding** to ensure `num` starts at a 4-byte aligned address.

### Minimizing Padding

Order fields from largest to smallest:

```c
struct better {
    int num;              // 4 bytes at offset 0
    int den;              // 4 bytes at offset 4
    unsigned char color;  // 1 byte at offset 8
};
// Size: 12 bytes (struct must align to largest member)
```

> **Note:** Even reordering doesn't help here because the struct's total size must be a multiple of its largest member for array alignment.

---

## Passing Structs to Functions

### By Pointer (Recommended)

```c
void print_fraction(struct fract *f) {
    printf("%d/%d\n", f->num, f->den);
}

// Usage
print_fraction(&a);  // Pass address of local struct
print_fraction(f);   // f is already a pointer
```

### By Value (Copies the Entire Struct)

```c
struct fract create_fraction(int num, int den) {
    struct fract f;
    f.num = num;
    f.den = den;
    return f;  // Entire struct is COPIED to caller
}
```

> **Warning:** Returning structs by value causes memory copies. For small structs (like two integers), this is fine. For large structs, use pointers.

---

## Building a Fraction Library

A complete example using structs:

```c
struct fract *create_fraction(int num, int den) {
    struct fract *f = malloc(sizeof(*f));
    if (f == NULL) return NULL;  // malloc error checking
    f->num = num;
    f->den = den;
    return f;
}

void simplify_fraction(struct fract *f) {
    for (int d = 2; d <= f->num && d <= f->den; d++) {
        while (f->num % d == 0 && f->den % d == 0) {
            f->num /= d;
            f->den /= d;
        }
    }
}

void print_fraction(struct fract *f) {
    printf("%d/%d\n", f->num, f->den);
}
```

Compare to the non-struct version using `f[0]` and `f[1]` — structs make code much clearer!

---

## Linked Lists

A linked list is a data structure where each element points to the next:

```c
struct line {
    char *s;              // String content
    struct line *next;    // Pointer to next node
};
```

```
┌─────────────┐     ┌─────────────┐     ┌─────────────┐
│  s: "one"   │     │  s: "two"   │     │  s: "three" │
│  next: ─────┼────►│  next: ─────┼────►│  next: NULL │
└─────────────┘     └─────────────┘     └─────────────┘
```

### Building a List (Prepending)

```c
struct line *head = NULL;

while (fgets(buf, sizeof(buf), fp) != NULL) {
    struct line *l = malloc(sizeof(*l));
    l->s = malloc(strlen(buf) + 1);
    strcpy(l->s, buf);

    l->next = head;  // New node points to old head
    head = l;        // New node becomes new head
}
```

This builds the list in **reverse order** — perfect for implementing `tac` (reverse cat)!

### Traversing a List

```c
while (head != NULL) {
    printf("%s", head->s);
    head = head->next;
}
```

---

## File I/O Basics

### Opening and Reading Files

```c
FILE *fp = fopen(filename, "r");  // "r" = read mode
if (fp == NULL) {
    printf("File does not exist\n");
    return 1;
}

char buf[1024];
while (fgets(buf, sizeof(buf), fp) != NULL) {
    // Process each line
}

fclose(fp);
```

### Command-Line Arguments

```c
int main(int argc, char **argv) {
    // argc = argument count
    // argv = array of argument strings
    // argv[0] = program name
    // argv[1] = first argument
}
```

`char **argv` is a pointer to an array of pointers to characters (strings).

---

## Reference Counting with Structs

The PLS library from Lessons 12-13 becomes much cleaner with structs:

```c
struct pls {
    uint32_t len;       // String length
    uint32_t refcount;  // Reference count
    char str[];         // Flexible array member (C99)
};
```

### Creating with Initial Refcount

```c
char *ps_create(char *init, int len) {
    struct pls *p = malloc(sizeof(struct pls) + len + 1);
    p->len = len;
    p->refcount = 1;  // Start with one reference

    for (int j = 0; j < len; j++) {
        p->str[j] = init[j];
    }
    p->str[len] = 0;

    return p->str;  // Return pointer to string content
}
```

### Retain and Release

```c
void ps_retain(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(struct pls));
    p->refcount++;
}

void ps_release(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(struct pls));
    p->refcount--;
    if (p->refcount == 0) {
        free(p);
    }
}
```

### Correct Usage

```c
char *mystr = ps_create("Hello", 5);  // refcount = 1
global_string = mystr;
ps_retain(mystr);                      // refcount = 2

ps_release(mystr);                     // refcount = 1
printf("%s\n", global_string);         // Still valid!
ps_release(global_string);             // refcount = 0, freed
```

---

## Flexible Array Members vs Pointers

A common confusion: `char str[]` vs `char *str` in structs.

### Pointer Member (`char *str`)

```c
struct pls_pointer {
    long len;
    char *str;    // 8 bytes on 64-bit systems
};
```

```
┌──────────┬──────────────┐
│   len    │     str      │ ──────► "Hello" (elsewhere in memory)
│ 8 bytes  │   8 bytes    │
└──────────┴──────────────┘
```

The pointer is stored **inside** the struct and points **elsewhere**.

### Flexible Array Member (`char str[]`)

```c
struct pls_flexible {
    long len;
    char str[];   // 0 bytes in struct, placeholder for data after
};
```

```
┌──────────┬─────────────────────────┐
│   len    │  H  e  l  l  o  \0      │
│ 8 bytes  │  (allocated extra)      │
└──────────┴─────────────────────────┘
```

The data is stored **directly after** the struct. `str` is just an offset, not a real field.

```c
// Allocate struct + space for string
struct pls_flexible *p = malloc(sizeof(struct pls_flexible) + len + 1);
// p->str points to byte immediately after struct header
```

> **Key Difference:** Flexible array members don't take space in the struct — they're a way to access memory allocated beyond the struct's fixed fields.

---

## Debug Magic Numbers

To detect use-after-free or invalid pointers:

```c
struct pls {
    uint32_t len;
    uint32_t refcount;
#ifdef PLS_DEBUG
    uint32_t magic;    // Only in debug builds
#endif
    char str[];
};

#define PLS_MAGIC 0xDEADBEEF

void ps_validate(struct pls *p) {
#ifdef PLS_DEBUG
    if (p->magic != PLS_MAGIC) {
        printf("INVALID STRING: Aborting\n");
        exit(1);
    }
#endif
}
```

Set `magic = 0` when freeing. Any subsequent access will fail validation.

---

## The Ternary Operator

A concise way to write simple if-else:

```c
// Long form
int c;
if (isprint(byte[i])) {
    c = byte[i];
} else {
    c = '.';
}

// Ternary form
int c = isprint(byte[i]) ? byte[i] : '.';
```

Syntax: `condition ? value_if_true : value_if_false`

---

## Hexdump: Practical Struct Example

A utility to visualize memory layout:

```c
#define HEXDUMP_CHARS_PER_LINE 16

void hexdump(void *p, size_t len) {
    unsigned char *byte = p;
    size_t po = 0;  // Print offset (for readable chars)

    for (size_t j = 0; j < len; j++) {
        printf("%02X ", byte[j]);

        if (((j+1) % HEXDUMP_CHARS_PER_LINE == 0) || (j == len-1)) {
            // Print readable characters
            printf("\t");
            for (size_t i = po; i <= j; i++) {
                int c = isprint(byte[i]) ? byte[i] : '.';
                printf("%c", c);
            }
            printf("\n");
            po = j + 1;
        }
    }
}
```

Useful for understanding memory layout of structs!

---

## Design Considerations

From Sanfilippo's experience with Redis:

1. **Reference counting often belongs at a higher level** — not in string libraries, but in object wrappers that manage different data types

2. **Variable-size headers save memory** — Redis SDS uses different header sizes based on string length (5-bit, 8-bit, 16-bit, 32-bit, 64-bit)

3. **Magic refcount values** — Setting refcount to `UINT32_MAX` marks objects as "immortal" (never freed), useful for interned strings

4. **Trade-offs are context-dependent** — 4GB string limit may be fine for most applications but not for others

---

## Quick Reference

### Struct Syntax

| Operation | Syntax |
|-----------|--------|
| Declare struct type | `struct name { fields };` |
| Declare variable | `struct name var;` |
| Declare pointer | `struct name *ptr;` |
| Access field (variable) | `var.field` |
| Access field (pointer) | `ptr->field` |
| Size of struct | `sizeof(struct name)` or `sizeof(*ptr)` |

### Memory Functions

| Function | Purpose |
|----------|---------|
| `memcpy(dst, src, n)` | Copy n bytes from src to dst |
| `memset(ptr, val, n)` | Set n bytes to val |
| `strlen(s)` | Length of null-terminated string |

---

## Code Files

- [`struct-base.c`](./struct-base.c) - Basic struct usage with fractions
- [`tac.c`](./tac.c) - Linked list implementation (reverse cat)
- [`pls.c`](./pls.c) - Full PLS library with reference counting
- [`hexdump.c`](./hexdump.c) - Memory visualization utility


*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
