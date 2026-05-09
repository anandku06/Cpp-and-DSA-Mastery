# Binary Tree

- A fundamental hierarchical data structure in computer science that comprises nodes arranged in a tree-like structure.
- It consists of nodes, where each node can have at most two children nodes, known as the left child and the right child.

## Nodes

- Each node in a binary tree contains three components:
  1. **Data**: The value or information stored in the node.
  2. **Left Child**: A reference to the left child node, which can be null if there is no left child.
  3. **Right Child**: A reference to the right child node, which can be null if there is no right child.

### Root Node

- The topmost node in a binary tree is called the root node. It serves as the entry point to the tree and has no parent.

### Child Nodes

- Nodes that are directly connected to another node are called child nodes. The left and right children of a node are its child nodes.

### Leaf Nodes

- Nodes that do not have any children are called leaf nodes. They are the terminal nodes of
  the tree.

### Ancestry

- The relationship between nodes in a binary tree can be described in terms of ancestry:
  - A node is an ancestor of another node if there is a path from the ancestor to the descendant.
  - A node is a descendant of another node if there is a path from the ancestor to the descendant.

## Properties of Binary Trees

- The maximum number of nodes at level `l` of a binary tree is `2^l`, where `l` starts from 0 for the root level.
- The maximum number of nodes in a binary tree of height `h` is `2^(h+1) - 1`.
- The height of a binary tree is the number of edges on the longest path from the root to a leaf node. The height of an empty tree is defined as -1, and the height of a tree with only one node (the root) is 0.

## Types of Binary Trees

1. **Full Binary Tree**: A binary tree in which every node has either 0 or 2 children.
2. **Complete Binary Tree**: A binary tree in which all levels are completely filled except possibly the last level, which is filled from left to right.
3. **Perfect Binary Tree**: A binary tree in which all internal nodes have two children and all leaf nodes are at the same level.
4. **Balanced Binary Tree**: A binary tree in which the difference in height between the left and right subtrees of any node is no more than one.
5. **Binary Search Tree (BST)**: A binary tree in which for each node, the value of all nodes in the left subtree is less than the node's value, and the value of all nodes in the right subtree is greater than the node's value.
6. **Degenerate Binary Tree**: A binary tree in which each parent node has only one child node. This can lead to a skewed tree structure, resembling a linked list.

# Full Binary Tree

- A binary tree in which every node has either 0 or 2 children.
- In a full binary tree, every node is either a leaf node (with 0 children) or an internal node (with 2 children).
- A full binary tree of height `h` has `2^(h+1) - 1` nodes.

# Complete Binary Tree

- A binary tree in which all levels are completely filled except possibly the last level, which is filled from left to right.
- In a complete binary tree, all nodes are as far left as possible.
- A complete binary tree of height `h` has between `2^h` and `2^(h+1) - 1` nodes.

# Perfect Binary Tree

- A binary tree in which all internal nodes have two children and all leaf nodes are at the same level.
- In a perfect binary tree, all levels are completely filled.
- A perfect binary tree of height `h` has `2^(h+1) - 1` nodes.

# Balanced Binary Tree

- A binary tree in which the difference in height between the left and right subtrees of any node is no more than one.
- A balanced binary tree ensures that the tree remains approximately balanced, which helps maintain efficient operations such as insertion, deletion, and search.
- Examples of balanced binary trees include AVL trees and Red-Black trees.

# Binary Search Tree (BST)

- A binary tree in which for each node, the value of all nodes in the left subtree is less than the node's value, and the value of all nodes in the right subtree is greater than the node's value.
- A binary search tree allows for efficient searching, insertion, and deletion operations.
- The average time complexity for search, insertion, and deletion operations in a binary search tree is O(log n), where n is the number of nodes in the tree. However, in the worst case (when the tree becomes skewed), the time complexity can degrade to O(n).

# Degenerate Binary Tree
- A binary tree in which each parent node has only one child node. This can lead to a skewed tree structure, resembling a linked list.
- In a degenerate binary tree, the height of the tree is equal to the number of nodes minus one, which can lead to inefficient operations with a time complexity of O(n) for search, insertion, and deletion.
