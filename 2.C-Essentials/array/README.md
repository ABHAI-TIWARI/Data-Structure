# Array in C - Detailed Tutorial

This folder teaches the **Array** concept in C with practical examples.

## 1. What is an Array?

An array is a collection of elements of the same data type stored in **continuous memory locations**.

Example:

```c
int marks[5] = {72, 85, 90, 68, 79};
```

- `marks` is an array of type `int`.
- `5` is the size (number of elements).
- Index starts from `0`.
- Valid indexes here are `0` to `4`.

## 2. Why Use Arrays?

Arrays are useful when:

- You need to store many values of the same type.
- You want fast access using index.
- You want to process data using loops.

## 3. Basic Syntax

### Declaration

```c
int arr[10];
```

This creates space for 10 integers.

### Initialization

```c
int arr[5] = {10, 20, 30, 40, 50};
```

### Partial Initialization

```c
int arr[5] = {1, 2};
```

Remaining elements become `0`.

### Size Inference

```c
int arr[] = {5, 10, 15};
```

Compiler sets size to `3` automatically.

## 4. Accessing and Updating Elements

```c
int x = arr[2];   // access
arr[2] = 99;      // update
```

If you access an invalid index (like `arr[10]` in a 5-size array), behavior is undefined.

## 5. Traversing an Array

Use a loop to visit each element.

```c
for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
}
```

## 6. Common Operations

### Sum and Average

```c
int sum = 0;
for (int i = 0; i < size; i++) sum += arr[i];
double avg = (double)sum / size;
```

### Find Maximum

```c
int max = arr[0];
for (int i = 1; i < size; i++) {
    if (arr[i] > max) max = arr[i];
}
```

### Reverse Array

```c
for (int l = 0, r = size - 1; l < r; l++, r--) {
    int t = arr[l];
    arr[l] = arr[r];
    arr[r] = t;
}
```

## 7. Insert and Delete in Array

Arrays in C have fixed capacity. So insertion/deletion means shifting elements.

### Insert at position

- Check if space is available.
- Shift elements right from end to position.
- Place new value.

### Delete at position

- Shift elements left from next position to end.
- Reduce logical size.

This is demonstrated in `main.c` using `insert_at()` and `delete_at()`.

## 8. Passing Array to Function

When you pass an array to a function, it behaves like a pointer to the first element.

```c
int sum_array(const int arr[], int size);
```

`const` is used when function should not modify the array.

## 9. 2D Arrays (Matrix)

A 2D array is an array of arrays.

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Access with two indexes: `matrix[row][col]`.

## 10. Memory View (Important)

For `int arr[5] = {10,20,30,40,50};`

- Elements are contiguous in memory.
- If `arr` starts at address `1000` and `int` is 4 bytes:
  - `arr[0]` at `1000`
  - `arr[1]` at `1004`
  - `arr[2]` at `1008`
  - ...

This is why random access by index is efficient.

## 11. Time Complexity Summary

- Access by index: `O(1)`
- Update by index: `O(1)`
- Traverse: `O(n)`
- Search (linear): `O(n)`
- Insert/Delete at end (with free space): `O(1)`
- Insert/Delete at middle: `O(n)` (due to shifting)

## 12. Common Mistakes

- Using index out of range.
- Forgetting array size during loops.
- Dividing by zero when size is `0`.
- Confusing capacity with logical size.

## 13. Practice Ideas

1. Find second largest element.
2. Rotate array by `k` positions.
3. Remove duplicates from sorted array.
4. Merge two sorted arrays.
5. Count frequency of each element.

## 14. Run the Example in This Folder

From `2.C-Essentials/array`:

```bash
gcc main.c -o array_demo
./array_demo
```

This program prints demonstrations for:

- Declaration and initialization
- Traversal, sum, average
- Update
- Insert and delete
- Function-based operations
- 2D arrays
