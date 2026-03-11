# Pointer-Address Tutorial (C)

Pointers are one of the most important C topics. This tutorial teaches pointer and address basics with simple examples, memory intuition, and practice tasks.

## 1) Address: Where a Variable Lives

Every variable is stored at some memory location. That location is called its address.

```c
#include <stdio.h>

int main(void) {
    int x = 10;

    printf("x (value)     = %d\n", x);
    printf("&x (address)   = %p\n", (void *)&x);

    return 0;
}
```

- `x` -> gives the value.
- `&x` -> gives the address.
- Use `%p` to print an address.

## 2) Pointer: A Variable That Stores an Address

A pointer is just another variable, but its value is an address.

```c
int *p;
```

This means `p` is a pointer to `int`.

```c
#include <stdio.h>

int main(void) {
    int x = 25;
    int *p = &x;

    printf("x   = %d\n", x);
    printf("&x  = %p\n", (void *)&x);
    printf("p   = %p\n", (void *)p);
    printf("*p  = %d\n", *p);

    return 0;
}
```

- `p` stores the address of `x`.
- `*p` reads the value at that address.

## 3) The Two Core Operators

- `&` (address-of): get address of a variable.
- `*` (dereference): read/write value stored at a pointer's address.

```c
int x = 5;
int *p = &x;

printf("%d\n", *p); // 5
*p = 99;
printf("%d\n", x);  // 99
```

When you write to `*p`, you are writing to `x`.

## 4) Visual Memory Model

Think about this setup:

```c
int x = 42;
int *p = &x;
```

Possible memory picture:

```text
x: value 42   at address 0x100
p: value 0x100 at address 0x200
```

- `x` stores data (`42`).
- `p` stores where that data is (`0x100`).

## 5) Pointer Type Must Match Data Type

Pointer type should match the type it points to.

```c
int n = 7;
int *pi = &n;

char ch = 'A';
char *pc = &ch;
```

Wrong type can cause warnings and undefined behavior.

## 6) Null and Uninitialized Pointers

### Uninitialized pointer (dangerous)

```c
int *p;
*p = 10; // undefined behavior
```

### Null pointer (safe placeholder)

```c
int *p = NULL;
if (p != NULL) {
    printf("%d\n", *p);
}
```

Initialize pointers before dereferencing.

## 7) Pass by Address in Functions

Pointers let functions modify caller variables.

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 3;
    int y = 8;

    printf("Before: x=%d y=%d\n", x, y);
    swap(&x, &y);
    printf("After:  x=%d y=%d\n", x, y);

    return 0;
}
```

`swap` receives addresses, so it can directly edit original values.

## 8) Pointer Arithmetic (Array Basics)

For arrays, pointer arithmetic moves by element size.

```c
#include <stdio.h>

int main(void) {
    int arr[4] = {10, 20, 30, 40};
    int *p = arr; // same as &arr[0]

    printf("%d\n", *p);       // arr[0]
    printf("%d\n", *(p + 1)); // arr[1]
    printf("%d\n", *(p + 2)); // arr[2]
    printf("%d\n", *(p + 3)); // arr[3]

    return 0;
}
```

If `p` points to `int`, then `p + 1` moves by `sizeof(int)` bytes.

## 9) Common Mistakes to Avoid

1. Dereferencing uninitialized pointers.
2. Dereferencing `NULL`.
3. Returning address of local variable from a function.
4. Using wrong format specifier (always `%p` for addresses).
5. Mixing pointer types incorrectly.

## 10) Practice Exercises

1. Create `int age = 21;` and `int *p = &age;`. Print value and address info.
2. Change `n` from `50` to `100` using pointer only.
3. Write `void increment(int *x)` and test it.
4. Print an array using pointer arithmetic (no `arr[i]`).
5. Write `void set_zero(int *x)` and call it for multiple integers.
6. Write your own `swap` and test with negative numbers too.

## 11) Mini Challenge

1. Reverse an array with two pointers (`left`, `right`).
2. Find max value in array using pointers only.
3. Implement `my_strlen(const char *s)` with pointer traversal.

## 12) Quick Recap

- Variable -> stores a value.
- Address -> location of that value.
- Pointer -> stores an address.
- `&` -> get address.
- `*` -> access value through address.

Master this model and topics like arrays, strings, dynamic memory, and linked lists become much easier.
