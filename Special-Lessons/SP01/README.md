# Special Lesson 01 - Binary Search Tree

**Video:** [Implementing a BST from Memory](https://www.youtube.com/watch?v=soiBgJjAmP8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=19)

---

## Overview

Sanfilippo demonstrates that fundamental data structures can be reconstructed from first principles — without memorization. After 20 years without touching a BST, he implements one live, proving that understanding the core idea is enough.

> *"You don't need to memorize algorithms. If you understand the fundamental idea, the implementation emerges on its own."*

---

## The Core Idea

A Binary Search Tree has one simple rule:

- **Left subtree**: values less than the node
- **Right subtree**: values greater than the node

```
         10
        /  \
       5    20
           /  \
         15    100
```

That's it. Everything else — insertion, traversal, deletion — flows from this invariant.

---

## The Node Structure

```c
struct node {
    int val;
    struct node *left, *right;
};
```

Each node holds a value and pointers to its children. Self-referential structs enable linked data structures.

---

## Insertion: Iterative Approach

Find the correct spot by following left/right based on comparison:

```c
struct node *add(struct node *root, int val) {
    struct node *saved_root = root;
    struct node *new = malloc(sizeof(*new));
    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL) return new;  // First node becomes root

    while (1) {
        if (val > root->val) {
            if (root->right == NULL) {
                root->right = new;
                return saved_root;
            }
            root = root->right;
        } else {
            if (root->left == NULL) {
                root->left = new;
                return saved_root;
            }
            root = root->left;
        }
    }
}
```

The function returns the root — either the newly created first node or the original root unchanged.

---

## In-Order Traversal: The Elegant Recursion

To print values in sorted order, use **in-order traversal**: left, self, right.

```c
void print_sorted(struct node *root) {
    if (root == NULL) return;
    print_sorted(root->left);   // All smaller values first
    printf("%d\n", root->val);  // Then this node
    print_sorted(root->right);  // Then all larger values
}
```

This three-line function is the beauty of recursion — the tree's structure directly maps to the algorithm.

> *"This code isn't my invention — it's written by the data structure itself."*

---

## Freeing Memory: Same Pattern

Recursion works for cleanup too. Free children before freeing the node itself:

```c
void free_tree(struct node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);  // Free self AFTER children
}
```

Post-order traversal: left, right, self.

---

## Key Takeaways

1. **Understand the invariant**, not the code — the implementation follows naturally

2. **Iterative vs Recursive**: Both work. Iterative avoids stack overflow on deep trees; recursive is more elegant

3. **Self-referential structs** (`struct node *left`) are the foundation of linked data structures

4. **Duplicate handling**: This implementation puts duplicates on the left — a design choice, not a bug

---

## Quick Reference

| Operation | Approach | Complexity |
|-----------|----------|------------|
| Insert | Iterative descent | O(log n) average, O(n) worst |
| Search | Same as insert | O(log n) average |
| Print sorted | In-order recursion | O(n) |
| Free all | Post-order recursion | O(n) |

---

## Code Files

- [`bst.c`](./bst.c) — Complete BST implementation
- [`bst-free-visual.html`](./bst-free-visual.html) — Interactive visualization of recursive memory freeing


*Notes from Salvatore Sanfilippo's C Programming Course.*
