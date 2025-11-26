# Lesson 01 - Introduction to C and the Compiler

**Video:** https://www.youtube.com/watch?v=HjXBXBgfKyk&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=1

## Lesson Contents

### 1. Course and C Language Presentation
   - General introduction to the course
   - C language characteristics
   - Course objectives

### 2. The Compiler and Hello World
   - `cc filename.c` - code compilation
   - `./a.out` - binary file execution
   - `a.out` - output binary file

### 3. Compiler Options
   - `-S` - display generated assembly code
   - `-O2` - compiler optimization level 2
   - Translation process from C to assembly

### 4. `man` Command and Documentation
   - `man fn_name` - display function manual
   - `man` - manual for shell commands
   - `man 3` - manual for C functions

### 5. Preprocessor Directives
   - What preprocessor directives are
   - `#include` - file inclusion
   - Role of the preprocessor in compilation

### 6. Language vs Library
   - Quick explanation between language and library
   - Some C language keywords

### 7. `.c` and `.h` Files
   - `.c` - files containing logic and execution code
   - `.h` - header files, general code to include
   - Both `.c` and `.h` can be included with `#include`

### 8. Function Prototypes
   - Function prototype definition
   - How the compiler uses prototypes

## Code Files

- `hello.c` - First Hello World program

## Notes

This lesson introduces fundamental concepts of C and the compilation process. It's important to understand the difference between compilation and execution, and how the compiler translates C code into machine language through assembly.

## Useful Commands
```bash
# Basic compilation
cc hello.c

# Execution
./a.out

# View assembly
cc -S hello.c
cat hello.s

# Optimized compilation
cc -O2 hello.c

# Consult manual
man 3 printf
```

## Resources

- Notes refined through AI with human review. Model: Opus 4.5
