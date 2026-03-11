#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int roll;
	char name[32];
	float marks;
} Student;

void print_student(const Student *s) {
	if (s == NULL) {
		printf("Student pointer is NULL\n");
		return;
	}

	printf("Roll: %d, Name: %s, Marks: %.2f\n", s->roll, s->name, s->marks);
}

void update_marks(Student *s, float new_marks) {
	if (s == NULL) {
		return;
	}
	s->marks = new_marks;
}

void rename_student(Student *s, const char *new_name) {
	if (s == NULL || new_name == NULL) {
		return;
	}

	strncpy(s->name, new_name, sizeof(s->name) - 1);
	s->name[sizeof(s->name) - 1] = '\0';
}

void print_class(const Student *cls, int size) {
	if (cls == NULL || size <= 0) {
		return;
	}

	for (int i = 0; i < size; i++) {
		printf("Student %d -> ", i + 1);
		print_student(cls + i);
	}
}

int main(void) {
	printf("=== POINTER TO STRUCTURE TUTORIAL (C) ===\n\n");

	printf("1) Basic struct variable\n");
	Student s1 = {101, "Aman", 88.5f};
	printf("Using dot operator: s1.name = %s\n\n", s1.name);

	printf("2) Pointer to structure\n");
	Student *ptr = &s1;
	printf("Address of s1: %p\n", (void *)&s1);
	printf("ptr stores:    %p\n\n", (void *)ptr);

	printf("3) Access members through pointer\n");
	printf("Using (*ptr).roll = %d\n", (*ptr).roll);
	printf("Using ptr->roll  = %d\n\n", ptr->roll);

	printf("4) Modify struct using pointer\n");
	ptr->marks = 92.0f;
	rename_student(ptr, "Aman Verma");
	print_student(&s1);
	printf("\n");

	printf("5) Pass pointer to function\n");
	update_marks(&s1, 95.0f);
	print_student(&s1);
	printf("\n");

	printf("6) Array of structures with pointer traversal\n");
	Student cls[3] = {
		{201, "Riya", 91.0f},
		{202, "Kabir", 84.5f},
		{203, "Meera", 89.0f}
	};
	print_class(cls, 3);
	printf("\n");

	printf("7) Dynamic allocation: pointer to struct on heap\n");
	Student *ps = (Student *)malloc(sizeof(Student));
	if (ps == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	ps->roll = 301;
	strncpy(ps->name, "Dynamic Student", sizeof(ps->name) - 1);
	ps->name[sizeof(ps->name) - 1] = '\0';
	ps->marks = 77.5f;

	print_student(ps);
	free(ps);
	ps = NULL;
	printf("Heap memory freed safely.\n\n");

	printf("8) NULL pointer safety check\n");
	Student *null_student = NULL;
	print_student(null_student);

	return 0;
}
