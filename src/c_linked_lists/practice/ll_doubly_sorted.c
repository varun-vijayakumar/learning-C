/*
 * Write a SortedInsert() function for a double linked list
 * that is sorted in increasing order, and a single node, inserts the node
 * into the correct sorted position in the list.
 */
#include <stdio.h>
#include <stdlib.h>

#define LL_LEN 5
struct node {
    int data;
    struct node *prev;
    struct node *next;
};


void sorted_insert(struct node **head, int data) {
    struct node *newNode = (struct node*) malloc (sizeof (struct node));
    *newNode = (struct node) {data, NULL, NULL};

    if (!(*head)) {
        *head = newNode;
        return;
    }

    if ( data < (*head)->data) {
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL && data >= current->next->data) {
            current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    newNode->prev = current;
}


void print(struct node* head) {
    if (!head) {
        return;
    }

    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }

    printf("\n");
}

int main () {
    struct node *source = NULL;

    int iter = 0;

    sorted_insert(&source, 10);
    sorted_insert(&source, 9);
    sorted_insert(&source, 12);
    sorted_insert(&source, 1);
    sorted_insert(&source, 2);
    sorted_insert(&source, 11);
    sorted_insert(&source, 4);
    print(source);

}
