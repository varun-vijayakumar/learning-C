/*
 * Write a function AlternatingSplit() that takes one list and
 * divides up its nodes to make two smaller lists.
 * The sublists should be made from alternating elements in the original list.
 * So if the original list is {a, b, a, b, a}, then one sublist should be
 * {a, a, a} and the other should be {b, b}.
 */


#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN  20

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


void alternating_split(struct node *source,
                       struct node **left,
                       struct node **right) {
#if 0  /* solution 1*/
    if (!source) {
        return;
    }

	while (source != NULL) {
		move_node(left, &source);
		if (source != NULL) {
			move_node(right, &source);
        }
    }
#endif
	/* solution 2*/
    if (!source) {
        return;
    }

	int i = 0;
	struct node *current = source;
	struct node *cur_l = NULL;
	struct node *cur_r = NULL;
    struct node *temp = NULL;

	while (current !=NULL) {

		if (!(i%2)) {
            if (!cur_l) {
                cur_l = (struct node *) malloc(sizeof(struct node));
                *cur_l = (struct node){current->data, NULL};
                *left = cur_l;
            } else {

                cur_l->next  = (struct node *) malloc(sizeof(struct node));
                *(cur_l->next) = (struct node){current->data, NULL};
                cur_l = cur_l->next;


            }
        } else {
            if (!cur_r) {
                cur_r = (struct node *) malloc(sizeof(struct node));
                *cur_r = (struct node){current->data, NULL};
                *right = cur_r;
            } else {
                cur_r->next  = (struct node *) malloc(sizeof(struct node));
                *(cur_r->next) = (struct node){current->data, NULL};
                cur_r = cur_r->next;
            }
        }
        i++;
        current = current->next;
    }
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
    struct node *source = NULL;
    struct node *left = NULL;
    struct node *right = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&source, iter+10);
    }

    print(source);

	alternating_split(source, &left, &right);
	print(left);
	print(right);
    print(source);
}
