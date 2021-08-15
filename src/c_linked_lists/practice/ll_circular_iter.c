/*
 * Create a circular linked list and print data of each node iteratively.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL_LEN 15

struct node {
    int data;
    struct node *prev;
    struct node *next;
};


void build (struct node **head, int data) {

    struct node *newNode = (struct node *) malloc (sizeof(struct node));

    *newNode = (struct node) {data, NULL};

    if (!(*head)) {
        *head = newNode;
        return;
    }

    struct node *current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;

    return;
}

void print_circular(struct node* head) {
    if (!head) {
        return;
    }

    struct node *current = head;

    do {
        printf("%d ",current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main () {
    struct node *source = NULL;

    int iter = 0;

    for (iter = 0; iter < LL_LEN; iter++) {
        build(&source, iter+1);
    }

    struct node *current = source;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = source;

    print_circular(source);

}
