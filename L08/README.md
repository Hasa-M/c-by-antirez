# Lesson 08 - Practical Exercise: Conway's Game of Life

**Video:** [Watch on YouTube](https://www.youtube.com/watch?v=c5atNuYdKK8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=9)

---

## Overview

This lesson is different from previous ones — instead of introducing new concepts, we apply everything learned so far to build a complete program: **Conway's Game of Life**. This cellular automaton, invented by mathematician John Conway in 1970, demonstrates how simple rules can generate complex, emergent behavior.

> **Warning:** This program uses "odd" C code because it's an example using just a subset of things learned so far in the course. Sanfilippo explicitly notes this limitation.

---

## What We're Building

The Game of Life is a zero-player game that simulates cellular evolution on a 2D grid. Each cell can be **alive** (`*`) or **dead** (`.`), and the next generation is computed using four simple rules.

```
Generation 0          Generation 1          Generation 2
. . . . .             . . . . .             . . . . .
. . * . .             . . . . .             . . * . .
. . * . .     →       . * * * .     →       . . * . .
. . * . .             . . . . .             . . * . .
. . . . .             . . . . .             . . . . .
```

---

## The Rules

A cell's next state depends on its **8 neighbors** (horizontally, vertically, and diagonally adjacent):

```
┌───┬───┬───┐
│NW │ N │NE │
├───┼───┼───┤
│ W │ X │ E │    X = current cell
├───┼───┼───┤    8 neighbors surround it
│SW │ S │SE │
└───┴───┴───┘
```

| Current State | Living Neighbors | Next State | Reason |
|---------------|------------------|------------|--------|
| **Alive** | < 2 | Dead | Underpopulation |
| **Alive** | 2 or 3 | Alive | Survival |
| **Alive** | > 3 | Dead | Overpopulation |
| **Dead** | = 3 | Alive | Reproduction |

---

## Problem Decomposition

Sanfilippo emphasizes that in C, you first write functions that "raise the level" of the language to match your problem domain. This lesson demonstrates building **abstraction layers**:

### Program Structure

```c

// Layer 1: Coordinate translation with wrapping
int cell_to_index(int x, int y);

// Layer 2: Grid access
void set_cell(char *grid, int x, int y, int state);
char get_cell(char *grid, int x, int y);

// Layer 3: Grid operations
void set_grid(char *grid, char state);
void print_grid(char *grid);
int count_living_neighbors(char *grid, int x, int y);

// Layer 4: Game logic
void new_state(char *old, char *new);

// Application
int main(void);
```

---


## Key Implementation Details

### 2D to 1D Array Mapping

We store a 2D grid in a 1D array. The formula to convert coordinates:

```
index = y * GRID_COLS + x
```

```
2D Grid (3x3):              1D Array:
┌───┬───┬───┐
│0,0│1,0│2,0│               [0][1][2][3][4][5][6][7][8]
├───┼───┼───┤                 ↑        ↑        ↑
│0,1│1,1│2,1│               y=0      y=1      y=2
├───┼───┼───┤
│0,2│1,2│2,2│
└───┴───┴───┘

Example: (x=1, y=2) → index = 2 * 3 + 1 = 7
```

### Toroidal Wrapping

The grid wraps around — going off one edge brings you to the opposite side:

```
Grid wrapping (x-axis):
... [18][19]│[0][1][2]...│[0][1][2] ...
            │← actual →│
            │   grid   │
            
x = -1  →  becomes  →  x = GRID_COLS - 1
x = 20  →  becomes  →  x = 0
```

This is implemented using modulo arithmetic:
- Positive overflow: `x = x % GRID_COLS`
- Negative values: `x = GRID_COLS - ((-x) % GRID_COLS)`

### Double Buffering

We need two grids: one for the current state, one for computing the next. If we modified cells in-place, later calculations would see partially-updated data:

```c
char old_grid[GRID_CELLS];  // Current generation
char new_grid[GRID_CELLS];  // Next generation (being computed)
```

---

## New Concept: `continue`

This lesson introduces `continue` for the first time — it skips to the next loop iteration:

```c
for (int xOffset = -1; xOffset <= 1; xOffset++) {
    for (int yOffset = -1; yOffset <= 1; yOffset++) {
        if (xOffset == 0 && yOffset == 0)
            continue;  // Skip the cell itself, only check neighbors
        // ... check neighbor
    }
}
```

---
 
## Animation Loop

The main loop alternates between two grids and uses `usleep()` for timing:

```c
while (1) {
    new_state(old_grid, new_grid);
    print_grid(new_grid);
    usleep(100000);  // 100ms delay
    
    new_state(new_grid, old_grid);
    print_grid(old_grid);
    usleep(100000);
}
```

---

## VT100 Escape Sequences

Terminal screen clearing uses escape sequences:

```c
printf("\x1b[3J\x1b[H\x1b[2J");
//      │      │      └── Clear entire screen
//      │      └── Move cursor to home (top-left)
//      └── Clear scrollback buffer
```

---

## Key Takeaways

1. **Abstraction layers** — Build low-level utilities first, then use them to construct higher-level functions
2. **Problem decomposition** — Break complex problems into small, testable functions
3. **Robust foundations** — Handle edge cases (like wrapping) at the lowest level so higher layers don't need to worry

---

## Code Files

- [`game_of_life.c`](./game_of_life.c) — Complete Game of Life implementation

## Resources

- [Conway's Game of Life - Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- [Antirez's Gist](https://gist.github.com/antirez/4f3f523154302413ce172e071b1d5d7d) — Original code from the video

<!-- IMPROVEMENTS: Add more pattern examples (blinker, block, beacon), performance comparison with optimized version -->

*Notes from Salvatore Sanfilippo's C Programming Course, refined with AI assistance.*
