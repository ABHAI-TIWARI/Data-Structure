#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[50];
    Date join_date;
} Employee;

void print_student(Student s) {
    printf("Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
}

void update_marks(Student *s, float new_marks) {
    s->marks = new_marks;
}

int main(void) {
    printf("=== STRUCTURE TUTORIAL (C) ===\n\n");

    printf("1) Basic Structure Declaration and Initialization\n");
    Student s1 = {101, "Aman", 88.5f};
    print_student(s1);
    printf("\n");

    printf("2) Access and Update Members\n");
    s1.roll = 102;
    strcpy(s1.name, "Riya");
    s1.marks = 91.0f;
    print_student(s1);
    printf("\n");

    printf("3) Pass by Value vs Pass by Pointer\n");
    Student s2 = {103, "Kabir", 76.0f};
    printf("Before update: ");
    print_student(s2);
    update_marks(&s2, 82.5f);
    printf("After update via pointer: ");
    print_student(s2);
    printf("\n");

    printf("4) Array of Structures\n");
    Student cls[3] = {
        {201, "Neha", 85.0f},
        {202, "Arjun", 79.5f},
        {203, "Sana", 92.0f}
    };

    for (int i = 0; i < 3; i++) {
        print_student(cls[i]);
    }
    printf("\n");

    printf("5) Nested Structure\n");
    Employee e1 = {1, "Rohit", {12, 8, 2024}};
    printf("Employee ID: %d, Name: %s, Join Date: %02d-%02d-%04d\n",
           e1.id,
           e1.name,
           e1.join_date.day,
           e1.join_date.month,
           e1.join_date.year);
    printf("\n");

    printf("6) Pointer to Structure (Dynamic Allocation)\n");
    Student *ps = (Student *)malloc(sizeof(Student));
    if (ps == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    ps->roll = 301;
    strcpy(ps->name, "Ishita");
    ps->marks = 95.5f;

    printf("Dynamic Student -> Roll: %d, Name: %s, Marks: %.2f\n",
           ps->roll, ps->name, ps->marks);

    free(ps);
    ps = NULL;
    printf("Dynamic memory freed successfully.\n");

    return 0;
}
