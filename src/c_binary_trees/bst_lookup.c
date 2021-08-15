/*
 * Binary Search Tree : Lookup a value in tree (recursion)
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


typedef enum {
    false = 0,
    true = 1,
} bool;

static bool lookup (struct node *node, int target) {

    if (!node) {
        return false;
    } else if (target == node->data) {
        return true;
    } else if (target < node->data) {
        return lookup(node->left, target);
    } else {
        return lookup(node->right, target);
    }
}


void new_node (struct node **node, int data) {

    struct node *newNode = (struct node *) malloc (sizeof(struct node));

    *newNode = (struct node) {data, NULL, NULL};

    *node = newNode;
}

void insert (struct node **node, int data) {

    if (!(*node)) {
        new_node(node, data);
        return;
    } else if (data <= (*node)->data) {
        return insert(&((*node)->left), data);
    } else {
        return insert(&((*node)->right), data);
    }
}

int main () {

    struct node *node = NULL;

    insert (&node, 10);
    insert (&node, 8);
    insert (&node, 12);

    int target = 0;

    printf("enter value to search : ");
    scanf("%d",&target);

    bool found = lookup(node, target);
    printf("%s\n", found ? "YES" : "NO");
}
