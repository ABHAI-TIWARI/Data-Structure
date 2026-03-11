#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void increment(int *x) {
    if (x != NULL) {
        (*x)++;
    }
}

void set_zero(int *x) {
    if (x != NULL) {
        *x = 0;
    }
}

void print_array_with_pointers(const int *arr, int size) {
    const int *p = arr;
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

int max_with_pointers(const int *arr, int size) {
    const int *p = arr;
    int max_val = *p;

    for (int i = 1; i < size; i++) {
        if (*(p + i) > max_val) {
            max_val = *(p + i);
        }
    }

    return max_val;
}

size_t my_strlen(const char *s) {
    const char *start = s;
    while (*s != '\0') {
        s++;
    }
    return (size_t)(s - start);
}

void reverse_array(int *arr, int size) {
    int *left = arr;
    int *right = arr + size - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main(void) {
    printf("=== POINTER-ADDRESS TUTORIAL DEMO ===\n\n");

    printf("1) Address Basics\n");
    int x = 10;
    printf("x (value)   = %d\n", x);
    printf("&x (address)= %p\n\n", (void *)&x);

    printf("2) Pointer Basics\n");
    int *p = &x;
    printf("p (address) = %p\n", (void *)p);
    printf("*p (value)  = %d\n\n", *p);

    printf("3) Modify Through Pointer\n");
    *p = 99;
    printf("After *p = 99, x = %d\n\n", x);

    printf("4) Function: increment(int *x)\n");
    int n = 50;
    printf("Before increment: n = %d\n", n);
    increment(&n);
    printf("After increment:  n = %d\n\n", n);

    printf("5) Function: swap(int *a, int *b)\n");
    int a = 3;
    int b = 8;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap:  a = %d, b = %d\n\n", a, b);

    printf("6) Null Pointer Safety\n");
    int *null_ptr = NULL;
    if (null_ptr == NULL) {
        printf("null_ptr is NULL, so we do not dereference it.\n\n");
    }

    printf("7) Pointer Arithmetic with Array\n");
    int arr[] = {10, 20, 30, 40, 50};
    int size = (int)(sizeof(arr) / sizeof(arr[0]));
    print_array_with_pointers(arr, size);
    printf("*(arr + 2) = %d\n\n", *(arr + 2));

    printf("8) set_zero(int *x) for Multiple Variables\n");
    int v1 = 7;
    int v2 = 14;
    int v3 = 21;
    printf("Before: v1=%d v2=%d v3=%d\n", v1, v2, v3);
    set_zero(&v1);
    set_zero(&v2);
    set_zero(&v3);
    printf("After:  v1=%d v2=%d v3=%d\n\n", v1, v2, v3);

    printf("9) Challenge: Reverse Array Using Two Pointers\n");
    int nums[] = {1, 2, 3, 4, 5, 6};
    int nums_size = (int)(sizeof(nums) / sizeof(nums[0]));
    printf("Before reverse: ");
    print_array_with_pointers(nums, nums_size);
    reverse_array(nums, nums_size);
    printf("After reverse:  ");
    print_array_with_pointers(nums, nums_size);
    printf("\n");

    printf("10) Challenge: Max in Array Using Pointers\n");
    int max_val = max_with_pointers(arr, size);
    printf("Max value in arr = %d\n\n", max_val);

    printf("11) Challenge: my_strlen(const char *s)\n");
    const char *text = "Pointer Address";
    printf("Text: %s\n", text);
    printf("my_strlen: %zu\n", my_strlen(text));
    printf("strlen:    %zu\n", strlen(text));

    return 0;
}
