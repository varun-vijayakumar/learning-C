/*
 * Given the pointer to the head node of a linked list and a specific position.
 * Counting backwards from the tail node of the linked list, get the value of 
 * the node at the given position.
 * A position of 0 corresponds to the tail, 1 corresponds to the node before the 
 * tail and so on.
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

int get_nth_from_last(struct node *head, int pos) {

    if (!head) {
        return 0;
    }

    if (!(head->next) && !pos) {
        return head->data;
    }

    struct node *fast = head->next;
      
    int iter = 0, len = 0;
     
    while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            iter++;
    }

    len = iter* 2;
    iter = 0;

    fast = head;
    while (fast != NULL) {
        if (iter == (len - (pos))) {
           return fast->data;      
        }
        fast = fast->next;
        iter++;
    }
    return 0;
}

int main () {
    struct node *left = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&left, iter+10);
    }
    print(left);

	int data = get_nth_from_last(left, 3);
    printf("%d\n", data);
}
