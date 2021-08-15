/*
 *  build
 *  push
 *  pop
 *  delete_list
 *  length
 *  get_Nth
 *  insert_Nth
 *  sorted_insert
 *  insert_sort
 *  append
 *  move_node
 *  shuffle_merge
 *  front_back_split
 *  alternate_split
 *  remove_duplicates
 *  sorted_merge
 *  merge_sort
 *  sorted_intersect
 *  reverse
 *
 *  Created by VARUN VIJAYAKUMAR on 7/6/19.
 *  Copyright © 2019 varun-c. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node* next;
};
struct node * build() {
/*
    struct node *head = NULL;
    head = (struct node *) malloc (sizeof(struct node));
    head->data = 1;
    head->next = (struct node *) malloc (sizeof(struct node));
    head->next->data = 2;
    head->next->next = (struct node *) malloc (sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = NULL;
*/
    struct node *head = (struct node *) malloc (sizeof(struct node));
    struct node *second = (struct node *) malloc (sizeof(struct node));
    struct node *third = (struct node *) malloc (sizeof(struct node));
    
    assert( head && second && third);
    
    *head = (struct node ) { 1, second};
    *second = (struct node) { 2, third};
    *third = (struct node) { 3, NULL};
    
    return head;
}

uint32_t length(struct node *head) {
    struct node *current = head;
    uint32_t count = 0;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void dump_list(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nlength : %u\n", length(head));
}

void push (struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void append (struct node **head, int data) {
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (!*head) {
        *head = newNode;
        return;
    }
    
    struct node *current = *head;
    
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void append_with_push(struct node **head) {
    push(head, 50);
    struct node *tail = *head;
    for (int i = 1; i < 6; i++) {
        push(&tail->next, (*head)->data+i);
        tail = tail->next;
    }
}

void build_with_dummmy(struct node **head) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.data = 61;
    dummy.next = NULL;
    
    for (int i = 0; i < 12; i++) {
        push(&(tail->next), dummy.data+i);
        tail = tail->next;
    }
    *head = dummy.next;
}

void build_with_ref_ptr(struct node **head) {
    struct node **ref = head;
    
    for (int i = 200; i < 210; i++) {
        push(ref, i);
        ref = &((*ref)->next);
    }
}

void copy_list(struct node *source, struct node **dest) {
    struct node *current = source;
    struct node dummy;
    struct node *new_curr = &dummy;
    dummy.next = NULL;
    
    while (current != NULL) {
        push(&new_curr->next, current->data);
        new_curr = new_curr->next;
        current = current->next;
    }
    
    *dest = dummy.next;
}

void copy_list_with_ref(struct node * source, struct node **dest) {
    struct node **ref = dest;
    struct node *curr = source;
    
    while(curr != NULL) {
        push(ref, curr->data);
        ref = &((*ref)->next);
        curr = curr->next;
    }
}

int count (struct node *head, int data) {
    int count = 0;
    while (head != NULL) {
        if (head->data == data) {
            count++;
        }
        head = head->next;
    }
    return count;
}

int getNth (struct node *head, int index) {
    int idx = 0;
    while (head != NULL) {
        if (idx == index) {
            return head->data;
        }
        idx++;
        head = head->next;
    }
    return 0;
}

void delete(struct node **head) {
    struct node *current = *head;
    struct node *temp = NULL;
    
    while (current != NULL) {
        dump_list(current);
        temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
}

int pop_head (struct node **head) {
    struct node *newHead = NULL;
    int head_data = 0;
    if (!*head) {
        return -1;
    }
    newHead = (*head)->next;
    head_data = (*head)->data;
    free(*head);
    *head = newHead;
    return head_data;
}

void insert_Nth(struct node **head, int data, int index) {
    struct node *current = *head;
    struct node *temp = NULL;
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
            temp = current->next;
            push(&current->next, data);
            current->next->next = temp;
            return;
        }
        idx++;
        current = current->next;
    }
    
    push(&current->next, data);
}

void sorted_insert(struct node **head, int data) {
    struct node *current = *head;
    struct node *temp = NULL;
 
    if (!current || (data < current->data)) {
        push(&current, data);
        current->next = *head;
        *head = current;
        return;
    }
    while (current->next != NULL) {
        if (data < current->next->data) {
            temp = current->next;
            push(&current->next, data);
            current->next->next = temp;
            return;
        }
        current = current->next;
    }
    
    push(&current->next, data);
    return;
}


void sorted_insert_without_push(struct node **head, struct node* newNode) {
    struct node *current = *head;
    struct node *temp = NULL;
    
    if (!current || (newNode->data < current->data)) {
        temp = current;
        *head  = newNode;
        newNode->next = temp;
        return;
    }
    while (current->next != NULL) {
        if (newNode->data < current->next->data) {
            temp = current->next;
            current->next = newNode;
            newNode->next = temp;
            return;
        }

        current = current->next;
    }

    current->next = newNode;
    return;
}

void insert_sort (struct node **head) {
    struct node *current = *head;
    struct node *result = NULL;
    struct node *temp = NULL;
    
    if (!current) {
        return;
    }
    
    while (current != NULL) {
        temp = current->next;
        sorted_insert_without_push(&result, current);
        current = temp;
    }
    *head = result;
}

void append_lists(struct node **list1, struct node **list2) {
    struct node *current = *list1;
    
    if (!current) {
        *list1 = *list2;
        *list2 = NULL;
        return;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = *list2;
    *list2 = NULL;
}

void front_back_split(struct node *head, struct node **front, struct node **back) {
    struct node *slow = head;
    struct node *fast = head;
    *front = head;
    
    if (head->next == NULL) {
        *back = NULL;
        return;
    }
    
    while (fast != NULL && fast->next !=NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    *back = slow->next;
    slow->next = NULL;
}



void remove_duplicates(struct node *head) {
    struct node *current = head;
    struct node *temp = NULL;
    
    if (!head) {
        return;
    }
    
    while (current != NULL) {
        if (current->next != NULL && current->data == current->next->data) {
            temp = current->next->next;
            free(current->next);
            current->next = temp;
        } else {
            current = current->next;
        }
    }
}

int move_node(struct node **source, struct node **dest) {

    struct node *temp = *source;
    
    if (!temp) {
        return 0;
    }

    //move to head
    *source = temp->next;
    temp->next = *dest;
    *dest = temp;
/*
    //move to last.
    struct node *temp = *dest;
    
    if (!*source) {
        return 0;
    }
    if (!temp) {
        *dest = *source;
        *source = (*source)->next;
        (*dest)->next = NULL;
        return 0;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *source;
    *source = (*source)->next;
    temp->next->next = NULL;
*/
    return 1;
}

void alternate_split(struct node *head, struct node **left, struct node **right) {
   struct node *current = head;
    if (!current) {
        *left = NULL;
        *right = NULL;
        return;
    }
    while (current != NULL) {
        move_node(&current, left);
        if (current) {
            move_node(&current, right);
        }
    }
}

void shuffle_merge(struct node **left, struct node **right, struct node **list) {

    struct node dummy;
    dummy.next = NULL;
 
    struct node *tail = &dummy;

    while (1) {
        if (!*left) {
            tail->next = *right;
            break;
        }

        if (!*right) {
            tail->next = *left;
            break;
        }

        move_node(left, &tail->next);
        tail = tail->next;
        move_node(right, &tail->next);
        tail = tail->next;
    }
    *list = dummy.next;
    return;
}

void sorted_merge_with_local_ref(struct node **list1, struct node **list2, struct node **result) {
    struct node *current = NULL;
    struct node **ref = &current;
    
    while (1) {
        if (!(*list1)) {
            *ref = *list2;
            break;
        }
        if (!(*list2)) {
            *ref = *list1;
            break;
        }
        if ((*list1)->data <= (*list2)->data) {
            move_node(list1, ref);
        } else {
            move_node(list2, ref);
        }
        ref = &((*ref)->next);
    }
    *result = current;
    
}

//TODO : some issue in this one.
void sorted_merge_alternate(struct node **list1, struct node **list2, struct node **result) {

    if (!*list1) {
        *result = *list2;
        return;
    }
    if (!*list2) {
        *result = *list1;
        return;
    }
    
    while (*list1 != NULL && *list2 != NULL) {
        if ((*list1)->data <= (*list2)->data) {
            move_node(list1, result);
        } else {
            move_node(list2, result);
        }
    }
    
    if (*list1) {
        append_lists(result, list1);
    }
    if (*list2) {
        append_lists(result, list2);
    }

    return;
}

void sorted_merge_dummy(struct node *list1, struct node *list2, struct node **head) {
    struct node dummy;
    dummy.next = NULL;
    struct node *tail = &dummy;
    
    while (1) {
        if (!list1) {
            tail->next = list2;
            break;
        }
        if (!list2) {
            tail->next = list1;
            break;
        }
        if (list1->data <= list2->data) {
            move_node(&list1,&tail->next);
        } else {
            move_node(&list2,&tail->next);
        }
        tail = tail->next;
    }
    *head = dummy.next;
}

void fbs(struct node *head, struct node **front, struct node **back) {
    struct node *slow = head;
    struct node *fast = head->next;
    
    if (!head || head->next == NULL) {
        *front = head;
        *back = NULL;
    } else {
        slow = head;
        fast = head->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *front = head;
        *back = slow->next;
        slow->next = NULL;
    }
}

void merge_sort(struct node **headRef) {
    
    struct node *left = NULL;
    struct node *right = NULL;
    struct node *head = *headRef;
    
    if (!head || !head->next) {
        return;
    }
    
    front_back_split(head, &left, &right);

    merge_sort(&left);
    merge_sort(&right);
    //sorted_merge_with_local_ref(&left, &right, &head);
    sorted_merge_dummy(left, right, headRef);
    
}

void sorted_intersect(struct node *list1, struct node *list2, struct node **result) {
    struct node dummy;
    dummy.next = NULL;
    struct node *tail = &dummy;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            push(&(tail->next), list1->data);
            tail = tail->next;
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data < list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
    }
    *result = dummy.next;
}

void move_to_front(struct node **source, struct node **dest) {
    struct node *current = *source;
    if (!current) {
        return;
    }
    
    *source = (*source)->next;
    current->next = *dest;
    *dest = current;
    return;
}

void reverse (struct node **source) {
    struct node *current = *source;
    struct node *temp = NULL;
    if (!current) {
        return;
    }
    
    while (current != NULL) {
        //move_to_front(&current, &temp);
        move_node(&current, &temp);
    }
    *source = temp;
}

void reverse_list_alternate(struct node **source) {
    if (!*source) {
        return;
    }
    
    struct node *middle = *source;
    struct node *front = middle->next;
    struct node *back = NULL;
    
    while (1) {
        middle->next = back;
        if (front == NULL) {
            break;
        }
        back = middle;
        middle = front;
        front = front->next;
    }
    *source = middle;
}
    
int main(int argc, const char * argv[]) {
    // insert code here...
    struct node *head = build();
    dump_list(head);
    
    struct node *empty = NULL;
    dump_list(empty);
    
    for (int i = 10; i < 20; i++) {
        push(&head, i);
    }
    dump_list(head);
    
    append(&head, 99);
    dump_list(head);
    
    for (int i = 101; i < 105; i++) {
        append(&empty, i);
    }
    dump_list(empty);
    
    struct node *rand_list = NULL;
    append_with_push(&rand_list);
    dump_list(rand_list);
    
    struct node *dummy_list = NULL;
    build_with_dummmy(&dummy_list);
    dump_list(dummy_list);
    
    
    struct node *ref_list = NULL;
    build_with_ref_ptr(&ref_list);
    dump_list(ref_list);
    
    struct node *copied_list = NULL;
    copy_list(ref_list,&copied_list);
    dump_list(copied_list);
    
    append_with_push(&ref_list);
    dump_list(ref_list);
    dump_list(copied_list);
    
    struct node *copied_list_2 = NULL;
    copy_list_with_ref(rand_list,&copied_list_2);
    dump_list(copied_list_2);
    
    append(&rand_list, 13);
    dump_list(rand_list);
    dump_list(copied_list_2);
    
    append(&rand_list, 12);
    append(&rand_list, 11);
    append(&rand_list, 12);
    append(&rand_list, 11);
    append(&rand_list, 13);
    append(&rand_list, 13);
    dump_list(rand_list);
    
#if 0
    //COUNT
    int data = 0;
    int cnt = 0;
    while (1) {
        printf("Search : ");
        scanf("%d", &data);
        cnt =  count(rand_list, data);
        printf("%d : count = %d\n", data,cnt);
        if (!cnt) {
            append(&rand_list, data);
            dump_list(rand_list);
        }
    }

    //get Nth

    int idx = 0;
    int val = 0;
    while (1) {
        printf("index : ");
        scanf("%d", &idx);
        val =  getNth(rand_list, idx);
        printf("index : %d has val :  %d\n", idx, val);
    }
    delete(&rand_list);
    dump_list(rand_list);
    
    printf("POP TEST\n");
    dump_list(copied_list_2);
    while (length(copied_list_2)) {
        printf("%d\n", pop_head(&copied_list_2));
        dump_list(copied_list_2);
    }

    
    printf("INSERT Nth Test\n");
    struct node *newList = NULL;
    for (int i = 0; i < 10; i++) {
        insert_Nth(&newList, i, i);
    }
    dump_list(newList);
    
    insert_Nth(&newList, 14, 3);
    dump_list(newList);
    insert_Nth(&newList, 24, 12);
    dump_list(newList);
    for (int i = 12; i < 20; i++) {
        insert_Nth(&newList, i+40, i);
    }
    dump_list(newList);

    

    printf("SORTED INSERT\n");
    struct node *sortedList = NULL;
    for (int i = 0; i < 23; i++) {
        sorted_insert(&sortedList, i+3);
    }
    dump_list(sortedList);
    sorted_insert(&sortedList, 11);
    dump_list(sortedList);
    sorted_insert(&sortedList, 60);
    sorted_insert(&sortedList, 1);
    dump_list(sortedList);

    printf("SORTED INSERT\n");
    struct node *sortedList = NULL;
    struct node newNode1 = {12, NULL};
    struct node newNode2 = {61, NULL};
    struct node newNode3 = {1, NULL};

    for (int i = 0; i < 23; i++) {
        sorted_insert(&sortedList, i+3);
    }
    dump_list(sortedList);
    sorted_insert_without_push(&sortedList, &newNode1);
    dump_list(sortedList);

    sorted_insert_without_push(&sortedList, &newNode2);
    dump_list(sortedList);

    sorted_insert_without_push(&sortedList, &newNode3);
    dump_list(sortedList);
    
    printf("INSERT SORT\n");
    struct node *unsortedList = NULL;
    int j = 11;
    for (int i = 0; i < 12; i++, j--) {
        insert_Nth(&unsortedList, j, i);
    }
    dump_list(unsortedList);
    insert_sort(&unsortedList);
    dump_list(unsortedList);

    printf("APPEND LISTS\n");

    struct node *list1 = NULL;
    for (int i = 0; i < 12; i++) {
        insert_Nth(&list1, i, i);
    }
    dump_list(list1);

    struct node *list2 = NULL;
    int j = 40;
    for (int i = 0; i < 9; i++, j++) {
        insert_Nth(&list2, j, i);
    }
    dump_list(list2);

    append_lists(&list1, &list2);
    dump_list(list1);
    dump_list(list2);
    
    append_lists(&list2, &list1);
    dump_list(list1);
    dump_list(list2);
    
    printf ("FRONT BACK SPLIT\n");
    
    struct node *main_list = NULL;
    for (int i = 0; i < 5; i++) {
        insert_Nth(&main_list, i, i);
    }
    dump_list(main_list);
    struct node *front = NULL;
    struct node *back = NULL;
    front_back_split(main_list, &front, &back);
    dump_list(front);
    dump_list(back);

    printf("REMOVE DUPLICATES\n");
    struct node *dup_list = NULL;
    insert_Nth(&dup_list, 1, 0);
    insert_Nth(&dup_list, 2, 1);
    insert_Nth(&dup_list, 2, 2);
    insert_Nth(&dup_list, 2, 3);
    insert_Nth(&dup_list, 3, 4);
    insert_Nth(&dup_list, 3, 5);
    insert_Nth(&dup_list, 4, 6);
    insert_Nth(&dup_list, 5, 7);
    insert_Nth(&dup_list, 5, 8);
    dump_list(dup_list);
    remove_duplicates(dup_list);
    dump_list(dup_list);

    printf("MOVE NODES\n");

    struct node *source = NULL;
    for (int i = 0; i < 5; i++) {
        insert_Nth(&source, i, i);
    }
    struct node *dest = NULL;
    for (int i = 0; i < 4; i++) {
        insert_Nth(&dest, i+5, i);
    }
    dump_list(source);
    dump_list(dest);
    while(move_node(&source, &dest)) {
        ;
    }
    //move_node(&source, &dest);
    dump_list(source);
    dump_list(dest);
    
    printf("ALTERNATE SPLIT\n");
    struct node *left = NULL;
    struct node *right = NULL;
    alternate_split(dest, &left , &right);
    dump_list(left);
    dump_list(right);
    dump_list(dest);

    printf("SHUFFLE MERGE\n");
    struct node *shuff_merged_list = NULL;
    shuffle_merge(&left,&right, &shuff_merged_list);
    dump_list(shuff_merged_list);
    dump_list(left);
    dump_list(right);

    printf("SORTED MERGE\n");
    struct node *sorted_list = NULL;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        j = j+2;
        insert_Nth(&list1, j, i);
    }
    j = 3;
    for (i = 0; i < 5; i++) {
        insert_Nth(&list2, j, i);
        j = j+3;
    }
    dump_list(list1);
    dump_list(list2);
    //sorted_merge_with_local_ref(&list1, &list2, &sorted_list);
    sorted_merge_dummy(list1, list2, &sorted_list);
    dump_list(sorted_list);

    printf("MERGE SORT\n");
    int i = 0, j = 10;
    struct node *list = NULL;
    for (i = 0; i < 5; i++) {
        insert_Nth(&list, j--, i);
    }
    dump_list(list);
    merge_sort(&list);
    dump_list(list);
    printf("SORTED INTERSECT\n");
    struct node *intersec_list = NULL;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    int i = 0;
    int j = 2;
    for (i = 0; i < 6; i++) {
        insert_Nth(&list1, j, i);
        j = j+2;
    }
    insert_Nth(&list2, 1, 0);
    insert_Nth(&list2, 2, 1);
    insert_Nth(&list2, 3, 2);
    insert_Nth(&list2, 4, 3);
    insert_Nth(&list2, 6, 4);
    dump_list(list1);
    dump_list(list2);
    sorted_intersect(list1, list2, &intersec_list);
    dump_list(intersec_list);
#endif
    printf("REVERSE LIST \n");
    struct node *rev_list = NULL;
    int i = 0;
    int j = 2;
    for (i = 0; i < 6; i++) {
        insert_Nth(&rev_list, j, i);
        j = j+2;
    }
    dump_list(rev_list);
    reverse(&rev_list);
    dump_list(rev_list);
    reverse(&rev_list);
    dump_list(rev_list);
    dump_list(copied_list);
    reverse(&copied_list);
    dump_list(copied_list);
    reverse(&copied_list);
    dump_list(copied_list);

#if 0
    printf("REVERSE LIST : 3 PTRS\n");
    struct node *rev_list = NULL;
    int i = 0;
    int j = 2;
    for (i = 0; i < 6; i++) {
        insert_Nth(&rev_list, j, i);
        j = j+2;
    }
    dump_list(rev_list);
    reverse_list_alternate(&rev_list);
    dump_list(rev_list);
    dump_list(copied_list);
    reverse_list_alternate(&copied_list);
    dump_list(copied_list);
#endif

}
