/*
 * Build and print linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL1_LEN 2
#define LL2_LEN 3
typedef enum {
    false = 0,
    true = 1,
} bool;
struct node{
    int data;
    struct node *next;
};

struct node *createNewNode(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void build (struct node **root, int data) {
    if (!root) {
        *root = createNewNode(data);
        return;
    }
    struct node *newNode = createNewNode(data);
    newNode->next = *root;
    (*root) = newNode;
}

void printList(struct node *root) {
    if (!root) {
        return;
    }
    struct node* current = root;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
struct node *insertNth(struct node *root, int data, int pos) {
    int index = 0;
    struct node *current = root;
    if (!root) {
        return createNewNode(data);
    }

    struct node *temp = NULL;
    if (pos == 0) {
        temp = root;
        root = createNewNode(data);
        root->next = temp;
        return root;
    }

    while(pos != 0 && current->next != NULL) {
        if (index == pos-1) {
            break;
        }
        index++;
        current = current->next;
    }
    temp = current->next;
    current->next = createNewNode(data);
    current->next->next = temp;
    return root;
}

void deleteNode(struct node *root, int pos) {
    struct node *current = root;
    int idx = 0;
    if (!root) {
        return;
    }
    struct node *temp = NULL;
    while (current->next != NULL) {
        if (idx == pos - 1) {
            break;
        }
        current = current->next;
        idx++;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

char STACK[6];
int topOfStack = -1;

char top() {
    return STACK[topOfStack];
}

void push(char x) {
    if (topOfStack == 6) {
        printf("Stack Overflow\n");
        return;
    }
    topOfStack++;
    STACK[topOfStack] = x;
}

bool isEmpty() {
    return topOfStack < 0 ? true : false;
}

char pop() {
    if(isEmpty()) {
        return '\0';
    }
    topOfStack--;
    return STACK[topOfStack+1];
}

struct node *STACKLIST = NULL;

void pushStack(char data) {
    struct node *temp = STACKLIST;
    STACKLIST = createNewNode(data);
    STACKLIST->next = temp;
}

char popStack() {
    struct node *temp = STACKLIST;
    STACKLIST = STACKLIST->next;
    char data = temp->data;
    free(temp);
    return data;
}

bool isStackEmpty() {
    return STACKLIST == NULL ? true : false;
}

char topStack() {
    return STACKLIST != NULL ? STACKLIST->data : -1;
}


int main() {
    struct node *root = NULL;
    int i;
    for ( i = 0; i < 5; i++) {
        build(&root, i+10);
    }
    printList(root);
    root = insertNth(root, 20, i+3);
    printList(root);
    root = insertNth(root, 30, 0);
    printList(root);

    struct node *list2 = NULL;
    for (i = 0; i < 6; i++) {
        list2= insertNth(list2, i+50, i);
    }
    printList(list2);
    deleteNode(list2, 3);
    printList(list2);

    for (int j = 1; j < 10; j++) {
        push(j);
    }
/*
    push(1);
    push(2);
    printf("Top : %d\n", top());
    printf("pop : %d\n", pop());
    printf("isEmpty : %s\n", isEmpty() ? "empty" : "notEmpty");
    push(25);
    printf("Top : %d\n", top());
    printf("isEmpty : %s\n", isEmpty() ? "empty" : "notEmpty");
    printf("pop : %d\n", pop());
    printf("isEmpty : %s\n", isEmpty() ? "empty" : "notEmpty");

    printf("LLSTACK : isEmpty : %s\n", isStackEmpty() ? "yes" : "no");
    pushStack(100);
    pushStack(200);
    printf("LLSTACK : isEmpty : %s\n", isStackEmpty() ? "yes" : "no");
    printf("LLSTACK : Top : %d\n", topStack());
    printf("LLSTACK : pop : %d\n", popStack());
    printf("LLSTACK : Top : %d\n", topStack());
    printf("LLSTACK : pop : %d\n", popStack());
    printf("LLSTACK : Top : %d\n", topStack());
    printf("LLSTACK : isEmpty : %s\n", isStackEmpty() ? "yes" : "no");
    pushStack(400);
    printf("LLSTACK : isEmpty : %s\n", isStackEmpty() ? "yes" : "no");
    printf("LLSTACK : Top : %d\n", topStack());

    */
    while(!isEmpty()) {
        printf("poping stack\n");
        pop();
    }
    
    char String[6] = "varun";
    int len = strlen(String);
    for (i = 0; i < len; i++) {
        push(String[i]);
    }



    for (i = 0 ; i < len ; i++) {
        String[i] = pop();
        //pop();
    }

    printf("reversed string : %s\n", String);

    char String2[] = "california";
    int lenString = strlen(String2);
    for (i = 0; i < lenString; i++) {
        pushStack(String2[i]);
    }

    for (i = 0; i < lenString; i++) {
        String2[i] = popStack();
    }

    printf("reverserd string2 : %s, isStackEmpty : %c\n", String2, isStackEmpty() ? 'y' : topStack());

    


}