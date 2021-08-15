/*
 * Binary Search Tree : Max Height/ Max Depth.
 *
 * max_depth = max(max dept of left subtree,
 *                  max depth of right subtree)
 *                  + 1
 * if tree is empty, max is 0.
 * Else,
 *      find max of left.
 *      find max of right.
 *      if left max > right max, return left max + 1;
 *      else right max + 1
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void new_node (struct node **node, int data) {

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    *newNode = (struct node) { data, NULL, NULL};
    *node = newNode;
    return;
}

void insert (struct node **node, int data) {
    if (!(*node)) {
        new_node(node,data);
        return;
    }

    if (data <= (*node)->data) {
        return insert(&((*node)->left), data);
    } else {
        return insert(&((*node)->right), data);
    }
}

int max_depth (struct node *node) {

    if (!node) {
        return 0;
    }

    int left_depth = max_depth(node->left);
    int right_depth = max_depth(node->right);

    if (left_depth > right_depth) {
        return left_depth+1;
    } else {
        return right_depth+1;
    }
}

int main () {
    struct node *root = NULL;

    insert (&root, 11);
    insert (&root, 10);
    insert (&root, 13);
    insert (&root, 8);
    insert (&root, 9);
    insert (&root, 5);

    printf("Height/MaxDepth = %d\n", max_depth(root));

}
