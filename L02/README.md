# Lesson 02 - Functions, Variables, and Memory Management

**Video Part 1:** [Functions and Variables](https://www.youtube.com/watch?v=Z84vlG1RRtg&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=3)

**Video Part 2:** [Memory, Registers, and the Stack](https://www.youtube.com/watch?v=r6mU_IHXEps&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=4)

---

## Overview

This lesson covers function definition and calling conventions, variable declaration and scope, and dives deep into how C manages memory through registers and the stack.

---

## Part 1: Functions and Variables

### Function Anatomy

```c
return_type function_name(parameters) {
    // function body
    return value;
}
```

```c
int sum(int a, int b) {
    int c = a + b;
    return c;
}
```

- **Return type** comes before the function name
- **Parameters** are comma-separated with their types
- **`void`** explicitly indicates no parameters: `int main(void)`

### The `main` Function

`main` is special — it's the program entry point called by the OS:

```c
int main(void) {
    // program code
    return 0;    // 0 = success, non-zero = error
}
```

```bash
./a.out; echo $?    # prints exit code (0 or error number)
./a.out && ls       # ls runs only if a.out returns 0
```

### Variables and Expressions

```c
int a = 10;         // Declaration + initialization
int b;              // Declaration only
b = 20;             // Assignment
int c = a + b;      // Expression in initialization
```

**Expressions** can appear in: `return`, assignments, conditions (`if`, `while`), etc.

### The `printf` Function

"Print formatted" — a variadic function accepting variable arguments:

```c
printf("Sum: %d and %d\n", 30, 50);   // %d = integer placeholder
```

> **Warning:** Mismatched format specifiers and arguments cause undefined behavior.

### Local Variables

Variables declared inside a function are **local** — created when the function is called, destroyed when it returns:

```c
int sum(int a, int b) {   // a, b are local (parameters)
    int c = a + b;         // c is also local
    return c;
}   // a, b, c are destroyed here
```

### Compiler Warnings

```bash
gcc -W -Wall file.c    # Enable warnings — always use these!
```

---

## Part 2: Memory, Registers, and the Stack

### Why This Matters

In high-level languages (JavaScript, Python), garbage collection handles variable cleanup. In C, understanding **where** variables live explains their lifecycle.

### Registers

Small, fast storage locations inside the CPU:

```
┌─────────────────────────────────────────────────────────┐
│                      CPU CORE                           │
│  ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐                       │
│  │ EAX │ │ EBX │ │ ECX │ │ EDX │  ← General registers  │
│  └─────┘ └─────┘ └─────┘ └─────┘                       │
│  ┌─────┐ ┌─────┐ ┌─────┐                               │
│  │ ESP │ │ EBP │ │ EIP │  ← Special registers          │
│  └─────┘ └─────┘ └─────┘                               │
└─────────────────────────────────────────────────────────┘
```

- **Very fast** but limited in number
- Can be overwritten by any function call
- This is why local variables "disappear"

### The Stack

A reserved memory area using **LIFO** (Last-In-First-Out) operations:

| Register | Name | Purpose |
|----------|------|---------|
| **SP/ESP** | Stack Pointer | Points to current top of stack |
| **BP/EBP** | Base Pointer | Points to base of current stack frame |
| **PC/EIP** | Program Counter | Address of next instruction |

**Operations:**
- **PUSH**: Decrement SP, write value
- **POP**: Read value, increment SP

### Stack Frame: `sum(10, 20)` Call

```c
int sum(int a, int b) { return a + b; }
int main(void) { return sum(10, 20); }
```

```
    STACK (grows downward)
    
    High Address
    ┌────────────────────────────┐
    │         20 (b)             │  ← EBP + 12
    ├────────────────────────────┤
    │         10 (a)             │  ← EBP + 8
    ├────────────────────────────┤
    │    Return Address (PC)     │  ← EBP + 4
    ├────────────────────────────┤
    │    Saved EBP (old base)    │  ← EBP points here
    ├────────────────────────────┤
    │   (local vars go here)     │  ← ESP (top of stack)
    └────────────────────────────┘
    Low Address
```

**Why EBP+8 and EBP+12?** Each slot is 4 bytes (32-bit). EBP+0 = saved EBP, EBP+4 = return address, then arguments follow.

### i386 Assembly Example

```asm
_sum    PROC
        push    ebp                 ; Save caller's base pointer
        mov     ebp, esp            ; Set up new stack frame
        mov     eax, [ebp+8]        ; Load argument 'a' into EAX
        add     eax, [ebp+12]       ; Add argument 'b' to EAX
        pop     ebp                 ; Restore old base pointer
        ret                         ; Return (result in EAX)
_sum    ENDP
```

### Local Variables: The Reality

Local variables in C are either:
1. **Registers** — temporary, overwritten by next function call
2. **Stack memory** — deallocated when function returns

This is why they "disappear" — the memory is reused for the next function call.

---

## Quick Reference

```bash
gcc -W -Wall file.c       # Compile with warnings
gcc -S file.c             # Generate assembly
./a.out; echo $?          # Check exit code
./a.out && next_cmd       # Run next_cmd only on success
```

---

## Code Files

- [`sum.c`](./sum.c) — Function example
- [`c_source.c`](./c_source.c) — Simple sum for assembly analysis
- [`6502_program.s`](./6502_program.s) — 6502 assembly example
- [`i386_program.s`](./i386_program.s) — x86 assembly from Compiler Explorer

## Resources

- [Easy 6502 Simulator](https://skilldrick.github.io/easy6502/)
- [Compiler Explorer (Godbolt)](https://godbolt.org/)

<!-- IMPROVEMENTS: Add animated GIF of stack operations, diagram showing register lifecycle -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
