# Pointer to Structure in C - Detailed Tutorial

This folder explains **pointer to structure** in C with clear concepts and a runnable `main.c` demo.

## 1) What Is a Pointer to Structure?

A pointer to structure stores the address of a struct variable.

```c
typedef struct {
    int roll;
    char name[32];
    float marks;
} Student;

Student s1 = {101, "Aman", 88.5f};
Student *ptr = &s1;
```

- `s1` is a normal struct variable.
- `ptr` points to `s1`.

## 2) Accessing Members with Pointer

There are two ways:

```c
(*ptr).roll
ptr->roll
```

Both are same, but `->` is shorter and preferred.

## 3) Why Pointer to Struct Is Useful

- Avoid copying large structures in function calls.
- Modify original struct data from functions.
- Work with dynamic memory (`malloc`).
- Build linked lists, trees, and advanced data structures.

## 4) Pass Struct Pointer to Function

```c
void update_marks(Student *s, float new_marks) {
    s->marks = new_marks;
}
```

Call:

```c
update_marks(&s1, 95.0f);
```

The function edits the original student, not a copy.

## 5) Array of Structures with Pointer Traversal

```c
Student cls[3];
Student *p = cls;
```

- `p + i` points to the `i`th student.
- `(p + i)->marks` accesses marks of that student.

## 6) Dynamic Allocation for Struct Pointer

```c
Student *ps = (Student *)malloc(sizeof(Student));
```

Then use arrow operator:

```c
ps->roll = 301;
```

Finally free memory:

```c
free(ps);
ps = NULL;
```

## 7) NULL Safety

Always check pointer before access:

```c
if (s != NULL) {
    printf("%d\n", s->roll);
}
```

This prevents crashes and undefined behavior.

## 8) Common Mistakes

1. Using `.` with struct pointer (should use `->`).
2. Forgetting parentheses in `(*ptr).member`.
3. Not checking `malloc` result for `NULL`.
4. Forgetting `free()` for dynamically allocated struct.

## 9) Run the Code

From `2.C-Essentials/ptr-to-struct`:

```bash
make output
```

or manually:

```bash
gcc -Wall -Wextra -std=c11 main.c -o out
./out
```

## 10) What This Folder Demo Covers

The `main.c` file demonstrates:

- Struct creation
- Pointer to struct declaration
- `(*ptr).member` vs `ptr->member`
- Updating values through pointer
- Passing pointer to function
- Array of structs via pointers
- Dynamic struct allocation and free
- NULL pointer safety
