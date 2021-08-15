/*
 * Write a reverse_print() function that prints the contents of an LL in the
 * reverse order without reversing the actual LL.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 10

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

void reverse_print(struct node *head) {
    if (!head) {
        return;
    }

    reverse_print(head->next);
    printf("%d ",head->data);
}

int main () {
    struct node *source = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, iter+10);
    }
    print(source);

    reverse_print(source);

    printf("\n");
}
