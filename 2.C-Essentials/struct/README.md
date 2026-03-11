# Structure in C - Detailed Tutorial

This folder explains **Structure (`struct`)** in C with complete examples.

## 1. What is a Structure?

A structure is a user-defined data type that groups variables of different data types under one name.

Example:

```c
struct Student {
    int roll;
    char name[50];
    float marks;
};
```

Here, `Student` combines `int`, `char[]`, and `float` in one record.

## 2. Why Use Structure?

Use structures when:

- You need to model real-world entities (Student, Employee, Book, etc.)
- One variable is not enough to represent an object
- You want clean and organized data

## 3. Declaring and Creating Structure Variables

### Structure definition

```c
struct Student {
    int roll;
    char name[50];
    float marks;
};
```

### Variable creation

```c
struct Student s1;
```

## 4. Accessing Members (`.` operator)

```c
s1.roll = 101;
strcpy(s1.name, "Aman");
s1.marks = 89.5f;
```

Member access is done using dot `.` with normal structure variables.

## 5. Initialization Methods

```c
struct Student s1 = {101, "Aman", 89.5f};
```

You can also use designated initialization:

```c
struct Student s2 = {.roll = 102, .name = "Riya", .marks = 91.0f};
```

## 6. Passing Structure to Function

### Pass by value

A copy is passed; original is unchanged.

```c
void print_student(struct Student s);
```

### Pass by pointer (recommended for large structs)

Original can be modified and copying cost is avoided.

```c
void update_marks(struct Student *s, float new_marks);
```

Use `->` for pointer to struct:

```c
s->marks = new_marks;
```

## 7. Array of Structures

```c
struct Student cls[3];
```

Useful for storing many records of same type.

## 8. Nested Structure

A structure member can be another structure.

```c
struct Date {
    int day, month, year;
};

struct Employee {
    int id;
    char name[40];
    struct Date join_date;
};
```

## 9. Typedef with Structure

`typedef` gives a shorter name.

```c
typedef struct {
    int id;
    char title[50];
    float price;
} Book;

Book b1;
```

## 10. Structure Memory and Padding

Structure size is often more than sum of members due to padding/alignment.

Example:

```c
struct Example {
    char c;
    int x;
};
```

`sizeof(struct Example)` may become `8` (not `5`) on many systems.

## 11. Common Mistakes

- Forgetting `#include <string.h>` when using `strcpy`
- Using `.` instead of `->` for pointer-to-struct
- Passing large structs by value unnecessarily
- Reading string with `scanf("%s", ...)` without width limit

## 12. Time Complexity Notes

- Access a member: `O(1)`
- Update a member: `O(1)`
- Traversal in array of structs: `O(n)`

## 13. Practice Ideas

1. Create `Book` struct and find costliest book.
2. Store `Employee` records and sort by salary.
3. Build structure for `Complex` numbers and add/subtract them.
4. Use nested struct for `Address` inside `Student`.

## 14. Run the Example in This Folder

From `2.C-Essentials/struct`:

```bash
gcc main.c -o struct_demo
./struct_demo
```

The demo includes:

- Basic struct creation and member access
- Pass by value vs pointer
- Array of structures
- Nested structures
- Pointer to structure and dynamic allocation
