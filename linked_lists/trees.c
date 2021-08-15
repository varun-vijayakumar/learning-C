//
//  trees.c
//  linked_lists
//
//  Created by VARUN VIJAYAKUMAR on 9/20/19.
//  Copyright © 2019 varun-c. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode (int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node *insert (struct node *root, int data) {
    if (!root) {
        return newNode(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left,data);
    } else {
        root->right = insert(root->right,data);
    }
    return root;
}

int size (struct node *root) {
    if (!root) {
        return 0;
    }
    return (size(root->left) + 1 + size(root->right));
}

int maxdepth(struct node *root) {
    if (!root) {
        return 0;
    }
    int left = maxdepth(root->left);
    int right = maxdepth(root->right);
    if (left <= right) {
        return left+1;
    } else {
        return right+1;
    }
}

int maxValue(struct node *root) {
    if (!root) {
        return 0;
    }
    if (root->right == NULL) {
        return root->data;
    }
    return maxValue(root->right);
    
}

int minValue(struct node *root) {
    if (!root) {
        return 0;
    }

    if (root->left == NULL) {
        return root->data;
    }
    return minValue(root->left);
#if 0
    // iterative method
    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
#endif
}

void printInOrder(struct node *root) {
    if (!root) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void printPostOrder(struct node *root) {
    if (!root) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

void printPreOrder(struct node *root) {
    if (!root) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int hasPathSum(struct node *root, int sum) {
    if (!root) {
        return (sum == 0);
    }
    sum = sum - root->data;
    return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
}
int main () {
    struct node *root = NULL;
    root = insert(root,5);
    root = insert(root,4);
    root = insert(root,11);
    root = insert(root,7);
    printf("Size of the tree : %d\n", size(root));
    root = insert(root,2);
    root = insert(root, 8);
    root = insert(root, 13);
    root = insert(root, 9);
    root = insert(root, 4);
    printf("Size of the tree : %d\n", size(root));
    printf("MAX Depth : %d\n", maxdepth(root));
    printf("MIN Value : %d\n", minValue(root));
    printf("MAX Value : %d\n", maxValue(root));
    printf("In Order\n");
    printInOrder(root);
    puts("");
    printf("Post Order\n");
    printPostOrder(root);
    puts("");
    printf("Pre Order\n");
    printPreOrder(root);
    puts("");
    int target_sum = 15;
    printf("has sum : %d ? : %s\n", target_sum, hasPathSum(root, target_sum) ? "yes" : "no");
}
