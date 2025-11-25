# Lesson 2: Functions, Variables, and Memory Management in C

## Part 1: Functions and Variables in C

**YT Link:** https://www.youtube.com/watch?v=Z84vlG1RRtg&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=3

### The `stdio.h` Header

Contains standard C functions for input/output operations (`printf`, `scanf`, etc.).

### Function Anatomy

```c
return_type function_name(parameters) {
    // function body
    return value;
}
```

- **Return type**: What the function returns (declared before the name)
- **Parameters**: What the function accepts (inside parentheses)
- **`void`**: Use to explicitly indicate no parameters

### Expressions

Any combination of variables, operators, and values that evaluates to a result: `a > 10`, `a + b`, `x = 5`.

### Compiler Warnings

```bash
gcc -W -Wall file_name.c
```

Always compile with warnings enabled — they catch potential issues even in compilable code.

### The `printf` Function

**"Print formatted"** — a variadic function (accepts variable number of arguments).

```c
printf("Sum: %d\n", result);
```

| Specifier | Type      | Example              |
|-----------|-----------|----------------------|
| `%d`      | Integer   | `printf("%d", 42);`  |
| `%f`      | Float     | `printf("%f", 3.14);`|
| `%s`      | String    | `printf("%s", "Hi");`|
| `%c`      | Character | `printf("%c", 'A');` |

### The `main` Function

- Entry point of every C program
- Called by the OS, not by your code
- Program won't compile without it
- Returns `0` for success, non-zero for error

```bash
./a.out; echo $?    # prints exit code
```

### Variables

```c
int x;          // Declaration
int y = 10;     // Declaration + Initialization
x = 5;          // Assignment
```

All variables in C must be **typed**.

### Local Variables

- Created when function is called, destroyed when it returns
- Only accessible within the declaring function
- **Function arguments are local variables**
- Stored on the **stack**

### Short-Circuit Evaluation

In `&&` operations, if the first condition is `false`, the rest are **not evaluated**.

```c
if (ptr != NULL && ptr->value > 0)  // Safe: ptr->value only accessed if ptr != NULL
```

---

## Part 2: Memory, Registers, and the Stack

**YT Link:** https://www.youtube.com/watch?v=r6mU_IHXEps&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=4

### Garbage Collection: JavaScript vs C

JavaScript has automatic garbage collection. **C does not** — you manually manage memory.

### Registers

Small, extremely fast storage locations inside the CPU core:

- Hold single values (one word size)
- Much faster than RAM
- Limited quantity (shared resource)

### CISC vs RISC

- **CISC** (x86): Complex instructions, can do memory-to-memory operations
- **RISC** (ARM): Simple instructions, requires load/store through registers

### 6502 Assembly Example 1

Reference: [Easy 6502 Simulator](https://skilldrick.github.io/easy6502/)

```asm
START:
    LDA #50         ; Load 50 into A
    JSR FILL_FIVE   ; Jump to subroutine
    BRK

FILL_FIVE:
    TAX             ; Transfer A to X (counter)
    BEQ DONE        ; If zero, done
    LDY #$00        ; Y = 0 (offset)
    LDA #$05        ; A = 5 (value to write)
LOOP:
    STA $0200, Y    ; Store A at $0200 + Y
    INY             ; Y++
    DEX             ; X--
    BNE LOOP        ; Loop if X != 0
DONE:
    RTS             ; Return
```

### The Register Reuse Problem

When jumping to a subroutine, registers may be **overwritten**. The solution: use a **stack**.

### The Stack

A reserved memory area with **LIFO** (Last-In-First-Out) behavior. Key registers:

| Register | Name           | Purpose                                    |
|----------|----------------|--------------------------------------------|
| **SP**   | Stack Pointer  | Points to current top of stack             |
| **BP**   | Base Pointer   | Points to base of current stack frame      |
| **PC**   | Program Counter| Address of next instruction to execute     |

**Operations:**

- **PUSH**: Decrement SP, write value at new SP location
- **POP**: Read value at SP, increment SP

### i386 Assembly Example: `sum(10, 20)`

Using [Compiler Explorer](https://godbolt.org/), we can see how the C code compiles to i386 assembly.

**C Source (`c_source.c`):**

```c
int sum(int a, int b) {
    return a + b;
}

int main(void) {
    return sum(10, 20);
}
```

**i386 Assembly (`i386_program.s`):**

```asm
_a$ = 8                                 ; offset for parameter 'a' from EBP
_b$ = 12                                ; offset for parameter 'b' from EBP

_sum    PROC
        push    ebp                     ; save caller's base pointer
        mov     ebp, esp                ; set up new stack frame
        mov     eax, DWORD PTR _a$[ebp] ; eax = *(ebp + 8) → load 'a'
        add     eax, DWORD PTR _b$[ebp] ; eax += *(ebp + 12) → add 'b'
        pop     ebp                     ; restore caller's base pointer
        ret     0                       ; return (result in eax)
_sum    ENDP

_main   PROC
        push    ebp                     ; save base pointer
        mov     ebp, esp                ; set up stack frame
        push    20                      ; push second argument (b)
        push    10                      ; push first argument (a)
        call    _sum                    ; call sum, pushes return address
        add     esp, 8                  ; clean up: remove 2 arguments (4 bytes each)
        pop     ebp                     ; restore base pointer
        ret     0
_main   ENDP
```

**Line-by-line breakdown:**

| Line | Instruction | What it does |
|------|-------------|--------------|
| 5 | `push ebp` | Saves `main`'s base pointer onto the stack |
| 6 | `mov ebp, esp` | EBP now points to current stack position (new frame base) |
| 7 | `mov eax, [ebp+8]` | Loads argument `a` (value 10) into EAX |
| 8 | `add eax, [ebp+12]` | Adds argument `b` (value 20) to EAX → EAX = 30 |
| 9 | `pop ebp` | Restores the old EBP value |
| 10 | `ret 0` | Pops return address into PC, jumps back to `main` |

**Why EBP+8 and EBP+12?**

Each stack slot is 4 bytes (32-bit architecture). From EBP:
- `EBP + 0` → saved old EBP
- `EBP + 4` → return address
- `EBP + 8` → first argument (`a` = 10)
- `EBP + 12` → second argument (`b` = 20)
- 

### Stack Visualization: `sum(10, 20)` Call

```
    STACK MEMORY (grows downward toward lower addresses)
    
    High Address
    ┌────────────────────────────────────────┐
    │              ...                       │
    ├────────────────────────────────────────┤
    │         20 (argument b)                │  ← EBP + 12
    ├────────────────────────────────────────┤
    │         10 (argument a)                │  ← EBP + 8
    ├────────────────────────────────────────┤
    │        Return Address (PC)             │  ← EBP + 4
    ├────────────────────────────────────────┤
    │    Saved EBP (main's base pointer)     │  ← EBP (current)
    ├────────────────────────────────────────┤
    │    (local variables would go here)     │  ← ESP (top of stack)
    ├────────────────────────────────────────┤
    │              ...                       │
    └────────────────────────────────────────┘
    Low Address
```




### Conclusion

**Local variables in C** are either:

1. Values stored in **CPU registers** (optimized for speed)
2. Temporary values on the **stack** (for persistence across calls)

---

## Resources

- [Easy 6502 Simulator](https://skilldrick.github.io/easy6502/)
- [Compiler Explorer (Godbolt)](https://godbolt.org/)

## Code Files

- `c_source.c` — Simple sum function example
- `6502_program.s` — 6502 assembly pixel fill
- `i386_program.s` — x86 assembly output from Compiler Explorer

## Reference
Notes refined through AI with human review. Model: Opus 4.5
