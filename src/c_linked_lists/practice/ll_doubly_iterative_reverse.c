/*
 * Iterative Reverse of Doubly Linked List
 */

#include <stdio.h>
#include <stdlib.h>

#define LL_LEN 10

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void move_node (struct node **left, struct node **right) {

    if (!right) {
        return;
    }

    struct node *temp = *right;
    *right = (*right)->next;

    temp->next = NULL;
    temp->prev = NULL;

    if (*left) {
        (*left)->prev = temp;
    }
    temp->next = *left;
    *left = temp;
}

void reverse(struct node **source) {

    if (!source) {
        return;
    }

    struct node *temp = *source;
    struct node *temp_head = NULL;

    while (temp != NULL) {
        move_node(&temp_head, &temp);
    }

    *source = temp_head;

}


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

    for (iter = 0; iter < LL_LEN; iter++) {
        sorted_insert(&source, iter+10);
    }

    print(source);

    reverse(&source);

    print(source);
}
