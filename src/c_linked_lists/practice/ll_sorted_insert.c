/*
 * Write a SortedInsert() function which given a list that is sorted in increasing order,
 * and a single node, inserts the node into the correct sorted position in the list.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 2

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

void sorted_insert (struct node **head, struct node *newNode) {

    if (!(*head) || (newNode->data < (*head)->data)) {

        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *current = *head;

    while (current->next != NULL && newNode->data > current->next->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

}

void insert(struct node **source, int data) {

    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    *newNode = (struct node) { data, NULL };

    sorted_insert(source, newNode);
}

int main () {
    struct node *source = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, (iter+10)*2);
    }
    print(source);

    insert(&source, 4);
    print(source);

    insert(&source, 21);
    print(source);

    insert(&source, 25);
    print(source);
}
