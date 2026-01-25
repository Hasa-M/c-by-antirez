# Lessons 12-13 - Dynamic Memory Allocation

**Video Lesson 12:** [Introduction to malloc and free](https://www.youtube.com/watch?v=ZkaKwWXJXs8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=15)

**Video Lesson 13:** [Advanced PLS with 4-byte Header](https://www.youtube.com/watch?v=9AhaOdEBmPc&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=14)

---

## Overview

These two lessons introduce **dynamic memory allocation** in C using `malloc` and `free`. We build a practical Prefixed-Length String (PLS) library that demonstrates why dynamic allocation is essential and how it enables creating objects that persist beyond function scope.

---

## The Problem: Static Allocation Limits

In early lessons, we used fixed-size buffers:

```c
char buffer[256];
ps_init(buffer, "Hello World", 11);
```

This approach has serious limitations:
- Can't create multiple strings without pre-allocating space for each
- Buffer sizes must be known at compile time
- Memory is wasted if strings are smaller than the buffer
- Can't return strings from functions (local variables are destroyed)

---

## malloc and free: The Solution

`malloc` allocates memory dynamically at runtime. `free` releases it when no longer needed.

```c
#include <stdlib.h>

char *s = malloc(100);    // Allocate 100 bytes
// ... use the memory ...
free(s);                  // Release when done
```

### Key Properties

| Function | Purpose | Returns |
|----------|---------|---------|
| `malloc(size)` | Allocate `size` bytes | Pointer to memory, or `NULL` on failure |
| `free(ptr)` | Release previously allocated memory | Nothing |

```
┌──────────────────────────────────────────────────────────────┐
│                      HEAP MEMORY                              │
├──────────────────────────────────────────────────────────────┤
│  malloc(12) returns pointer to:                              │
│  ┌────────────────────────┐                                  │
│  │ 12 bytes of usable     │                                  │
│  │ memory you control     │                                  │
│  └────────────────────────┘                                  │
│                                                              │
│  This memory persists until you call free() on it            │
└──────────────────────────────────────────────────────────────┘
```

> **Critical Rule:** Every `malloc` must have a corresponding `free`. Memory allocated with `malloc` remains valid until explicitly freed.

---

## Prefixed-Length Strings (PLS)

C strings use null termination (`\0`). An alternative is **prefixed-length strings** where the length is stored before the string data:

### Version 1: Single-Byte Length (Lesson 12)

```c
/* Memory Layout:
 * ┌───┬─────────────────────┬───┐
 * │ L │ String content...   │ 0 │
 * └───┴─────────────────────┴───┘
 *   1 byte    len bytes      null terminator
 */
```

```c
char *ps_create(char *init, int len) {
    char *s = malloc(1 + len + 1);  // length byte + string + null
    unsigned char *lenptr = (unsigned char*)s;
    *lenptr = len;

    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }
    s[len+1] = 0;  // null terminator for C compatibility
    return s;
}
```

**Limitation:** Maximum string length is 255 bytes (single byte can hold 0-255).

### Version 2: Four-Byte Length (Lesson 13)

```c
/* Memory Layout:
 * ┌──────────┬─────────────────────┬───┐
 * │   LLLL   │ String content...   │ 0 │
 * └──────────┴─────────────────────┴───┘
 *   4 bytes       len bytes         null
 */
```

```c
#include <stdint.h>

char *ps_create(char *init, int len) {
    char *s = malloc(4 + len + 1);
    uint32_t *lenptr = (uint32_t*)s;
    *lenptr = len;

    s += 4;  // Move pointer to string start
    for (int j = 0; j < len; j++) {
        s[j] = init[j];
    }
    s[len] = 0;
    return s;  // Return pointer to string, not to length!
}
```

---

## The "Hidden Header" Pattern

A clever trick: return a pointer to the **string content**, not the allocation start. The length lives "behind" the pointer:

```
What malloc returns:    What ps_create returns:
        │                       │
        ▼                       ▼
┌───────────────┬───────────────────────────┐
│  LLLL (len)   │  Hello World\0            │
└───────────────┴───────────────────────────┘
        ◄──────►
        4 bytes
```

To get the length back, subtract from the pointer:

```c
uint32_t ps_len(char *s) {
    uint32_t *lenptr = (uint32_t*)(s - 4);
    return *lenptr;
}

void ps_free(char *s) {
    free(s - 4);  // Must free the original allocation pointer!
}
```

### Benefits of This Pattern

1. **C Compatibility:** The returned pointer is a valid C string (null-terminated)
2. **O(1) Length Lookup:** No need to scan for null terminator
3. **Binary Safe:** Can contain embedded null bytes (length is known)
4. **Interoperability:** Works with standard C string functions like `printf("%s", s)`

---

## C String Interoperability

Since we add a null terminator and return a pointer to the string content:

```c
char *my_str = ps_create("Hello World", 11);

// Works with standard C functions!
printf("%s\n", my_str);  // No conversion needed
strlen(my_str);          // Returns 11

// But we also have O(1) length access
ps_len(my_str);          // Returns 11 instantly
```

---

## Introduction to Reference Counting

**Problem:** Multiple variables may point to the same string. How do we know when to free it?

```c
char *global_string;

int main(void) {
    char *mystr = ps_create("Hello World", 11);
    global_string = mystr;  // Two references to same string!

    ps_free(mystr);         // Freed!
    printf("%s\n", global_string);  // BUG: Use after free!
}
```

**Solution:** Track how many references exist. Only free when count reaches zero.

```c
/* Memory Layout with Reference Count:
 * ┌──────────┬──────────┬─────────────────┬───┐
 * │   LLLL   │   CCCC   │ String content  │ 0 │
 * └──────────┴──────────┴─────────────────┴───┘
 *   4 bytes    4 bytes      len bytes      null
 *   (length)  (refcount)
 */
```

This concept is fully developed in Lessons 14-17 with structs.

---

## malloc Error Checking

`malloc` returns `NULL` if allocation fails:

```c
char *s = malloc(size);
if (s == NULL) {
    // Handle out-of-memory condition
    return NULL;
}
```

> **Best Practice:** Always check `malloc` return value in libraries. In application code, the strategy depends on context.

---

## Common Pitfalls

### 1. Forgetting to Free

```c
char *s = ps_create("Hello", 5);
// ... use s ...
// MEMORY LEAK: forgot to call ps_free(s)!
```

### 2. Double Free

```c
ps_free(s);
ps_free(s);  // CRASH or corruption: freeing already-freed memory
```

### 3. Use After Free

```c
ps_free(s);
printf("%s\n", s);  // UNDEFINED BEHAVIOR: memory no longer valid
```

### 4. Freeing Wrong Pointer

```c
char *s = ps_create("Hello", 5);
free(s);      // WRONG: s points 4 bytes into the allocation
ps_free(s);   // RIGHT: ps_free knows to subtract 4
```

---

## Why Dynamic Allocation Matters

With `malloc`, we can:

1. **Create objects that outlive their creating function**
2. **Allocate exactly the memory needed** (no waste)
3. **Build complex data structures** (lists, trees, graphs)
4. **Return objects from functions**

```c
char *create_greeting(const char *name) {
    // Can't use local array - would be destroyed on return
    // Must use malloc!
    char *greeting = malloc(100);
    sprintf(greeting, "Hello, %s!", name);
    return greeting;
}
```

---

## Quick Reference

| Operation | Function | Notes |
|-----------|----------|-------|
| Allocate memory | `malloc(size)` | Returns `NULL` on failure |
| Free memory | `free(ptr)` | Must be same pointer `malloc` returned |
| Get PLS length | `ps_len(s)` | O(1) - reads header |
| Free PLS | `ps_free(s)` | Adjusts pointer before calling `free` |

### PLS Functions Summary

```c
char *ps_create(char *init, int len);  // Create new PLS
void ps_print(char *s);                // Print PLS content
void ps_free(char *s);                 // Free PLS memory
uint32_t ps_len(char *s);              // Get length in O(1)
char *ps_get_c(char *s);               // Get C string pointer (just s!)
```

---

## Code Files

- [`pls.c`](./pls.c) - Basic prefixed-length strings with static buffer
- [`malloc.c`](./malloc.c) - Dynamic allocation version with 4-byte length header
- [`reference_count.c`](./reference_count.c) - Introduction to reference counting concept


*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
