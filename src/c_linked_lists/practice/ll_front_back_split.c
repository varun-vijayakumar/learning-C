/*
 * Write a function AlternatingSplit() that takes one list and
 * divides up its nodes to make two smaller lists.
 * The sublists should be made from alternating elements in the original list.
 * So if the original list is {a, b, a, b, a}, then one sublist should be
 * {a, a, a} and the other should be {b, b}.
 */


#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 9

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


void front_back_split(struct node *source , struct node **left,
                      struct node **right) {
    if(!(source) || !(source->next)) {
        *left = source;
        return;
    }

    struct node *fast = source->next;
    struct node *slow = source;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

int main () {
    struct node *source = NULL;
    struct node *left = NULL;
    struct node *right = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, iter+1);
    }

    print(source);

	front_back_split(source, &left, &right);
    printf("left\n");
	print(left);
    printf("right\n");
	print(right);
}
