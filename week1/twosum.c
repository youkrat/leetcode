#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Create a new empty list with a dummy head
ListNode* list_create() {
    ListNode* dummy = malloc(sizeof(ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    return dummy;
}

// Append a value to the end of the list
void list_add(ListNode* head, int val) {
    ListNode* n = malloc(sizeof(ListNode));
    n->val = val;
    n->next = NULL;

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

// Print list contents (skip dummy head)
void print_list(ListNode* head) {
    ListNode* temp = head->next;
    printf("{");
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) printf(", ");
        temp = temp->next;
    }
    printf("}\n");
}

// The LeetCode addTwoNumbers() function
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = malloc(sizeof(ListNode));
    dummy->next = NULL;

    ListNode* curr = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        ListNode* node = malloc(sizeof(ListNode));
        node->val = sum % 10;
        node->next = NULL;

        curr->next = node;
        curr = curr->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy->next;
}

int main(void) {
    // create lists: l1 = (2 -> 4 -> 3), l2 = (5 -> 6 -> 4)
    ListNode* l1 = list_create();
    ListNode* l2 = list_create();

    list_add(l1, 0);
    list_add(l1, 0);
    list_add(l1, 3);

    list_add(l2, 5);
    list_add(l2, 6);
    list_add(l2, 4);

    printf("l1 = "); print_list(l1);
    printf("l2 = "); print_list(l2);

    // add two numbers (skip dummy heads: use l1->next and l2->next)
    ListNode* sum = addTwoNumbers(l1->next, l2->next);

    // wrap result in a dummy head so we can print easily
    ListNode* result = list_create();
    result->next = sum;

    printf("sum = "); print_list(result);

    return 0;
}
