Binary Trees (C)
============================

Team:
------
Sondos Saleh Alrubaish
Nawal Samer Alharbi


About the Project
----------------------------
This project implements core binary tree utilities in C and practices
fundamental concepts such as node creation, insertion, deletion, depth/height,
size, traversals, and relationship queries (sibling, uncle).
All code follows Holberton requirements and Betty style.

Environment & Rules
----------------------------
- OS: Ubuntu 20.04 LTS
- Compiler: gcc -Wall -Werror -Wextra -pedantic -std=gnu89
- No global variables
- ≤ 5 functions per file
- Standard library is allowed
- All headers are include-guarded
- Prototypes in binary_trees.h
- A list/array with size < 2 is considered trivially handled
- Main files are only for local tests (not graded)


Data Structures
----------------------------
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;


Repository Structure (suggested)
----------------------------
holbertonschool-binary_trees/
├── binary_trees.h
├── binary_tree_print.c      (visualization helper, not graded)
├── 0-binary_tree_node.c
├── 1-binary_tree_insert_left.c
├── 2-binary_tree_insert_right.c
├── 3-binary_tree_delete.c
├── 4-binary_tree_is_leaf.c
├── 5-binary_tree_is_root.c
├── 6-binary_tree_preorder.c
├── 7-binary_tree_inorder.c
├── 8-binary_tree_postorder.c
├── 9-binary_tree_height.c
├── 10-binary_tree_depth.c
├── 11-binary_tree_size.c
├── 12-binary_tree_leaves.c
├── 13-binary_tree_nodes.c
├── 14-binary_tree_balance.c
├── 15-binary_tree_is_full.c
├── 16-binary_tree_is_perfect.c
├── 17-binary_tree_sibling.c
├── 18-binary_tree_uncle.c
└── README.md


Compilation Examples
----------------------------
# Example (Task 0):
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node

# Example (Task 6 - preorder):
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre

# Use similar commands for other tasks by swapping the source files.


Implemented Tasks (0–18)
----------------------------
0. New node
   File: 0-binary_tree_node.c
   Proto: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
   - Allocates and initializes a new node (left/right = NULL).

1. Insert left
   File: 1-binary_tree_insert_left.c
   Proto: binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
   - Inserts as left child. If left exists, it becomes new node’s left.

2. Insert right
   File: 2-binary_tree_insert_right.c
   Proto: binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
   - Inserts as right child. If right exists, it becomes new node’s right.

3. Delete
   File: 3-binary_tree_delete.c
   Proto: void binary_tree_delete(binary_tree_t *tree);
   - Recursively frees entire tree (post-order).

4. Is leaf
   File: 4-binary_tree_is_leaf.c
   Proto: int binary_tree_is_leaf(const binary_tree_t *node);
   - Returns 1 if node has no children, else 0.

5. Is root
   File: 5-binary_tree_is_root.c
   Proto: int binary_tree_is_root(const binary_tree_t *node);
   - Returns 1 if node->parent is NULL, else 0.

6. Pre-order traversal
   File: 6-binary_tree_preorder.c
   Proto: void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
   - Visit order: node → left → right. No-op if tree or func is NULL.

7. In-order traversal
   File: 7-binary_tree_inorder.c
   Proto: void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
   - Visit order: left → node → right.

8. Post-order traversal
   File: 8-binary_tree_postorder.c
   Proto: void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
   - Visit order: left → right → node.

9. Height
   File: 9-binary_tree_height.c
   Proto: size_t binary_tree_height(const binary_tree_t *tree);
   - Number of edges on the longest path from node down to a leaf.
   - Returns 0 for NULL.

10. Depth
    File: 10-binary_tree_depth.c
    Proto: size_t binary_tree_depth(const binary_tree_t *tree);
    - Number of edges from node up to the root.
    - Returns 0 for NULL.

11. Size
    File: 11-binary_tree_size.c
    Proto: size_t binary_tree_size(const binary_tree_t *tree);
    - Total number of nodes in the tree (recursive count).

12. Leaves
    File: 12-binary_tree_leaves.c
    Proto: size_t binary_tree_leaves(const binary_tree_t *tree);
    - Number of leaves (nodes with no children).

13. Nodes (with at least 1 child)
    File: 13-binary_tree_nodes.c
    Proto: size_t binary_tree_nodes(const binary_tree_t *tree);
    - Counts internal nodes (degree ≥ 1).

14. Balance factor
    File: 14-binary_tree_balance.c
    Proto: int binary_tree_balance(const binary_tree_t *tree);
    - balance = height(left) - height(right).
    - Returns 0 if tree is NULL.

15. Is full
    File: 15-binary_tree_is_full.c
    Proto: int binary_tree_is_full(const binary_tree_t *tree);
    - Full: every node has either 0 or 2 children.

16. Is perfect
    File: 16-binary_tree_is_perfect.c
    Proto: int binary_tree_is_perfect(const binary_tree_t *tree);
    - Perfect: all leaves at the same depth and every internal node has 2 children.

17. Sibling
    File: 17-binary_tree_sibling.c
    Proto: binary_tree_t *binary_tree_sibling(binary_tree_t *node);
    - Returns the other child of the parent, or NULL.

18. Uncle
    File: 18-binary_tree_uncle.c
    Proto: binary_tree_t *binary_tree_uncle(binary_tree_t *node);
    - Returns parent’s sibling, or NULL.


Key Concepts (Quick Reference)
----------------------------
- Binary Tree: Each node has up to two children (left/right).
- BST vs. Binary Tree: BST has ordering constraints; here (tasks 0–23) trees are not BSTs.
- Gain vs Linked Lists: Tree operations can achieve O(log n) average (balanced trees) for search/insert,
  while linked lists are typically O(n).
- Depth (node): Edges from node to root.
- Height (node): Edges from node to deepest leaf below it.
- Size: Total nodes.
- Traversals:
  * Pre-order: Node, Left, Right
  * In-order: Left, Node, Right
  * Post-order: Left, Right, Node
- Tree Types:
  * Complete: All levels filled except possibly the last, filled from left.
  * Full: Every node has 0 or 2 children (no single-child node).
  * Perfect: All leaves at same depth, and all internal nodes have 2 children.
  * Balanced (informal): Left/right heights differ by at most 1 (varies by definition/AVL/RB).


Notes
----------------------------
- The provided binary_tree_print.c is for visualization (not graded, may not be used by checker).
- Handle NULL inputs gracefully in all APIs.
- Traversal functions must no-op if tree or callback is NULL.
- Follow Betty style and project constraints strictly.


How to Test Quickly
----------------------------
# Build and run a sample:
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node && ./0-node

# Use valgrind to ensure no leaks:
valgrind ./0-node


Authors
----------------------------
Sondos Saleh Alrubaish
Nawal Samer Alharbi

