

/*
 * Reverse a string using stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int top;
    unsigned int size;
    char *array;
} stack;


typedef enum {
    false = 0,
    true = 1,
} bool;


bool isEmpty (stack *stk) {
    if (!stk) {
        return true;
    }

    if (stk->top == -1) {
        return true;
    } else {
        return false;
    }
}

void push (stack *stk, char data) {
    if (!stk) {
        return;
    }

    stk->top++;
    stk->array[stk->top] = data;
}

char pop (stack *stk) {
    if (isEmpty(stk)) {
        return -1;
    }

    return (stk->array[stk->top--]);
}


stack *create (unsigned int size) {

    stack *stk = (stack *) malloc (sizeof(stack));

    stk->size = size;
    stk->top = -1;
    stk->array = (char *) malloc (sizeof(char) * size);

    return stk;

}

void reverse (char a[]) {
    if (!a) {
        return;
    }

    int len = strlen(a);
    stack *stk = create(len);

    int iter = 0;

    for (iter = 0; iter < len; iter++) {
        push(stk, a[iter]);
    }

    for (iter = 0; iter < len; iter++) {
        a[iter] = pop(stk);
    }
}

int main () {
    char str[] = "This_is_a_test";
    reverse(str);
    printf("%s\n",str);
}

