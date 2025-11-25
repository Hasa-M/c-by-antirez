# Lesson 2: Functions, Variables, and Memory Management in C

## Overview

This lesson is divided into two parts. Part 1 covers C functions, variables, and the basics of how programs execute. Part 2 dives deeper into how memory works at the processor level, using the 6502 and i386 architectures as examples to understand stack-based memory management.

---

## Part 1: Functions and Variables in C

YT Link: https://www.youtube.com/watch?v=Z84vlG1RRtg&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=3

### The `stdio.h` Header

The `stdio.h` header file contains the standard C functions for input and output operations (e.g., `printf`, `scanf`).

<!-- IMPROVEMENT SUGGESTION:
Add a simple diagram showing the relationship between your C code and header files:

```
┌─────────────────┐      #include      ┌──────────────┐
│   your_code.c   │ ◄────────────────► │   stdio.h    │
│                 │                    │  (printf,    │
│  printf("Hi");  │                    │   scanf...)  │
└─────────────────┘                    └──────────────┘
```
-->

### Function Anatomy

A function in C has the following structure:

```c
return_type function_name(parameters) {
    // function body
    return value;
}
```

**Key components:**

- **Return type**: Declared before the function name, indicates what type of value the function returns
- **Parameters (arguments)**: Declared inside parentheses, specify what the function accepts
- **`void` keyword**: Use `void` in the parameter list to explicitly indicate a function takes no arguments

**Example - Sum Function:**

```c
int sum(int a, int b) {
    return a + b;
}

int main(void) {
    return sum(10, 20);
}
```

<!-- IMPROVEMENT SUGGESTION:
Add a visual breakdown of the function anatomy:

```
   return type    function name    parameters
        │              │               │
        ▼              ▼               ▼
       int           sum         (int a, int b)
                                        │
                        ┌───────────────┘
                        ▼
                  function body
                  ┌─────────────┐
                  │ return a+b; │
                  └─────────────┘
```
-->

### Expressions in C

An **expression** is any valid combination of variables, operators, and values that evaluates to a result. For example:

- `a > 10` — a comparison expression (evaluates to `true` or `false`)
- `a + b` — an arithmetic expression
- `x = 5` — an assignment expression

### Enabling Compiler Warnings

Always compile with warnings enabled to catch potential issues:

```bash
gcc -W -Wall file_name.c
```

Warnings alert you to potential problems even when the code is technically compilable. The compiler helps identify issues that could cause runtime errors or unexpected behavior.

<!-- IMPROVEMENT SUGGESTION:
Add a practical example showing what happens with and without warnings:

```c
// Example code with potential issue
int main(void) {
    int x;  // uninitialized variable
    return x;
}
```

Compile without warnings: `gcc example.c` → No output (compiles fine)
Compile with warnings: `gcc -W -Wall example.c` → Warning: 'x' is used uninitialized
-->

### The `printf` Function

`printf` stands for **"print formatted"** — it outputs formatted text to the console.

```c
printf("The sum is: %d\n", result);
```

`printf` is a **variadic function**, meaning it accepts a variable (non-fixed) number of arguments. The first argument is always the format string, followed by zero or more values to substitute into the format placeholders.

<!-- IMPROVEMENT SUGGESTION:
Add a table of common format specifiers:

| Specifier | Description      | Example           |
|-----------|------------------|-------------------|
| %d        | Integer          | printf("%d", 42); |
| %f        | Float            | printf("%f", 3.14);|
| %s        | String           | printf("%s", "Hi");|
| %c        | Character        | printf("%c", 'A'); |
| %%        | Literal %        | printf("100%%");   |
-->

### The `main` Function

The `main` function is special:

- It is the **entry point** of every C program
- The program execution starts from `main`
- A C program **will not compile** without a `main` function
- Unlike other functions, `main` is called by the operating system, not by your code

### Variables in C

**Declaration vs Initialization:**

- **Declaration**: Telling the compiler that a variable exists with a specific type
- **Initialization**: Giving a variable its first value
- **Assignment**: Changing the value of an already-declared variable

```c
int x;          // Declaration only
int y = 10;     // Declaration + Initialization
x = 5;          // Assignment
y = 20;         // Assignment (changing value)
```

**Important:** All variables in C must be **typed** — you must specify the data type when declaring a variable.

<!-- IMPROVEMENT SUGGESTION:
Add a visual memory representation:

