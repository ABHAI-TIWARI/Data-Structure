# Pointer in C - Detailed Tutorial

This folder explains **Pointers** in C with examples and a runnable program.

## 1. What is a Pointer?

A pointer is a variable that stores the **memory address** of another variable.

```c
int x = 10;
int *p = &x;
```

- `x` stores value `10`.
- `&x` means address of `x`.
- `p` stores that address.
- `*p` gives the value at that address (dereference).

## 2. Why Pointers are Important

Pointers are used for:

- Pass-by-reference in functions
- Working with arrays and strings
- Dynamic memory allocation (`malloc`, `calloc`, `free`)
- Building data structures like linked list, tree, graph

## 3. Pointer Syntax

### Declaration

```c
int *p;
char *cp;
float *fp;
```

The pointer type should match the variable type it points to.

### Initialization

```c
int x = 25;
int *p = &x;
```

Always initialize pointers. Uninitialized pointers are dangerous.

## 4. Address Operator and Dereference Operator

- `&` gives address of a variable.
- `*` accesses value at an address.

```c
int x = 40;
int *p = &x;
printf("%p\n", (void*)p);   // address
printf("%d\n", *p);         // value: 40
```

## 5. Pointer and Value Update

```c
int x = 5;
int *p = &x;
*p = 99;
```

Now `x` becomes `99`, because `*p` updates the same memory location.

## 6. Pointer Arithmetic

```c
int arr[4] = {10, 20, 30, 40};
int *p = arr;
```

- `p` points to `arr[0]`
- `p + 1` points to `arr[1]`
- `*(p + 2)` gives `arr[2]`

Pointer arithmetic moves by data type size, not by 1 byte.

## 7. Array and Pointer Relationship

In most expressions, array name acts like pointer to first element.

```c
int arr[3] = {7, 8, 9};
int *p = arr;
```

- `arr[1]` is same as `*(arr + 1)`
- `p[i]` is same as `*(p + i)`

## 8. Passing Pointer to Function

Pointers allow function to modify original variables.

```c
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
```

Call:

```c
swap(&x, &y);
```

## 9. NULL Pointer

```c
int *p = NULL;
```

`NULL` means pointer is not pointing to valid memory yet.
Always check before dereference.

```c
if (p != NULL) {
    printf("%d", *p);
}
```

## 10. Double Pointer

A double pointer stores address of another pointer.

```c
int x = 50;
int *p = &x;
int **pp = &p;
```

- `*pp` gives `p`
- `**pp` gives `x`

## 11. Dynamic Memory Allocation

```c
int n = 5;
int *arr = malloc(n * sizeof(int));
```

- Memory is allocated at runtime (heap).
- Always check `arr != NULL`.
- Release memory after use:

```c
free(arr);
arr = NULL;
```

## 12. Common Pointer Problems

- Wild pointer: uninitialized pointer
- Dangling pointer: pointer to freed memory
- NULL dereference: using `*p` when `p == NULL`
- Memory leak: allocated memory not freed

## 13. Time Complexity Notes

- Dereference pointer: `O(1)`
- Access array by pointer offset: `O(1)`
- Traversing via pointer: `O(n)`

## 14. Run the Example in This Folder

From `2.C-Essentials/pointer`:

```bash
gcc main.c -o pointer_demo
./pointer_demo
```

The program demonstrates:

- Basic pointer creation
- Dereference and update
- Pointer arithmetic
- Array traversal via pointer
- Pass-by-reference with swap
- Double pointer
- Dynamic memory with `malloc` and `free`
