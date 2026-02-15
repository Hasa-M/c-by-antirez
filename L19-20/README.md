# Lessons 19-20 - System Calls and Memory Mapping

**Video Lesson 19:** [POSIX System Calls](https://www.youtube.com/watch?v=QWLJ7CBAu_I&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=22)

**Video Lesson 20:** [Buffering and mmap](https://www.youtube.com/watch?v=yKavhObop5I&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=24)

---

## Overview

These lessons break through the C language boundary into **system programming**. We replace libc functions (`fopen`, `fread`) with raw POSIX system calls (`open`, `read`, `close`), understand why libc uses buffering, and explore `mmap` — a powerful technique to access files through memory pointers.

> *"When we do system programming with POSIX, we reconnect to ancestral computing — the `open` call appeared in AT&T Unix, May 1975."*

---

## User Space vs Kernel Space

A C program runs in **user space** — an isolated memory sandbox. It cannot directly access files, network, or hardware. To interact with the outside world, it must ask the kernel for help via **system calls**.

```
┌─────────────────────────────────────┐
│           USER SPACE                │
│  ┌─────────────────────────────┐    │
│  │   Your C Program            │    │
│  │   - malloc, pointers        │    │
│  │   - can only read/write     │    │
│  │     its own memory          │    │
│  └──────────────┬──────────────┘    │
│                 │ system calls      │
├─────────────────┼───────────────────┤
│           KERNEL SPACE              │
│                 ▼                   │
│  ┌─────────────────────────────┐    │
│  │   OS Kernel                 │    │
│  │   - files, devices, network │    │
│  │   - returns file descriptors│    │
│  └─────────────────────────────┘    │
└─────────────────────────────────────┘
```

The kernel returns a **file descriptor** (an integer) that identifies the open resource. Your program uses this number in subsequent calls.

---

## POSIX System Calls

### open — Open a File

```c
#include <fcntl.h>

int fd = open("file.txt", O_RDONLY);  // Returns file descriptor or -1
```

| Flag | Meaning |
|------|---------|
| `O_RDONLY` | Read only |
| `O_WRONLY` | Write only |
| `O_RDWR` | Read and write |
| `O_APPEND` | Append to end |
| `O_CREAT` | Create if doesn't exist |

Combine flags with `|`: `O_WRONLY | O_APPEND`

### read — Read from File Descriptor

```c
#include <unistd.h>

char buf[32];
ssize_t n = read(fd, buf, sizeof(buf));  // Returns bytes read, 0 = EOF, -1 = error
```

### close — Release File Descriptor

```c
close(fd);  // Tell kernel we're done with this resource
```

### Error Handling

System calls return `-1` on error and set `errno`:

```c
#include <errno.h>

if (fd == -1) {
    perror("open failed");  // Prints: "open failed: No such file or directory"
    return 1;
}
```

---

## Libc vs System Calls

| Aspect | Libc (`fopen`, `fread`) | System Calls (`open`, `read`) |
|--------|-------------------------|-------------------------------|
| Portability | ANSI C — works everywhere | POSIX — Unix/Linux/macOS |
| Buffering | Automatic | Manual |
| Performance | Good for typical use | Best if you manage buffering |
| Complexity | Simple | More control, more responsibility |

---

## Why Libc Buffers

Every system call has overhead (context switch to kernel). Writing one byte at a time would be slow:

```c
// SLOW: one syscall per byte
for (int j = 0; j < len; j++) {
    write(STDOUT_FILENO, &str[j], 1);
}

// FAST: libc buffers internally, fewer syscalls
for (int j = 0; j < len; j++) {
    putchar(str[j]);
}
```

### The Buffering Surprise

```c
printf("hello");  // Goes to buffer, not screen
sleep(5);         // Wait 5 seconds
// "hello" appears AFTER sleep ends!
```

Libc flushes the buffer when:
- Buffer is full
- A newline `\n` is written
- `fflush(stdout)` is called
- Program exits normally

---

## mmap: Memory-Mapped Files

The most powerful technique: map a file directly into memory and access it via pointers.

```c
#include <sys/mman.h>

int fd = open("file.txt", O_RDONLY);
void *mem = mmap(NULL, filesize, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);

char *s = mem;
printf("%c", s[0]);  // First byte of file — no read() needed!
```

### How It Works

1. Kernel sets up virtual memory mapping
2. When you access the pointer, CPU triggers page fault
3. Kernel loads that page from disk into memory
4. Your code continues — it just sees memory

```
┌──────────────────────────────────────────┐
│         Your Process Memory              │
├──────────────────────────────────────────┤
│  0x7fff...  │  Stack                     │
│  ...        │  ...                       │
│  0x1000000  │  mmap'd file ◄──┐          │
│  ...        │  Heap           │          │
└─────────────┴─────────────────┼──────────┘
                                │
                    ┌───────────┴───────────┐
                    │     file.txt          │
                    │     (on disk)         │
                    └───────────────────────┘
```

### mmap Parameters

```c
void *mmap(
    void *addr,     // Desired address (NULL = let kernel choose)
    size_t len,     // Size of mapping
    int prot,       // PROT_READ, PROT_WRITE, PROT_EXEC
    int flags,      // MAP_FILE | MAP_SHARED or MAP_PRIVATE
    int fd,         // File descriptor
    off_t offset    // Offset in file (0 = start)
);
```

**Note:** Returns `MAP_FAILED` (not NULL) on error.

### Why mmap Is Powerful

- **No syscalls** for each read — just pointer access
- **Simplifies code** — treat file as array
- **Optimal performance** — kernel handles caching
- **Great for search** — implement `grep` by scanning memory

---

## File Descriptors 0, 1, 2

Every process starts with three open descriptors:

| FD | Name | Macro | Purpose |
|----|------|-------|---------|
| 0 | stdin | `STDIN_FILENO` | Keyboard input |
| 1 | stdout | `STDOUT_FILENO` | Terminal output |
| 2 | stderr | `STDERR_FILENO` | Error output |

```c
write(STDOUT_FILENO, "hello", 5);  // Write directly to terminal
```

---

## Key Takeaways

1. **System calls** are how your program escapes its memory sandbox

2. **File descriptors** are integers that identify open resources

3. **Libc buffers** for performance — be aware when output appears

4. **Use libc** for portable programs, **syscalls** for control

5. **mmap** is advanced but enables the fastest file access

6. **POSIX standardization** means code works across Unix systems

---

## Quick Reference

| System Call | Purpose | Returns |
|-------------|---------|---------|
| `open(path, flags)` | Open file | fd or -1 |
| `read(fd, buf, n)` | Read bytes | count, 0, or -1 |
| `write(fd, buf, n)` | Write bytes | count or -1 |
| `close(fd)` | Close descriptor | 0 or -1 |
| `mmap(...)` | Map file to memory | pointer or MAP_FAILED |

| Header | Provides |
|--------|----------|
| `<fcntl.h>` | `open`, O_* flags |
| `<unistd.h>` | `read`, `write`, `close`, `sleep` |
| `<sys/mman.h>` | `mmap`, PROT_*, MAP_* |
| `<errno.h>` | `errno`, error codes |

---

## Code Files

- [`sys-stdio.c`](./sys-stdio.c) — Hexdump using raw system calls
- [`stdio.c`](./stdio.c) — Demonstrating libc buffering behavior
- [`map.c`](./map.c) — Memory-mapped file access with mmap


*Notes from Salvatore Sanfilippo's C Programming Course.*
