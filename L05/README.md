# Lesson 05 - Strings and Arrays

**Video:** [Watch on YouTube](https://www.youtube.com/watch?v=SWWHqgSwQFw&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=6)

---

## Overview

This lesson reveals one of C's fundamental truths: **strings are just arrays of integers**. We explore character literals, arrays, and the null terminator that makes C strings work.

---

## Character Literals

In C, single quotes create a **character literal** — an integer representing an ASCII value:

```c
char c = 'A';           // c = 65 (ASCII value of 'A')
printf("%d\n", c);      // prints: 65
printf("%c\n", 65);     // prints: A
```

**Key difference from Python:**
- `'A'` → Single character (integer)
- `"A"` → String (array of chars)

```c
printf("%c %c %c %c\n", 65, 66, 67, 68);  // prints: A B C D
printf("%c %c %c %c\n", 'A', 'B', 'C', 'D');  // same thing
```

---

## Arrays

Arrays are declared with square brackets and initialized with curly braces:

```c
int a[5] = {10, 5, 50, 100, 7};

printf("%d\n", a[0]);   // 10
printf("%d\n", a[1]);   // 5
printf("%d\n", a[2]);   // 50
```

**Indexing starts at 0** — same as most languages that came after C.

---

## Strings Are Char Arrays

**The big revelation:** C strings are simply arrays of `char` terminated by a zero byte (NUL terminator):

```c
char s[6] = {'H', 'e', 'l', 'l', 'o', 0};  // Manual way
char str[] = "hello";                       // Shorthand (compiler adds the 0)
```

Both create the same thing in memory:

```
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ 'H' │ 'e' │ 'l' │ 'l' │ 'o' │  0  │
│ 72  │ 101 │ 108 │ 108 │ 111 │  0  │
└─────┴─────┴─────┴─────┴─────┴─────┘
  [0]   [1]   [2]   [3]   [4]   [5]
```

---

## The NUL Terminator

C strings have **no length header** — the only way to know where a string ends is the NUL terminator (`0` or `'\0'`).

```c
// Without terminator — DANGEROUS
char bad[2] = {'a', 'b'};  // No terminator!
printf("%s\n", bad);        // Prints garbage until it finds a 0 in memory
```

> **Warning:** Forgetting the NUL terminator causes `printf` to read past your array into random memory.

---

## Implementing printf's %s

We can print a string character by character using `%c`:

```c
char s[] = "hello";
int i = 0;

while (s[i] != 0) {
    printf("%c", s[i]);
    i++;
}
printf("\n");
```

This is essentially what `printf("%s", s)` does internally.

---

## Strings Are Mutable

Since strings are arrays, you can modify individual characters:

```c
char str[] = "hello";
str[3] = 'X';           // "helXo"
str[1] = 65;            // "hAXo" (65 = 'A')
str[0]++;               // "iAXo" ('h' + 1 = 'i')

printf("%s\n", str);
```

---

## sizeof at Compile Time

`sizeof` is evaluated at **compile time**, not runtime — it's free:

```c
char str[] = "hello";
printf("%lu\n", sizeof(str));  // 6 (includes NUL terminator)
```

The compiler replaces `sizeof(str)` with `6` before the program runs.

---

## Quick Reference

| Syntax | Meaning |
|--------|---------|
| `'A'` | Character literal (integer 65) |
| `"A"` | String literal (array: `{'A', 0}`) |
| `\0` | NUL terminator (same as `0`) |
| `%c` | Print as character |
| `%s` | Print as string |
| `%d` | Print as integer |

```c
// Array declaration
int arr[5] = {1, 2, 3, 4, 5};      // Integer array
char str[] = "hello";              // String (size inferred)
char str[10] = "hello";            // String with extra space
```

---

## Code Files

- [`string.c`](./string.c) — String and array examples

<!-- IMPROVEMENTS: Add memory diagram showing what happens without NUL terminator -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
