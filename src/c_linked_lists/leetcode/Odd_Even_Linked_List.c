/*
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes)
time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void move_node(struct ListNode** source, struct ListNode** dest) {
    struct ListNode *temp = *dest;
    if (!*source) {
        return;
    }

    if (!temp) {
        temp = *source;
        *source = (*source)->next;
        temp->next = NULL;
        *dest = temp;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *source;
    *source = (*source)->next;
    temp->next->next = NULL;
}

struct ListNode* oddEvenList(struct ListNode* head){

    if (!head) {
        return;
    }

    struct ListNode **current = &head;
    struct ListNode *left = NULL;
    struct ListNode *right = NULL;

    while (*current != NULL) {
        move_node(current, &left);
        move_node(current, &right);
    }

    struct ListNode *newHead = left;
    while (left->next != NULL) {
        left = left->next;
    }
    left->next = right;
    return newHead;
}

//SOLUTION 2 ( 8 ms)
struct ListNode* oddEvenList(struct ListNode* head){

    if (!head || !head->next) {
        return;
    }

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *right_side = even;
    while (odd && odd->next != NULL && even != NULL) {
        odd->next = odd->next->next;

        if (even->next) {
            even->next = even->next->next;
        }
        if (odd->next) {
            odd = odd->next;
        }
        even = even->next;
    }
    odd->next = right_side;
    return head;
}



