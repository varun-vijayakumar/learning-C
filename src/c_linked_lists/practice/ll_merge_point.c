/*
 * Given pointers to the head nodes of 2 linked lists
 * that merge together at some point,
 * find the Node where the two lists merge.
 * It is guaranteed that the two head Nodes will be different, and neither will be NULL.
 */

//TODO : need to find a solution with hashmaps.

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 2
#define LL2_LEN 3
#define LL3_LEN 3

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

void merge_lists(struct node *left, struct node *right) {

    if (!left || !right) {
        return;
    }

    struct node *current = left;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = right;
}

int len(struct node *source) {
    if (!source) {
        return 0;
    }

    int iter = 0;

    while (source != NULL) {
        source = source->next;
        iter++;
    }

    return iter;
}

int merge_point(struct node *left, struct node *right) {

    if (!left || !right) {
        return 0;
    }


#if 0
    // 0(mn) complexity.
    struct node *temp = right;

    while (left != NULL) {
        while (right != NULL) {
            if (right == left) {
                return right->data;
            }
            right = right->next;
        }
        right = temp;
        left = left->next;
    }
#endif

    int len_left = len(left);
    int len_right = len(right);

    int iter = 0;

    int diff = 0;

    int right_long = 0;

    if (len_left < len_right) {
        diff = len_right - len_left;
        right_long = 1;
    } else {
        diff = len_left - len_right;
    }

    if (!right_long) {
        for (iter = 0; iter < diff; iter++) {
            if (!left) {
                return 0;
            }
            left = left->next;
        }
    } else {
        for (iter = 0; iter < diff; iter++) {
            if (!right) {
                return 0;
            }
            right = right->next;
        }
    }


    while (left != NULL && right != NULL) {
        if (left == right) {
            return left->data;
        }
        left = left->next;
        right = right->next;
    }

    return 0;

}

int main () {

    struct node *left = NULL;
    struct node *right = NULL;
    struct node *common = NULL;

    int iter = 0;
    for (iter = 0; iter < LL1_LEN; iter++) {
        build(&left, iter+10);
    }
    print(left);

    for (iter = 0; iter < LL2_LEN; iter++) {
        build(&right, iter+20);
    }
	print(right);

    for (iter = 0; iter < LL3_LEN; iter++) {
        build(&common, iter+30);
    }
    print(common);

    merge_lists(left, common);
    merge_lists(right, common);

    print (left);
    print (right);

    int merge_point_data = merge_point(left,right);

    printf("%d\n", merge_point_data);
}
