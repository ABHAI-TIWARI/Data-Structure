#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

static struct Node *create_node(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->next = NULL;
    return node;
}

static void insert_at_end(struct Node **head, int value) {
    struct Node *new_node = create_node(value);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

static void insert_at_beginning(struct Node **head, int value) {
    struct Node *new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

static int delete_by_value(struct Node **head, int value) {
    if (*head == NULL) {
        return 0;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    return 1;
}

static int search_value(struct Node *head, int value) {
    int position = 1;
    while (head != NULL) {
        if (head->data == value) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1;
}

static void print_list(struct Node *head) {
    if (head == NULL) {
        printf("List: empty\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf(" -> NULL\n");
}

static void free_list(struct Node **head) {
    struct Node *current = *head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main(void) {
    struct Node *head = NULL;

    printf("Singly Linked List Demo\n\n");

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    print_list(head);

    insert_at_beginning(&head, 5);
    print_list(head);

    if (delete_by_value(&head, 20)) {
        printf("Deleted value 20\n");
    } else {
        printf("Value 20 not found\n");
    }
    print_list(head);

    {
        int key = 30;
        int position = search_value(head, key);
        if (position != -1) {
            printf("Value %d found at position %d\n", key, position);
        } else {
            printf("Value %d not found\n", key);
        }
    }

    free_list(&head);
    print_list(head);

    return 0;
}
