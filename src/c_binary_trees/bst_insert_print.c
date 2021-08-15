/*
 * Binary Search Tree : insert and print
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false = 0,
    true = 1,
} bool;

typedef struct stack {
    int data;
    struct stack *next;
}Stack;

Stack *stack1 = NULL;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

/*Stack Operations.*/
Stack *newStackNode(int data) {
    Stack *new = (Stack *)malloc(sizeof(Stack));
    new->data = data;
    new->next = NULL;
    return new;
}
void push(int data) {
    if (!stack1) {
        stack1 = newStackNode(data);
        return;
    }
    Stack *temp = stack1;
    stack1 = newStackNode(data);
    stack1->next = temp;
}

void pop() {
    if (!stack1) {
        printf("Stack EMPTY\n");
        return;
    }
    Stack *temp = stack1;
    stack1 = stack1->next;
    free(temp);
}

void top() {
    if (!stack1) {
        printf("Stack EMPTY\n");
        return;
    }
    printf("top of stack : %d\n", stack1->data);
}

void printStack() {
    if (!stack1) {
        printf("Stack EMPTY\n");
        return;
    }
    Stack *temp = stack1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* newNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
/*LEFT, ROOT, RIGHT*/
void printInOrder(Node *root) {
    if (!root) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}
/*LEFT, RIGHT,  ROOT*/
void printPostOrder(Node *root) {
    if (!root) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

/* ROOT, LEFT, RIGHT*/
void printPreOrder(Node *root) {
    if (!root) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

Node* build(Node* root, int data) {
    if (!root) {
        return newNode(data);
    }
    if (root->data > data) {
        root->left = build(root->left, data);
    } else {
        root->right = build(root->right,data);
    }
    return root;
}

int size(Node *root) {
    if (!root) {
        return 0;
    }
    return (size(root->left) + 1 + size(root->right));
}

int maxDepth(Node *root) {
    if (!root) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);// + 1;
    if (left >= right) {
        return left + 1;
    } else {
        return right + 1;
    }
}
int min (int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int minDepth(Node *root) {
    if (!root) {
        return 0;
    }
    // Base case : Leaf Node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If left subtree is NULL, recur for right subtree
    if (!root->left)
        return minDepth(root->right) + 1;

    // If right subtree is NULL, recur for left subtree
    if (!root->right)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
/*    int left = minDepth(root->left);
    int right = minDepth(root->right);// + 1;
    return min(left, right) + 1;*/

}

bool lookup(Node *root, int data) {
    if (!root) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    if (root->data < data) {
        return lookup(root->right, data);
    } else {
        return lookup(root->left, data);
    }
}

int minValue(Node *root) {
    if (!root) {
        return -1;
    }

    if (!root->left) {
        return root->data;
    } else {
        return minValue(root->left);
    }
}

/*int sum = 0;
int total = 0;
void printPathWithSum(Node *root) {
    if (!root) {
        return;
    }
    sum = sum + root->data;
    push(root->data);
    if (sum == total) {
        printStack();
    }
    printPathWithSum(root->left);
    printPathWithSum(root->right);
    sum =  sum - root->data;
    pop();
}*/

/*
TODO : complete this.
void printPathWithSum(Node *root, int sum) {
    if (!root || sum < 0) {
        return;
    }
    int subSum = sum - root->data;
    push(root->data);

    if (sum == 0) {
        printStack();
    }

    printPathWithSum(root->left, subSum);
    subSum =  subSum + root->data;
    printPathWithSum(root->right, subSum);
    pop();
}*/


bool hasPathSum(Node* root, int sum){
    if (!root) {
        return false;
    }
    if (!root->right && !root->left) {
        if ((sum - root->data) == 0) {
            return true;
        }
    }
    int subSum = sum - root->data;
    return (hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum));
}

void printAllPaths(Node *root) {
    if (!root) {
        return;
    }

    push(root->data);
    if (root->left == NULL && root->right == NULL) {
        printStack();
    }
    printAllPaths(root->left);
    printAllPaths(root->right);
    pop();
}


void mirror(Node *root) {
    if (!root) {
        return;
    }

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

/*
 * * Alternate Mirror Solution
 * /
void mirror(Node *root) {
    if (!root) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

}*/
void doubleTree(Node *root) {
    if (!root) {
        return;
    }
/*    doubleTree(root->left);
    doubleTree(root->right);
    Node *new = newNode(root->data);
    Node *temp = root->left;
    root->left = new;
    new->left = temp;*/
    doubleTree(root->left);
    doubleTree(root->right);
    Node *new = newNode(root->data);
    Node *temp = root->left;
    root->left = new;
    new->left = temp;
    printPreOrder(root);
    printf("\n");


}

int main () {
    Node* root = NULL;
    root = build(root, 15);
    root = build(root, 3);
    root = build(root, 16);
    root = build(root, 5);
    root = build(root, 19);
    root = build(root, 6);
    root = build(root, 1);
/*    root = build(root, 4);
    root = build(root, 2);
    root = build(root, 5);
    root = build(root, 1);
    root = build(root, 3);*/
    printf("PreOrder : ");
    printPreOrder(root);
    puts("\n");
    printf("InOrder : ");
    printInOrder(root);
    puts("\n");
    printf("PostOrder : ");
    printPostOrder(root);
    puts("\n");
    printf("size      : %d\n", size(root));
    printf("maxdepth  : %d\n", maxDepth(root));
    printf("mindepth  : %d\n", minDepth(root));
    printf("minvalue  : %d\n", minValue(root));
    /*int data = 0;
    while(1) {
        scanf("%d",&data);
        if (data == -1)
            break;
        printf("%d exists : %s\n",data ,lookup(root, data) ? "yes" : "no");
    }*/
/*    int sum = 0;
    while(1) {
        printf("check sum : ");
        scanf("%d",&sum);
        if (sum == -1)
            break;
        printf("%d exists : %s\n",sum , hasPathSum(root, sum) ? "yes" : "no");
    }*/

/*    int total2 = 0;
    while (1) {
        printf("check sum : ");
        scanf("%d", &total2);
        if (total == -1)
            break;
        printPathWithSum(root,total2);
    }*/
    printAllPaths(root);
/*    printf("Mirror Tree ")
    printPostOrder(root);
    printf("\n");
    mirror(root);
    printPostOrder(root);
    printf("\n");*/
    printf("Double Tree ");
    printPreOrder(root);
    printf("\n");
    doubleTree(root);
    printPreOrder(root);
    printf("\n");
    
}