```
After: int y = 10;

Memory Address    Value    Variable Name
┌─────────────┬─────────┬──────────────┐
│   0x7fff    │   10    │      y       │
└─────────────┴─────────┴──────────────┘
```
-->

### Local Variables and Function Scope

**Local variables** are:

- Created each time a function is called
- Destroyed when the function returns
- Only accessible within the function where they are declared
- **Function arguments are also local variables**

The memory for local variables is allocated on the **stack** when the function is called and automatically freed when the function returns.

<!-- IMPROVEMENT SUGGESTION:
Add a diagram showing the function call lifecycle:

```
Function called          During execution         Function returns
┌──────────────┐        ┌──────────────┐        ┌──────────────┐
│              │        │  local vars  │        │              │
│    Stack     │   →    │  allocated   │   →    │   memory     │
│    empty     │        │  on stack    │        │   freed      │
└──────────────┘        └──────────────┘        └──────────────┘
```
-->

### Return Value of `main`

The return value of `main` signals to the **operating system** whether the program executed successfully:

- **Return 0**: Program completed successfully
- **Non-zero return**: Program encountered an error

To check the return value of the last executed program in Unix/Linux:

```bash
./a.out; echo $?
```

This prints the exit code of `a.out`.

### Short-Circuit Evaluation

In logical AND (`&&`) operations, C uses **short-circuit evaluation**:

- If the first condition is `false`, the remaining conditions are **not evaluated**
- This is because `false && anything` is always `false`

```c
if (ptr != NULL && ptr->value > 0) {
    // ptr->value is only accessed if ptr is not NULL
}
```

This behavior is commonly used for safe conditional checks and is particularly useful when combined with program exit codes in shell scripts.

---

## Part 2: Memory, Registers, and the Stack

YT Link: https://www.youtube.com/watch?v=r6mU_IHXEps&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=4

### Garbage Collection: JavaScript vs C

In **JavaScript**, a garbage collector automatically manages heap memory — it tracks which objects are no longer referenced and frees them automatically.

**C has no garbage collector.** You are responsible for manually allocating and freeing memory. This gives you more control but also more responsibility to avoid memory leaks.

<!-- IMPROVEMENT SUGGESTION:
Add a comparison diagram:

```
JavaScript:                          C:
┌─────────────────────┐            ┌─────────────────────┐
│  let obj = {...};   │            │  int *p = malloc(); │
│                     │            │                     │
│  obj = null;        │            │  // Must manually:  │
│                     │            │  free(p);           │
│  // GC frees memory │            │                     │
│  // automatically   │            │  // Or memory leaks!│
└─────────────────────┘            └─────────────────────┘
```
-->

### Understanding Microprocessors: The 6502

To understand how C manages memory at a low level, let's examine the **6502 microprocessor** (used in the Commodore 64). Its simplicity makes it an excellent learning tool.

