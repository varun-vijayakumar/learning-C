/*
 * Sort a linked list using merge_sort algorithm
 * in the ascending order without recursive merge.
 * Given a list {5,4,3,1,2}
 * it should yield {1, 2, 3, 4 , 5}.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 30

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


void move_node (struct node **left,
                struct node **right) {
    
    if (!right) {
        return;
    }

    struct node *temp = *right;
    *right = (*right)->next;
    temp->next = NULL;


    temp->next = *left;
    *left = temp;

    return;
}

void non_recursive_merge (struct node **source,
                          struct node *left,
                          struct node *right) {

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

    *source = dummy.next;

}


void front_back_split(struct node *source,
                      struct node **left,
                      struct node **right) {

    if (!source || !(source->next)) {
        *left = source;
        *right = NULL;
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


void merge_sort(struct node **source) {

    if (!(*source) || !(*source)->next) {
        return;
    }

    struct node *head = *source;
    struct node *left;
    struct node *right;

    front_back_split(head, &left, &right);

    merge_sort(&left);
    
    merge_sort(&right);

    non_recursive_merge(source, left, right);

}
int main () {
    struct node *source = NULL;
    struct node *right = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, 200 - iter);
    }
    print(source);
    merge_sort(&source);
    printf("__sorted list__ \n");
    print(source);
}
