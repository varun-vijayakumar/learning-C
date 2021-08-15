/*
 * Reverse a LL using stack.
 */

#include <stdio.h>
#include <stdlib.h>

#define LL_LEN 15

typedef enum {
    false = 0,
    true,
} bool;

struct node {
    int data;
    struct node *next;
};

struct stack_node {
    struct node *ll_node;
    struct stack_node *next;
};

bool isEmpty (struct stack_node *head) {
    if (!head) {
        return true;
    } else {
        return false;
    }
}

void push (struct stack_node **stack_head, struct node *ll_node) {

    if (!ll_node) {
        return;
    }

    struct stack_node *newNode =
        (struct stack_node *) malloc(sizeof(struct stack_node));

    *newNode = (struct stack_node) {ll_node, NULL };

    if (!(*stack_head)) {
        *stack_head = newNode;
        return;
    }
    newNode->next = *stack_head;
    *stack_head = newNode;
    return;
}

void pop (struct stack_node **stack_head) {

    if (isEmpty(*stack_head)) {
        printf("Error : stack is empty to pop\n");
        return;
    }

    struct stack_node *temp = *stack_head;
    *stack_head = (*stack_head)->next;
    free(temp);

}

struct node* top (struct stack_node *stack_head) {
    if (isEmpty(stack_head)) {
        printf("Error : stack is empty, no top\n");
        return NULL;
    }

    return stack_head->ll_node;
}

/* copy LL node references to stack,
 * start printing from top of the stack to down.
 */

void print_reverse (struct node *head) {

    if (!head) {
        return;
    }

    struct node *temp = head;

    struct stack_node *stack = NULL;

    while (temp != NULL) {
        push (&stack, temp);
        temp = temp->next;
    }

    temp = top(stack);

    while (!isEmpty(stack)) {
        printf("%d ", top(stack)->data);
        pop(&stack);
    }

    printf("\n");
}

void print (struct node *head) {

    if (!head) {
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void build (struct node **head, int data) {
    struct node *newNode =
        (struct node *) malloc (sizeof(struct node));
    *newNode = (struct node) {data, NULL};

    if (!(*head)) {
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return;

}


int main () {

    struct node *ll_head = NULL;

    int iter = 0;
    for (iter = 0; iter < LL_LEN; iter++) {
        build(&ll_head, iter+1);
    }

    print(ll_head);

    print_reverse(ll_head);

    print(ll_head);
}