**Reference:** [Easy 6502 Simulator](https://skilldrick.github.io/easy6502/)

### Registers

Microprocessors contain **registers** — small, extremely fast storage locations inside the CPU core itself. Key characteristics:

- Can only hold numbers (typically one word size)
- Much faster to access than RAM
- Limited in number

**Operations with registers:**

1. Load data from RAM into a register
2. Perform computations on register values
3. Store results from a register back to RAM

### CISC vs RISC Architectures

**CISC (Complex Instruction Set Computing):**

- Can address memory directly with complex instructions
- Some operations can move data from RAM to RAM without using registers as intermediaries

**RISC (Reduced Instruction Set Computing):**

- Simpler instructions
- Most operations require loading data into registers first

<!-- IMPROVEMENT SUGGESTION:
Add architecture comparison:

```
CISC (e.g., x86):                    RISC (e.g., ARM):
┌───────────────────────────┐       ┌───────────────────────────┐
│  ADD [mem1], [mem2]       │       │  LOAD R1, [mem1]          │
│  (direct memory-to-memory)│       │  LOAD R2, [mem2]          │
└───────────────────────────┘       │  ADD R1, R2               │
                                    │  STORE R1, [result]       │
                                    └───────────────────────────┘
```
-->

### 6502 Assembly Example

The 6502 has very few registers (A, X, Y). Here's an example program that fills 50 memory locations with the value 5:

```asm
## Print 50 green pixels in sequence on the display

START:
    LDA #50         ; Load the value 50 into register A
    JSR FILL_FIVE   ; Jump to subroutine FILL_FIVE
    BRK             ; Break (end program)

FILL_FIVE:
    TAX             ; Transfer A to X (X = 50, our counter)
    BEQ DONE        ; If zero, skip to DONE
    LDY #$00        ; Load 0 into Y (offset index)
    LDA #$05        ; Load 5 into A (the value to write)
LOOP:
    STA $0200, Y    ; Store A at address $0200 + Y
    INY             ; Increment Y
    DEX             ; Decrement X (counter)
    BNE LOOP        ; If X != 0, continue loop
DONE:
    RTS             ; Return from subroutine
```

**Key instructions explained:**

| Instruction | Meaning |
|-------------|---------|
| `LDA #value` | Load immediate value into A register |
| `TAX` | Transfer A to X |
| `JSR label` | Jump to Subroutine |
| `RTS` | Return from Subroutine |
| `STA addr, Y` | Store A at address + Y offset |
| `INY/DEX` | Increment Y / Decrement X |
| `BEQ/BNE` | Branch if Equal (zero) / Not Equal |

<!-- IMPROVEMENT SUGGESTION:
Add a visual execution trace showing register states:

```
Step | Instruction  | A  | X  | Y  | Notes
-----|--------------|----|----|----|-----------------------
1    | LDA #50      | 50 | -  | -  | Load counter
2    | JSR FILL_FIVE| 50 | -  | -  | Jump to subroutine
3    | TAX          | 50 | 50 | -  | Copy to X as counter
4    | LDY #$00     | 50 | 50 | 0  | Initialize offset
5    | LDA #$05     | 5  | 50 | 0  | Value to write
6    | STA $0200,Y  | 5  | 50 | 0  | Write 5 to $0200
7    | INY          | 5  | 50 | 1  | Next offset
8    | DEX          | 5  | 49 | 1  | Decrement counter
...
```
-->

### The Register Reuse Problem

When a program jumps to another subroutine (like with `JSR`), the registers might be **overwritten** by the new code. If memory isn't managed correctly, the previous values are lost.

This is a fundamental problem: **registers are shared resources**.

### The Stack: Solving Register Conflicts

To solve this problem, processors use a **stack** — a reserved area of memory with Last-In-First-Out (LIFO) behavior.

<!-- IMPROVEMENT SUGGESTION:
Add a clear stack visualization:

```
        Stack Memory (grows downward)
        
High Address
┌─────────────────────┐
│                     │  ← Stack grows downward
├─────────────────────┤
│   Previous Data     │
├─────────────────────┤
│   Saved Register    │
├─────────────────────┤
│   Return Address    │
├─────────────────────┤
│   Local Variable 1  │
├─────────────────────┤
│   Local Variable 2  │  ← SP (Stack Pointer)
├─────────────────────┤
│   (free space)      │
│         ↓           │
│                     │
Low Address
```
-->

### Function Prototypes and Calling Conventions

In C, when you declare a function prototype, the compiler knows **how to call that function** — it just needs the memory address where the function code resides. The prototype tells the compiler:

- What arguments to push onto the stack
- What return type to expect
- The calling convention to use

### i386 Assembly: Stack in Action

Using **Compiler Explorer**, we can see how the C code compiles to i386 assembly:

**C Source:**

```c
int sum(int a, int b) {
    return a + b;
}

int main(void) {
    return sum(10, 20);
}
```

**i386 Assembly:**

```asm
; Parameter offsets from base pointer
_a$ = 8                              ; 'a' is at EBP + 8
_b$ = 12                             ; 'b' is at EBP + 12

_sum    PROC
        push    ebp                  ; Save old base pointer
        mov     ebp, esp             ; Set new base pointer
        mov     eax, DWORD PTR _a$[ebp]   ; Load 'a' into EAX
        add     eax, DWORD PTR _b$[ebp]   ; Add 'b' to EAX
        pop     ebp                  ; Restore old base pointer
        ret     0                    ; Return (result in EAX)
_sum    ENDP

_main   PROC
        push    ebp                  ; Save old base pointer
        mov     ebp, esp             ; Set new base pointer
        push    20                   ; Push second argument
        push    10                   ; Push first argument
        call    _sum                 ; Call sum function
        add     esp, 8               ; Clean up arguments from stack
        pop     ebp                  ; Restore old base pointer
        ret     0
_main   ENDP
```

### Key Registers for Stack Management

| Register | Name | Purpose |
|----------|------|---------|
| **SP** (ESP) | Stack Pointer | Points to the current top of the stack. Contains a memory address (a reference/pointer). |
| **BP** (EBP) | Base Pointer | Points to the base of the current stack frame. Used to access local variables and parameters. |
| **PC** (EIP) | Program Counter | Holds the address of the next instruction to execute. |

### PUSH and POP Operations

- **PUSH**: Saves a register value onto the stack
  - Decrements SP
  - Writes the value at the new SP location
  
- **POP**: Retrieves a value from the stack into a register
  - Reads the value at current SP
  - Increments SP

<!-- IMPROVEMENT SUGGESTION:
Add step-by-step stack visualization for the sum function call:

```
1. Before call:          2. After PUSH 20, 10:    3. After CALL sum:
                                                     (return addr pushed)
┌──────────┐             ┌──────────┐             ┌──────────┐
│          │             │    20    │             │    20    │
│          │             ├──────────┤             ├──────────┤
│          │             │    10    │             │    10    │
│          │ ← SP        ├──────────┤             ├──────────┤
└──────────┘             │          │ ← SP        │ ret addr │
                         └──────────┘             ├──────────┤
                                                  │          │ ← SP
                                                  └──────────┘

4. Inside sum            5. Accessing a, b:
   (after prologue):
                         ┌──────────┐
┌──────────┐             │    20    │ ← EBP+12 (b)
│    20    │             ├──────────┤
├──────────┤             │    10    │ ← EBP+8  (a)
│    10    │             ├──────────┤
├──────────┤             │ ret addr │ ← EBP+4
│ ret addr │             ├──────────┤
├──────────┤             │ old EBP  │ ← EBP
│ old EBP  │ ← EBP       ├──────────┤
├──────────┤             │          │ ← ESP
│          │ ← ESP       └──────────┘
└──────────┘
```
-->

### Stack Frame Lifecycle

1. **Function prologue**: Save old BP, set up new stack frame
2. **Allocate locals**: Reserve space on stack for local variables
3. **Execute function**: Access parameters via BP offsets
4. **Function epilogue**: Restore old BP, return

### Conclusion: What Are Local Variables Really?

At the hardware level, **local variables in C** are either:

1. **Values stored in CPU registers** (for optimization/speed)
2. **Temporary values stored on the stack** (for persistence across function calls)

The stack provides the mechanism for:
- Saving register values before calling other functions
- Passing arguments to functions
- Storing local variables
- Keeping track of return addresses

---

## Code Files Reference

### c_source.c

```c
int sum(int a, int b) {
    return a + b;
}

int main(void) {
    return sum(10, 20);
}
```

### 6502_program.s

See the [6502 Assembly Example](#6502-assembly-example) section above.

### i386_program.s

See the [i386 Assembly: Stack in Action](#i386-assembly-stack-in-action) section above.

---

## Resources

- [Easy 6502 Simulator](https://skilldrick.github.io/easy6502/) — Interactive 6502 assembly learning tool
- [Compiler Explorer (Godbolt)](https://godbolt.org/) — See how C code compiles to assembly

---

## Summary

| Concept | Key Takeaway |
|---------|--------------|
| Functions | Have return type, name, and parameters. Use `void` for no parameters. |
| `main` | Entry point of C programs. Returns 0 for success. |
| Variables | Must be typed. Declared, then initialized or assigned. |
| Local Variables | Created on stack when function called, destroyed on return. |
| Registers | Fast CPU storage, limited quantity, shared resource. |
| Stack | LIFO memory structure for local vars, return addresses, saved registers. |
| SP/BP | Stack Pointer tracks top of stack; Base Pointer accesses local data. |
| PUSH/POP | Save/restore register values to/from stack. |

---

## Improvement Suggestions Summary

To enhance this lesson, consider adding:

1. **Visual diagrams** for:
   - Function anatomy breakdown
   - Memory representation of variables
   - Stack frame layout and evolution
   - CISC vs RISC comparison
   - Garbage collection comparison (JS vs C)

2. **Interactive elements**:
   - Link to Easy 6502 with pre-loaded example code
   - Compiler Explorer link with the sum function pre-loaded

3. **Practical exercises**:
   - Modify the sum function to take 3 parameters and trace the stack
   - Write a simple 6502 program that uses all three registers
   - Use `gcc -S` to generate assembly from your own C code and analyze it

4. **Additional explanations**:
   - More format specifiers for `printf`
   - Common warning messages and what they mean
   - Stack overflow explanation and example

5. **Video timestamps**: Add timestamps for each major topic in the video links so readers can jump to specific sections.


## Reference
Notes refined through AI with human review. Model: Opus 4.5
