/*
 * Write an iterative Reverse() function that reverses a
 * list by rearranging all the .next pointers and the head pointer.
 * Ideally, Reverse() should only need to make one pass of the list. 
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

void move_node (struct node **left, struct node **right) {

    if (!(*right)) {
        return;
    }

    struct node *temp = NULL;

    temp = *right;
    *right= (*right)->next;
    temp->next = NULL;

    temp->next = *left;
    *left = temp;

}

void reverse (struct node **source) {
    if (!(*source)) {
        return;
    }

    struct node *temp = *source;
    struct node *temp_head = NULL;

    while (temp != NULL) {
        move_node(&temp_head, &temp);
    }

    *source = temp_head;

}

int main () {
    struct node *source = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, iter+10);
    }
    print(source);

    reverse(&source);

    print(source);
}
