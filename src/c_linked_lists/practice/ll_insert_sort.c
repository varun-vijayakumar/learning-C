/*
 * Write an InsertSort() function which given a list,
 * rearranges its nodesso they are sorted in increasing order.
 * It should use SortedInsert()
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

void insert_sort(struct node **head) {

	if (!head) {
		return;
    }

    struct node *current = *head;
    struct node *next = NULL;
    struct node *result = NULL;

    while (current != NULL) {
        next = current->next;
        sorted_insert(&result, current);
        current = next;
    }

    *head = result;

}

int main () {
    struct node *source = NULL;

    build(&source, 12);
    build(&source, 10);
    build(&source, 15);
    build(&source, 11);
    build(&source, 9);

    print(source);

    insert_sort(&source);

    print(source);
}
