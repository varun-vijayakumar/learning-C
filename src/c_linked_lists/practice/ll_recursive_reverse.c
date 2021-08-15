/*
 * Recursive Reverse of LL.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 15

struct node {
    int data;
    struct node *next;
};

void build(struct node **head, int data) {
	struct node *newNode = (struct node *) malloc (sizeof(struct node));
	*newNode = (struct node){data, NULL};

	if (!(*head)) {
		*head = newNode;
		return;
	}

    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void print(struct node *head) {
    if (!head) {
        return;
    }

    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void recursive_reverse (struct node **head) {

    if (!(*head)) {
        return;
    }

    struct node *first = *head;
    struct node *rest = first->next;

    if (!rest) {
        return;
    }

    recursive_reverse(&rest);

    //reverse links.
    first->next->next = first;
    first->next = NULL;

    //head is now at the tail
    *head = rest;
}

int main () {
    struct node *source = NULL;
    struct node *right = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, iter+10);
    }
    print(source);

    printf("reversing\n");
    recursive_reverse(&source);

    print(source);
}
