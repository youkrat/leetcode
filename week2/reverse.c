#include <stdio.h>

struct listNode{
    int val;
    struct listNode* next;
};

typedef struct listNode node;

struct ListNode* reverseList(struct ListNode* head) {
    if(head->next == NULL) return head;
    
}