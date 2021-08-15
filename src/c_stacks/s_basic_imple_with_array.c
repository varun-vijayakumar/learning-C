/*
 * Basic stack implemention using arrays. Not the ideal implementation.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int array[MAX];
int top = -1;

typedef enum {
    false = 0,
    true = 1,
} bool;

bool isEmpty () {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

void push (int data) {
    if (top == MAX-1) {
        printf("Error : stack overflow\n");
        return;
    }
    top++;
    array[top] = data;
}

void pop() {
    if (isEmpty()) {
        printf("Error: no element to pop\n");
        return;
    }
    top--;
}

void s_top() {
    if (isEmpty()) {
        printf("Error: stack empty\n");
        return;
    }
    printf("Top : %d\n",array[top]);
}

void print() {
    int iter = 0;
    printf("\n");
    for (iter = 0; iter <= top; iter++) {
        printf("%d ",array[iter]);
    }
    printf("\n");
}

int main () {
    push(1);
    push(2);
    push(4);
    push(5);
    push(3);

    print();
    s_top();
    pop();

    print();
    s_top();
    pop();

    print();
    s_top();
    pop();

    print();
    s_top();
    pop();

    print();
    s_top();
    pop();

    print();
    s_top();
    pop();
}

