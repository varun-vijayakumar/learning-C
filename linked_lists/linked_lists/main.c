//
//  main.c
//  linked_lists
//
//  Created by VARUN VIJAYAKUMAR on 8/3/19.
//  Copyright © 2019 varun-c. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

uint32_t length(struct ListNode *head) {
    struct ListNode *current = head;
    uint32_t count = 0;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void dump_list(struct ListNode *head) {
    struct ListNode *current = head;
    
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\nlength : %u\n", length(head));
}

void push (struct ListNode **head, int data) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    *newNode = (struct ListNode){data, NULL};
    *head = newNode;
}

void insert_Nth(struct ListNode **head, int data, int index) {
    struct ListNode *current = *head;
    struct ListNode *temp = NULL;
    int idx = 0;
    
    if (!current && !index) {
        push(&current, data);
        *head = current;
        return;
    } else if (!current && index) {
        return;
    } else if (current && !index) {
        push(&temp, data);
        temp->next = current;
        *head = temp;
        return;
    }
    
    while (current->next != NULL) {
        if (idx == index-1) {
            temp = current->next->next;
            push(&current->next, data);
            current->next->next = temp;
            return;
        }
        idx++;
        current = current->next;
    }
    
    push(&current->next, data);
}

void reverse(struct ListNode **head) {
    if (!head) {
        return ;
    }
    struct ListNode *back = NULL;
    struct ListNode *middle = *head;
    struct ListNode *front = middle->next;
    
    while (1) {
        middle->next = back;
        if (!front) {
            break;
        }
        back = middle;
        middle = front;
        front = front->next;
    }
    *head = middle;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    
    int pos = 1;
    
    if (!head) {
        return NULL;
    }
    
    struct ListNode *current = head;
    struct ListNode *temp = NULL;
    struct ListNode *reversed = NULL;
    struct ListNode *reversed_last = NULL;
    struct ListNode *last = NULL;
    
    while (current !=NULL) {
        if (pos == 1 && m == 1) {
            reversed_last = current;
            reversed = current;
        }
        if (pos == m-1) {
            temp = current;
            reversed_last = temp->next;
            reversed = temp->next;
        }
        if (pos == n) {
            last = current->next;
            current->next = NULL;
            break;
        }
        current = current->next;
        pos++;
    }

    reverse(&reversed);
    if (temp) {
        temp->next = reversed;
    }
    reversed_last->next = last;
    if (m == 1) {
        return reversed;
    } else {
        return head;
    }
}



#if 0
int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode *rev_list = NULL;
    int i = 0;
    int j = 2;
    for (i = 0; i < 6; i++) {
        insert_Nth(&rev_list, j, i);
        j = j+2;
    }
    dump_list(rev_list);
    int start = 0;
    int end = 0;
    while (1) {
        printf("Enter range - start end : ");
        scanf("%d %d",&start, &end);
        rev_list = reverseBetween(rev_list, start, end);
        dump_list(rev_list);
    }
}
#endif
