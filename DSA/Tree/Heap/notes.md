# Heap

- A heap is a special tree-based data structure that satisfies the heap property.
- It is commonly used to efficiently solve problems involving priority and to implement algorithms like sorting and finding the smallest or largest elements.

## Heap Property

- The heap property defines the relationship between a parent node and its child nodes in a heap.
- This property ensures that the structure of the heap remains consistent for efficient operations.
- The exact nature of this relationship depends on the type of heap. There are two types of heaps:

1. Min-Heap: The value of each parent node must be less than or equal to the values of its child nodes. This ensures that the smallest element is always at the root of the heap.
2. Max-Heap: The value of each parent node must be greater than or equal to the values of its child nodes. This ensures that the largest element is always at the root of the heap.

### Key Points about the Heap Property

1. Local Relationship:
   The heap property only ensures that a parent node maintains its relationship with its immediate children. It does not impose any order between sibling nodes or across levels.

2. Preservation During Operations:
   When elements are inserted or removed, the heap property might temporarily be violated. A process called heapification restores the property by adjusting the positions of elements.

### Internal Representation Of Heaps

- The internal implementation of a heap utilizes the array representation of a heap rather than the tree structure discussed earlier.
- This highlights the importance of understanding how an almost complete binary tree is represented using an array.

#### Indexing Technique to represnt the Tree

- Root Node: The root of the tree is stored at index 0 (following the 0-based indexing).
- Parent-Child Relationships: For a node at index i:
  - Left Child: The left child is located at index 2\*i + 1.
  - Right Child: The right child is located at index 2\*i + 2.
  - Parent: The parent is located at index ⌈i/2⌉ - 1 (or equivalently, (i-1)/2 using integer division).

### Indices of Leaf Nodes and Non-leaf Nodes

- **Leaf Nodes**
  Leaf nodes are the nodes without any children, and they always appear in the last level (or partially in the second-last level if the last level is incomplete).

In an array representation of a binary tree with N elements
Range of Leaf Node Indices: Leaf Nodes start from the index ⌊N/2⌋ to n-1 (both inclusive).

- **Non-leaf Nodes**
  Non-leaf nodes are the nodes that have at least one child.

In an array representation of a binary tree with N elements
Range of Non-leaf Node Indices: Non-leaf Nodes start from the index 0 to ⌊N/2⌋ - 1 (both inclusive).
