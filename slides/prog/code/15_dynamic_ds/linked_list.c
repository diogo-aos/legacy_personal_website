
#include <stdio.h>
#include <stdlib.h>

// linked list struct for int, typedef capitalized
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// function to print linked list, include enumareation
void print_list(Node *head) {
    int i = 0;
    while (head != NULL) {
        printf("%d: %d\n", i, head->data);
        head = head->next;
        i++;
    }
}

// function to insert node at the end of the list
void insert(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

//function to delete node at index, free memory
void delete(Node **head, int index) {
    if (*head == NULL) {
        return;
    }

    Node *current = *head;
    Node *previous = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}


// main that creates a linked list
int main() {
    Node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    print_list(head);

    delete(&head, 1);

    print_list(head);

    return 0;
}