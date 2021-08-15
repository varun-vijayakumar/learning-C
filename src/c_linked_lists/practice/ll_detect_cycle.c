/*
 * Detect cycle in an LL.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL1_LEN 5
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

void print (struct node *head) {

    if (!head) {
        return;
    }

    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }

    printf("\n");
}

/*
 * Floyd's cycle detection algorithm. Have 2 pointers.
 * Move first pointer twice and the second one once, together.
 * If both pointers meet, loop exists.
 */
int cycle_detect (struct node *head) {

    if (!head || !(head->next)) {
        return 0;
    }

    struct node *fast = head;
    struct node *slow = head;

    while (fast != NULL && fast->next != NULL && slow != NULL) {

        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return 1;
        }

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

    struct node *temp = left;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = left;

    printf("cycle exists in the list :  %s\n",
            cycle_detect(left) ? "yes" : "no");

}
