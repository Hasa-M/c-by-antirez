# Lesson 3: Variable Scope, Pass by Value, and C Types

**YT Link:** https://www.youtube.com/watch?v=YNsXyasn4R4&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=4

---

## Side Effects

A **side effect** is when a function does something observable (like printing) without returning a functional value.

```c
void incrVoid(void) {
    int x = 0;
    x = x + 1;
    printf("X: %d\n", x);
}
```

This function returns `void` — it has no return value, but it *does something* (prints to screen).

### Quick Note: `=` vs `==`

- `=` → **Assignment** (sets a value)
- `==` → **Comparison** (checks equality)

C is an **imperative language** — you give the computer a sequence of commands to execute.

---

## Variable Scope

### Local Variables: The Problem

```c
void incrVoid(void) {
    int x = 0;
    x = x + 1;
    printf("X: %d\n", x);
}

int main(void) {
    incrVoid();  // prints 1
    incrVoid();  // prints 1
    incrVoid();  // prints 1
}
```

**Always prints 1.** Why? `x` is **local** — created fresh each time the function is called, destroyed when it returns.

### Global Variables: Persistent State

```c
int x = 0;  // Global

void incrVoid(void) {
    x = x + 1;
    printf("X: %d\n", x);
}

int main(void) {
    incrVoid();  // prints 1
    incrVoid();  // prints 2
    incrVoid();  // prints 3
}
```

**Now it increments.** Global variables:

- Created at program start
- Exist for the entire program duration
- Accessible from any function

**Scope resolution:** The compiler first looks for `x` locally. If not found, it searches the global scope.

### Static Variables: Best of Both Worlds

```c
void incrVoid(void) {
    static int x = 0;  // Initialized once, persists between calls
    x = x + 1;
    printf("X: %d\n", x);
}
```

`static` inside a function means:

- **Global lifetime** (persists between calls)
- **Local visibility** (only accessible within the function)

If another function tries to access `x`, the program **won't compile**.

---

## Pass by Value

### The Default Behavior

```c
int incrInt(int x) {
    x = x + 1;
    return x;
}

int main(void) {
    int a = 10;
    incrInt(a);
    printf("A: %d\n", a);  // prints 10 — unchanged!
}
```

`a` is still 10 because C passes arguments **by value** — the function receives a *copy*, not the original.

### To Modify the Original: Reassign

```c
int main(void) {
    int a = 10;
    a = incrInt(a);  // a = 11
    a = incrInt(a);  // a = 12
    printf("A: %d\n", a);  // prints 12
}
```

### Pass by Reference: Only with Pointers

C is entirely pass-by-value. The **only way** to pass by reference is through **pointers** (covered in later lessons).

This applies to everything in C, including structs.

---

## C Data Types

### Basic Types

| Type | Size (typical) | Range | Notes |
|------|----------------|-------|-------|
| `char` | 1 byte | -128 to 127 | Often used for characters |
| `unsigned char` | 1 byte | 0 to 255 | |
| `short` | 2 bytes | -32,768 to 32,767 | Size not guaranteed by spec |
| `int` | 4 bytes | ≈ ±2 billion | |
| `float` | 4 bytes | ≈ ±3.4 × 10³⁸ | ~7 decimal digits precision |
| `double` | 8 bytes | ≈ ±1.7 × 10³⁰⁸ | ~15 decimal digits precision |


### Floating Point Representation

`float` (fp32) uses **mantissa + exponent** representation:

```
[sign: 1 bit][exponent: 8 bits][mantissa: 23 bits]
```

### Format Specifiers Matter

```c
float y = 1.234;
printf("Y: %.3f\n", y);  // Correct: prints "1.234"
```

Using the **wrong specifier** compiles but prints garbage. The compiler doesn't check format string correctness at runtime.

| Type | Specifier |
|------|-----------|
| `int` | `%d` |
| `float` / `double` | `%f` |
| `char` | `%c` |
| `char` as number | `%d` |

---

## Type Promotion and Overflow

### Automatic Type Promotion

C automatically promotes types in certain contexts:

**In variadic functions (like `printf`):**
- `short` → `int`
- `float` → `double`

**In expressions:**
- Smaller types are promoted to larger types when mixed

### Signed Overflow: Undefined Behavior

```c
char c = 127;
c++;  // UNDEFINED — could be -128, could be anything
```

Signed integer overflow is **not defined** by the C standard. Don't rely on any specific behavior.

### Unsigned Overflow: Defined Wraparound

```c
unsigned char c = 255;
c++;  // c = 0 (wraps around)
```

Unsigned integers **wrap around** predictably: 255 + 1 = 0.

### The `++` Operator

```c
x++;      // Increment x by 1 (same as x = x + 1)
++x;      // Also increments, but returns the new value
```

---

## Code Example

```c
#include 

void incrVoid(void) {
    static int x = 0;
    x = x + 1;
    printf("X: %d\n", x);
}

int incrInt(int x) {
    x = x + 1;
    return x;
}

int main(void) {
    // Static variable demonstration
    incrVoid();  // X: 1
    incrVoid();  // X: 2
    incrVoid();  // X: 3

    // Pass by value demonstration
    int a = 10;
    incrInt(a);
    printf("A: %d\n", a);  // A: 10 (unchanged)

    a = incrInt(a);  // a = 11
    a = incrInt(a);  // a = 12
    printf("A: %d\n", a);  // A: 12

    // Types demonstration
    float y = 1.234;
    char c = 128;  // Overflow! 128 > 127 (max signed char)
    printf("Y: %.3f - C: %c\n", y, c);

    return 0;
}
```

---

## Summary

| Concept | Key Point |
|---------|-----------|
| Side effect | Function does something without returning a value |
| Local variable | Created on call, destroyed on return |
| Global variable | Exists for entire program, accessible everywhere |
| `static` in function | Persistent like global, visible only locally |
| Pass by value | Functions receive copies, not originals |
| Pass by reference | Only possible with pointers |
| Signed overflow | Undefined behavior — avoid it |
| Unsigned overflow | Wraps around (255 + 1 = 0) |

---

## Resources
- Use an LLM as an "evolved Stack Overflow" for quick answers to C questions
