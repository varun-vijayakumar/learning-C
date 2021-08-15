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

    struct node *temp = *right;
    *right = (*right)->next;
    temp->next = NULL;

    if (!(*left)) {
        *left = temp;
        return;
    }

    temp->next = *left;
    *left = temp;
}

void sorted_merge(struct node **sorted, struct node *left, struct node *right) {
#if 0 /* Solution 1 using recursion */
    if (!left) {
        *sorted = right;
        return;
    }

    if (!right) {
        *sorted = left;
        return;
    }

    struct node *result = NULL;

    if (left->data <= right->data) {
        result = left;
        sorted_merge(&(result->next),left->next, right);
    } else {
        result = right;
        sorted_merge(&(result->next),left, right->next);
    }
    *sorted = result;
    return;
#endif
    /* Solution 2 */
    struct node dummy;
    struct node *tail = &dummy;

    dummy.next = NULL;

    while (1) {
        if (!left) {
            tail->next = right;
            break;
        }

        if (!right) {
            tail->next = left;
            break;
        }

        if (left->data <= right->data) {
            move_node(&(tail->next),&left);
        } else {
            move_node(&(tail->next),&right);
        }

        tail = tail->next;
    }
    *sorted = dummy.next;
}

int main () {
    struct node *left = NULL;
    struct node *right = NULL;

    int iter = 0;
    build(&left, 20);
    build(&left, 22);
    build(&left, 24);
    build(&left, 26);
    build(&right, 21);
    build(&right, 23);
    build(&right, 25);
    build(&right, 100);

    print(left);
	print(right);

    struct node *sorted = NULL;
    sorted_merge(&sorted, left, right);
    left = NULL;
    right = NULL;
    print(sorted);
    print(left);
    print(right);
    //TODO : Free the mallocs.

}
