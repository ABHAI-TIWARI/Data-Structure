#include <stdio.h>

void print_array(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int sum_array(const int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int max_array(const int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void reverse_array(int arr[], int size) {
	for (int left = 0, right = size - 1; left < right; left++, right--) {
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
}

void insert_at(int arr[], int *size, int capacity, int position, int value) {
	if (*size >= capacity) {
		printf("Insert failed: array is full.\n");
		return;
	}
	if (position < 0 || position > *size) {
		printf("Insert failed: invalid position.\n");
		return;
	}

	for (int i = *size; i > position; i--) {
		arr[i] = arr[i - 1];
	}
	arr[position] = value;
	(*size)++;
}

void delete_at(int arr[], int *size, int position) {
	if (*size <= 0) {
		printf("Delete failed: array is empty.\n");
		return;
	}
	if (position < 0 || position >= *size) {
		printf("Delete failed: invalid position.\n");
		return;
	}

	for (int i = position; i < *size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*size)--;
}

int main(void) {
	printf("=== ARRAY TUTORIAL (C) ===\n\n");

	printf("1) Declaration and Initialization\n");
	int marks[5] = {72, 85, 90, 68, 79};
	printf("marks = ");
	print_array(marks, 5);
	printf("\n");

	printf("2) Traversal, Sum, and Average\n");
	int total = sum_array(marks, 5);
	double average = (double)total / 5;
	printf("Sum = %d\n", total);
	printf("Average = %.2f\n\n", average);

	printf("3) Update an Element\n");
	marks[3] = 75;
	printf("After updating marks[3] to 75: ");
	print_array(marks, 5);
	printf("\n");

	printf("4) Insert and Delete (using logical size)\n");
	int numbers[10] = {10, 20, 30, 40, 50};
	int size = 5;
	int capacity = 10;

	printf("Original numbers: ");
	print_array(numbers, size);

	insert_at(numbers, &size, capacity, 2, 99);
	printf("After insert 99 at index 2: ");
	print_array(numbers, size);

	delete_at(numbers, &size, 4);
	printf("After delete at index 4: ");
	print_array(numbers, size);
	printf("\n");

	printf("5) Pass Array to Functions\n");
	printf("Max element in numbers = %d\n", max_array(numbers, size));
	reverse_array(numbers, size);
	printf("Reversed numbers: ");
	print_array(numbers, size);
	printf("\n");

	printf("6) 2D Array Example\n");
	int matrix[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 3; col++) {
			printf("%d ", matrix[row][col]);
		}
		printf("\n");
	}

	return 0;
}
