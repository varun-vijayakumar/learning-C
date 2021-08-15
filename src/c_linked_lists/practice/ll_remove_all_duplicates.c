/*
 * Remove all instances of duplicates of a LL.
 *
 */

// Check for an alternate solution.

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true,
} bool;

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
    *right = (*right)->next;
    temp->next = NULL;

    if (!(*left)) {
        *left = temp;
        return;
    } else {
        struct node *current = *left;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = temp;
        return;
    }
}

void remove_duplicates(struct node **head) {
    if (!head) {
        return;
    }

    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;

    struct node *current = *head;
    int duplicate = false;
    struct node *temp = NULL;

    /* move to next only if there are no duplicates */
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            temp = current->next->next;
            free(current->next);
            current->next = temp;
            if (!temp) {
                free(current);
            }
            duplicate = true;
        } else {
            if (duplicate) {
                temp = current->next;
                free(current);
                current = temp;
            }
            duplicate = false;
            move_node(&(tail->next),&current);
        }
    }
    *head = dummy.next;
}

int main () {
    struct node *left = NULL;

    build(&left, 3);
    build(&left, 3);
    build(&left, 4);
    build(&left, 5);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);
    build(&left, 6);

    print(left);

    remove_duplicates(&left);

    print(left);

}
