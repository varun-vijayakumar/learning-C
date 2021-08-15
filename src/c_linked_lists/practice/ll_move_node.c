/*
 * Instead of creating a new node and pushing it onto the given list,
 * move_node() takes two lists, removes the front node from the
 * second list and pushes it onto the front of the first.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN  3
#define LL2_LEN  4

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

void move_node(struct node **left, struct node **right) {
    if (!(*right)) {
        return;
    }

    struct node *r_head = *right;

    *right = (*right)->next;
    r_head->next = NULL;

    if (!(*left)) {
        *left = r_head;
        return;
    }

    r_head->next = *left;
    *left = r_head;
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
	move_node(&left, &right);
	print(left);
	print(right);
}
