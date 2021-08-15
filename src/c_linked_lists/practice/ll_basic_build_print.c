/*
 * Build and print linked list.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 2
#define LL2_LEN 3

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

int main () {
    struct node *left = NULL;
    struct node *right = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&left, iter+10);
    }
    print(left);

    for (iter = 0; iter < LL2_LEN; iter++) {
        build(&right, iter+20);
    }
	print(right);
}
