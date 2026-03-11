# Linked List (Common Notes)

A linked list is a **linear data structure** where elements (called nodes) are stored at non-contiguous memory locations.
Each node stores:

- `data` (actual value)
- `next` (address of next node)

Unlike arrays, linked lists do not require continuous memory.

## Why Linked List?

Arrays have fixed size (or costly resizing) and insertion/deletion in the middle can be expensive because elements must shift.
Linked lists solve this by changing pointers instead of shifting data.

## Basic Node Structure in C

```c
struct Node {
	 int data;
	 struct Node* next;
};
```

## Types of Linked List

1. **Singly Linked List**
	- Each node points to next node only.
	- Last node points to `NULL`.

2. **Doubly Linked List**
	- Each node has `prev` and `next`.
	- Traversal possible in both directions.

3. **Circular Linked List**
	- Last node points back to first node.
	- Can be singly or doubly circular.

## Common Operations

1. **Traversal**: Visit all nodes from head to end.
2. **Insertion**:
	- At beginning
	- At end
	- At specific position
3. **Deletion**:
	- From beginning
	- From end
	- By value/position
4. **Search**: Find node containing a key.
5. **Update**: Modify node value.

## Time Complexity (Singly Linked List)

- Access by index: `O(n)`
- Search: `O(n)`
- Insert at head: `O(1)`
- Insert at tail: `O(n)` (or `O(1)` if tail pointer maintained)
- Delete at head: `O(1)`
- Delete at tail: `O(n)`

## Linked List vs Array

- Array:
  - Fast random access: `O(1)`
  - Fixed/contiguous memory
  - Costly insertion/deletion in middle

- Linked List:
  - Dynamic size
  - Easy insertion/deletion (pointer changes)
  - No direct random access (`O(n)` to reach i-th node)

## Advantages

- Dynamic memory usage
- Efficient insertion/deletion at known position
- Useful in implementing stacks, queues, adjacency lists, hash chaining

## Disadvantages

- Extra memory for pointers
- Slower access due to sequential traversal
- Pointer handling can cause bugs (memory leaks, dangling pointers)

## Real-Life Analogy

Think of linked list like a treasure hunt:
each clue tells where the next clue is.
You cannot jump directly to clue #10 without following previous clues.

## Key Terms

- **Head**: First node pointer
- **Tail**: Last node
- **NULL**: End marker in non-circular list
- **Pointer**: Variable storing address of another variable/node
