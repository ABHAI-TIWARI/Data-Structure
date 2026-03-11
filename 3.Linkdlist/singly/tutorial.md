# Singly Linked List Tutorial (C)

A singly linked list is a linear data structure made of nodes.
Each node has two parts:

- `data`: stores the value
- `next`: stores the address of the next node

The last node points to `NULL`.

## 1. Node Structure

```c
struct Node {
    int data;
    struct Node *next;
};
```

## 2. Why Use Singly Linked List?

- Dynamic size (you can grow/shrink at runtime)
- Fast insertion at beginning (`O(1)`)
- No need for contiguous memory like arrays

Tradeoff:

- No direct index access, traversal is sequential (`O(n)`)

## 3. Operations Implemented in `main.c`

The demo program includes:

1. Create node
2. Insert at end
3. Insert at beginning
4. Delete by value
5. Search by value
6. Print list
7. Free entire list

## 4. How Insert At End Works

- Create a new node
- If head is `NULL`, make new node the head
- Otherwise traverse to last node and attach new node

## 5. How Delete By Value Works

- Track two pointers: `previous` and `current`
- Find node with matching value
- Relink pointers to skip target node
- Free target node memory

## 6. Time Complexity

- Insert at beginning: `O(1)`
- Insert at end: `O(n)`
- Search: `O(n)`
- Delete by value: `O(n)`
- Traversal: `O(n)`

## 7. Compile and Run

From the singly folder:

```bash
gcc -Wall -Wextra -pedantic -std=c11 main.c -o singly_demo
./singly_demo
```

## 8. Sample Output

```text
Singly Linked List Demo

List: 10 -> 20 -> 30 -> NULL
List: 5 -> 10 -> 20 -> 30 -> NULL
Deleted value 20
List: 5 -> 10 -> 30 -> NULL
Value 30 found at position 3
List: empty
```

## 9. Important Notes

- Always `free` allocated nodes to avoid memory leaks.
- Use a double pointer (`struct Node **head`) when a function may modify the head node.
- Check `malloc` result before using the allocated memory.
