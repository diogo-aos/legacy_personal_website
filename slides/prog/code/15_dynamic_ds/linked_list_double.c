#include <stdio.h>
#include <stdlib.h>

// linked list struct for int, typedef capitalized
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// linked list struct for int, typedef capitalized
typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

// function to print linked list, include enumeration and size
void print_list(List *list) {
    int i = 0;
    Node *current = list->head;
    
    printf("Size: %d\n", list->size);
    while (current != NULL) {
        printf("\t%d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

// function to insert node at the end of the list
void insert(List *list, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        (list->tail)->next = new_node;
    }

    list->tail = new_node;
    list->size++;
}

//function to delete node at index, free memory
void delete(List *list, int index) {
    if (list->head == NULL) {
        return;
    }

    Node *current = list->head;
    int i = 0;

    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        return;
    }

    if (current->prev == NULL) {
        list->head = current->next;
    } else {
        current->prev->next = current->next;
    }

    if (current->next == NULL) {
        list->tail = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    free(current);
    list->size--;
}


// main that creates a linked list
int main() {
    List list = {NULL, NULL, 0};

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);

    print_list(&list);

    delete(&list, 1);

    print_list(&list);


    return 0;
}