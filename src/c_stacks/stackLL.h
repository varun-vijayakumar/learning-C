/*
 * Implement stack using LL.
 */

#include <stdio.h>
#include <stdlib.h>


typedef enum bool_ {
    false = 0,
    true,
} bool;

struct stack_node {
    int data;
    struct stack_node *next;
};

extern bool isStackLLEmpty ();

extern void pushStackLL (int data);

extern void popStackLL ();

extern int topStackLL ();

extern void printStackLL ();

extern void stackLLInit();