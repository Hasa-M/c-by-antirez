# Lesson 18 - typedef and File I/O

**Video:** [typedef and Standard I/O](https://www.youtube.com/watch?v=3w73xjUSUEU&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=21)

---

## Overview

This lesson introduces `typedef` — a way to create type aliases in C. We see how typedef makes structs cleaner and enables **opaque types** in library design. The lesson also covers file I/O with `fopen`, `fread`, and `fclose`.

---

## typedef: Creating Type Aliases

`typedef` creates a new name for an existing type:

```c
typedef int error_code;

error_code foo(void) {
    return -20;
}

error_code result = foo();  // Same as: int result = foo();
```

The syntax mirrors variable declaration — just add `typedef` in front.

---

## typedef with Structs

The real power: eliminating `struct` keyword everywhere.

**Without typedef:**
```c
struct fract { int n; int d; };
struct fract f;           // Must write "struct fract" every time
```

**With typedef:**
```c
typedef struct {
    int n;
    int d;
} fract;

fract f;                  // Clean, like a built-in type
f.n = 10;
f.d = 20;
```

You can even typedef pointers:

```c
typedef fract *fractptr;
fractptr fp = &f;         // fp is a pointer to fract
```

---

## Opaque Types: Library Design

`typedef` enables **information hiding**. The C standard library does exactly this:

```c
FILE *fp = fopen("file.txt", "r");
```

`FILE` is a typedef — you don't know (or need to know) its internal structure. The library manages it; you just pass the pointer around.

This is the foundation of API design in C:
- Expose a typedef name
- Hide the struct definition
- Provide functions that operate on pointers to that type

---

## File I/O Basics

### Opening and Closing

```c
FILE *fp = fopen("filename.c", "r");  // "r" = read mode
if (fp == NULL) {
    printf("Unable to open file\n");
    return 1;
}

// ... use the file ...

fclose(fp);  // Always close: frees memory + file descriptor
```

### Reading with fread

```c
char buf[32];
size_t nread = fread(buf, 1, sizeof(buf), fp);
//                   ↑    ↑  ↑            ↑
//                  dest  |  count       file
//                     element size
```

`fread` returns the number of elements read. Returns 0 at end-of-file.

> **API Note:** Sanfilippo calls the two-size-parameter design (element size × count) an antipattern. Modern APIs would just take a byte count.

### Reading a File in a Loop

```c
char buf[32];
size_t nread;

while (1) {
    nread = fread(buf, 1, sizeof(buf), fp);
    if (nread == 0) break;  // EOF or error
    // Process buf (nread bytes)
}
```

---

## Practical Example: Self-Hexdumping Program

The lesson builds a program that hexdumps its own source code:

```c
FILE *fp = fopen("stdio1.c", "r");
char buf[32];
size_t nread;

while (1) {
    nread = fread(buf, 1, sizeof(buf), fp);
    if (nread == 0) break;
    hexdump(buf, nread);
}
fclose(fp);
```

> *"This is perhaps the first useful program we write."*

---

## Key Takeaways

1. **typedef creates aliases**, not new types — the compiler sees them as identical

2. **typedef + struct** = cleaner code: `fract f` instead of `struct fract f`

3. **Opaque pointers** (`FILE *`) are the standard C pattern for encapsulation

4. **fopen/fread/fclose** are library functions (libc), not system calls — they wrap lower-level OS calls

5. **Coming next:** implementing our own I/O library using raw POSIX system calls

---

## Quick Reference

| typedef Pattern | Result |
|-----------------|--------|
| `typedef int mytype;` | `mytype` = `int` |
| `typedef struct {...} name;` | `name` = that struct |
| `typedef name *nameptr;` | `nameptr` = pointer to name |

| File Function | Purpose |
|---------------|---------|
| `fopen(path, mode)` | Open file, returns `FILE*` or NULL |
| `fread(buf, size, count, fp)` | Read into buffer, returns items read |
| `fclose(fp)` | Close file, free resources |

---

## Code Files

- [`typedef.c`](./typedef.c) — Basic typedef examples with structs
- [`stdio1.c`](./stdio1.c) — File reading with hexdump output


*Notes from Salvatore Sanfilippo's C Programming Course.*
