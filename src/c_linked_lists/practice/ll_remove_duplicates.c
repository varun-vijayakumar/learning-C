/*
 * Remove duplicates of a LL.
 */

#include <stdio.h>
#include <stdlib.h>


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

void remove_duplicates(struct node *head) {
    if (!head) {
        return;
    }

    struct node *current = head;

    /* move to next only if there are no duplicates */
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct node *temp = current->next->next;
            free(current->next);
            current->next = temp;
        } else {
            current = current->next;
        }
    }
}

int main () {
    struct node *left = NULL;

    build(&left, 3);
    build(&left, 3);
    build(&left, 3);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);
    build(&left, 7);
    build(&left, 8);

    print(left);

    remove_duplicates(left);

    print(left);

}
