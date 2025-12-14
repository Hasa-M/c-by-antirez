# Lessons 06-07 - Control Flow: Conditionals, Loops, and Recursion

**Video Lesson 6:** [Watch on Youtube](https://www.youtube.com/watch?v=lc7aYXNl1T8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=8)

**Video Lesson 7:** [Watch on Youtube](https://www.youtube.com/watch?v=HCRthhjbfAg&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=9)

---

## Overview

These lessons cover C's control flow: conditionals (`if`, `switch`), loops (`while`, `for`, `do-while`), blocks, `goto`, and recursion with tail call optimization.

---

## Conditionals and Blocks

```c
if (i > 3) {
    printf("i > 3\n");
} else if (i == 3) {
    printf("i is 3\n");
} else {
    printf("i < 3\n");
}
```

Braces optional for single statements. In C: **0 = false**, **non-zero = true**.

**Blocks create scope** — variables inside don't exist outside:

```c
int i = 8;
{
    int i = 5;                    // Shadows outer i
    printf("Inner: %d\n", i);     // 5
}
printf("Outer: %d\n", i);         // 8
```

---

## Labels and `goto`

```c
int i = 0;
again:
    printf("%d\n", i++);
    if (i < 10) goto again;
```

Understanding `goto` reveals that loops are structured jumps. Labels must start with a letter.

---

## Loop Constructs

### `while`

```c
while (i < 10) {
    printf("%d\n", i++);
}
```

`while(1)` = infinite loop.

### `for` — Syntactic sugar for `while`

```c
for (int i = 0; i < 10; i++) printf("%d\n", i);
```

**Three parts:** `for (init; condition; increment)` — all optional.

**Scope:** Variables declared in `for` don't exist after it. Declare outside if needed later.

### `do-while` — Executes at least once

```c
do { printf("%d\n", i++); } while (i < 10);
```

### `break` — Exit innermost loop

```c
for (i = 0; a[i] != 0; i++)
    if (a[i] == 8) break;
// Check i after to know if found
```

---

## `switch` Statement

```c
switch (i) {
    case 5:
        printf("Five\n");
        break;              // Without break → fall-through!
    case 7: {
        int x = 10;         // Block needed for variables
        printf("%d\n", x);
        break;
    }
    default:
        printf("Other\n");
}
```

---

## Recursion and Tail Call Optimization

```c
void count(int start, int end) {
    if (start > end) return;      // Base case
    printf("%d\n", start);
    count(start + 1, end);        // Each call = new stack frame
}
```

**Problem:** Stack grows with each call. **Solution** — convert tail calls to iteration:

```c
void count_tco(int start, int end) {
iterate:
    if (start > end) return;
    printf("%d\n", start++);
    goto iterate;    // Same frame, no memory growth
}
```

Only works when recursion is the **last operation**.

---

## Quick Reference

| Construct | Purpose |
|-----------|---------|
| `if / else` | Conditional branching |
| `while (cond)` | Loop while true |
| `for (i;c;u)` | Loop with counter |
| `do {} while` | Loop at least once |
| `switch` | Multi-way branching |
| `break` | Exit loop/switch |
| `goto` | Jump to label |

---

## Code Files

- [`condizioni_cicli_L6.c`](./condizioni_cicli_L6.c) — Conditionals, blocks, goto, while, recursion
- [`condizioni_cicli_L7.c`](./condizioni_cicli_L7.c) — TCO, for, do-while, switch

<!-- IMPROVEMENTS: Add flowchart for loop selection, diagram comparing recursion stack vs TCO -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
