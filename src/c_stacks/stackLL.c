/*
 * Implement stack using LL.
 */

#include "stackLL.h"

struct stack_node *STACK;

bool isStackLLEmpty () {

    if (STACK == NULL) {
        //printf("stack empty\n");
        return true;
    } else {
        //printf("stack not empty\n");
        return false;
    }
}

void pushStackLL (int data) {

    struct stack_node *newNode =
        (struct stack_node *) malloc(sizeof(struct stack_node));

    *newNode = (struct stack_node){ data, NULL };

    if (!(STACK)) {
        STACK = newNode;
        return;
    }

    newNode->next = STACK;
    STACK = newNode;
    return;
}

void popStackLL () {

    if (isStackLLEmpty()) {
        printf("Error : stack is empty to pop\n");
        return;
    }

    struct stack_node *temp = STACK;
    STACK = (STACK)->next;
    free(temp);

}

int topStackLL () {
    if (isStackLLEmpty()) {
        printf("Error : stack is empty, no top\n");
        return -1;
    }

    return STACK->data;
}


void printStackLL () {

    if (isStackLLEmpty()) {
        printf("Error : stack is empty\n");
        return;
    }

    struct stack_node *head = STACK;
    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }

    printf("\n");
    return;
}

void stackLLInit() {
    while(!isStackLLEmpty()) {
        popStackLL();
    }
    STACK = NULL;
}
