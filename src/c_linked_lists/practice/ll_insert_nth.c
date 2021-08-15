/*
 * Given a list, insert a node at the Nth position.
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

void insert_nth(struct node **head, int index, int data) {

    struct node *current = *head;

    if (!current) {
        return;
    }

    int iter = 1;

    struct node *newNode = (struct node *) malloc (sizeof(struct node));

    *newNode = (struct node){data, NULL};


    if (!index) {
        newNode->next = (*head);
        *head = newNode;
        return;
    }

    while (current->next != NULL && iter < (index - 1)) {
        current = current->next;
        iter++;
    }

    newNode->next = current->next;

    current->next = newNode;

}
int main () {
    struct node *source = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, iter+10);
    }
    print(source);

    insert_nth(&source, 1, 8);


    print(source);

    insert_nth(&source, 0, 2);

    print(source);

    insert_nth(&source, 5, 4);

    print(source);

    insert_nth(&source, 5, 14);

    print(source);

    insert_nth(&source, 0, 14);

    print(source);

    insert_nth(&source, 3, 14);

    print(source);
}
