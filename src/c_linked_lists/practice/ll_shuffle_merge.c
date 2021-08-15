/*
 * Given two lists, merge their nodes together to make one list,
 * taking nodes alternately between the two lists.
 * So ShuffleMerge() with {1, 2, 3} and {7, 13, 1}
 * should yield {1, 7, 2, 13, 3, 1}.
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

void shuffle_merge(struct node **left, struct node **right) {
    if (!(*left)) {
        *left = *right;
        *right = NULL;
        return;
    }

    if (!(*right)) {
        return;
    }

    struct node *current_left = *left;
    struct node *current_right = *right;
    struct node *temp = NULL;

    while (current_left->next != NULL) {
        temp = current_left->next;
        move_node(&(current_left->next), right);
        current_left = temp;
    }
    current_left->next = *right;
    *right = NULL;
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
	shuffle_merge(&left, &right);
	print(left);
	print(right);
}
