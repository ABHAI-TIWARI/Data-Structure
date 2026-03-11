#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array_with_pointer(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(void) {
    printf("=== POINTER TUTORIAL (C) ===\n\n");

    printf("1) Basic Pointer\n");
    int x = 10;
    int *p = &x;
    printf("x = %d\n", x);
    printf("Address of x (&x) = %p\n", (void *)&x);
    printf("Pointer p stores address = %p\n", (void *)p);
    printf("Value at *p = %d\n\n", *p);

    printf("2) Modify Value Through Pointer\n");
    *p = 99;
    printf("After *p = 99, x = %d\n\n", x);

    printf("3) Pointer Arithmetic\n");
    int arr[] = {11, 22, 33, 44, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ap = arr;

    printf("arr[0] using pointer = %d\n", *ap);
    printf("arr[2] using *(ap + 2) = %d\n", *(ap + 2));
    printf("All elements using pointer traversal: ");
    print_array_with_pointer(arr, size);
    printf("\n");

    printf("4) Pass Pointer to Function (Swap)\n");
    int a = 5;
    int b = 9;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap:  a = %d, b = %d\n\n", a, b);

    printf("5) NULL Pointer Check\n");
    int *np = NULL;
    if (np == NULL) {
        printf("np is NULL, safe to avoid dereference.\n\n");
    }

    printf("6) Double Pointer\n");
    int y = 50;
    int *py = &y;
    int **ppy = &py;
    printf("y = %d\n", y);
    printf("*py = %d\n", *py);
    printf("**ppy = %d\n\n", **ppy);

    printf("7) Dynamic Memory (malloc/free)\n");
    int n = 5;
    int *dyn = (int *)malloc(n * sizeof(int));

    if (dyn == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        dyn[i] = (i + 1) * 100;
    }

    printf("Dynamically allocated array: ");
    print_array_with_pointer(dyn, n);

    free(dyn);
    dyn = NULL;
    printf("Memory freed successfully.\n");

    return 0;
}
