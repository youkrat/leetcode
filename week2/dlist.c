#include <stdio.h>
/*
typedef struct dnode {
    int val;
    struct dnode* next;
    struct dnode* prev;
    
    
} MyLinkedList;
typedef struct list{
    MyLinkedList* head;
    MyLinkedList* tail;
    int length;
}list;


list* myLinkedListCreate() {
    list* obj = malloc(sizeof(list));

    MyLinkedList* dhead = malloc(sizeof(MyLinkedList));
    MyLinkedList* dtail = malloc(sizeof(MyLinkedList));

    dhead->prev = NULL;
    dhead->next = dtail;

    dtail->next = NULL;
    dtail->prev = dhead;

    obj->head = dhead;
    obj->tail = dtail;
    obj->length = 0;

    return obj;
}


int myLinkedListGet(list* obj, int index) {
    if (index < 0 || index >= obj->length) return -1;

    if (index >= obj->length / 2) {
        MyLinkedList* temp = obj->tail->prev;
        for (int i = obj->length - 1; i > index; i--) {
            temp = temp->prev;
        }
        return temp->val;
    } else {
        MyLinkedList* temp = obj->head->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
}


void myLinkedListAddAtHead(list* obj, int val) {
    MyLinkedList* n = malloc(sizeof(MyLinkedList));
    //checking for successful memory allocation
    if (!n) return;

    MyLinkedList* temp = obj->head->next;

    n->val = val;
    n->prev = obj->head;
    n->next = temp;

    obj->head->next = n;
    temp->prev = n;

    obj->length++;
}


void myLinkedListAddAtTail(list* obj, int val) {
    MyLinkedList* n = malloc(sizeof(MyLinkedList));
    if (!n) return;

    MyLinkedList* temp = obj->tail->prev;

    n->val = val;
    n->prev = temp;
    n->next = obj->tail;

    temp->next = n;
    obj->tail->prev = n;

    obj->length++;
}

void myLinkedListAddAtIndex(list* obj, int index, int val) {
    if (index < 0 || index > obj->length) return;

    MyLinkedList* temp;

    if (index >= obj->length / 2) {
        temp = obj->tail;
        for (int i = obj->length; i > index; i--) {
            temp = temp->prev;
        }
    } else {
        temp = obj->head->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }

    MyLinkedList* n = malloc(sizeof(MyLinkedList));
    if (!n) return;

    n->val = val;
    n->prev = temp->prev;
    n->next = temp;

    temp->prev->next = n;
    temp->prev = n;

    obj->length++;
}


void myLinkedListDeleteAtIndex(list* obj, int index) {
    if (index < 0 || index >= obj->length) return;

    MyLinkedList* temp;

    if (index >= obj->length / 2) {
        temp = obj->tail->prev;
        for (int i = obj->length - 1; i > index; i--) {
            temp = temp->prev;
        }
    } else {
        temp = obj->head->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
    obj->length--;
}


void myLinkedListFree(list* obj) {
    if (!obj) return;

    MyLinkedList* curr = obj->head;

    while (curr != NULL) {
        MyLinkedList* next = curr->next;
        free(curr);
        curr = next;
    }

    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

#include <stdlib.h>

/*
===============================================================================
 Doubly Linked List — LeetCode 707 (Design Linked List)
===============================================================================

 OVERVIEW
 --------
 This implementation defines a doubly linked list using:
   - A LIST OBJECT (MyLinkedList)
   - INTERNAL NODE STRUCTS (Node)
   - Dummy head and dummy tail sentinels

 The design exactly matches LeetCode 707's required invariant:
   -> MyLinkedList represents the LIST OBJECT, not a node.

 All operations maintain strict structural invariants to simplify edge cases.

===============================================================================
 CORE INVARIANTS (ALWAYS TRUE)
 ------------------------------------------------------------------------------
 1. head and tail are dummy sentinel nodes
 2. head->prev == NULL
 3. tail->next == NULL
 4. head->next points to:
      - first real node, OR
      - tail if list is empty
 5. tail->prev points to:
      - last real node, OR
      - head if list is empty
 6. length == number of REAL nodes (sentinels not counted)
 7. All real nodes are strictly between head and tail

 Because of sentinels:
   - No operation needs special cases for empty list
   - No NULL neighbor checks are required during insertion/deletion

===============================================================================
 DATA STRUCTURES
===============================================================================
*/

/* -----------------------------
   Node (internal, not exposed)
   -----------------------------
   Represents a single element in the list.
*/
typedef struct Node {
    int val;              // value stored in the node
    struct Node* next;    // pointer to next node
    struct Node* prev;    // pointer to previous node
} Node;

/* -----------------------------
   MyLinkedList (public object)
   -----------------------------
   Represents the entire linked list.
*/
typedef struct MyLinkedList {
    Node* head;           // dummy head sentinel
    Node* tail;           // dummy tail sentinel
    int length;           // number of real nodes
} MyLinkedList;


/*
===============================================================================
 FUNCTION: myLinkedListCreate
===============================================================================
 Purpose:
   Initializes an empty linked list with dummy head and tail.

 Post-condition:
   head <-> tail
   length = 0
*/
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    if (!obj) return NULL;

    Node* dhead = malloc(sizeof(Node));
    Node* dtail = malloc(sizeof(Node));
    if (!dhead || !dtail) return NULL;

    dhead->prev = NULL;
    dhead->next = dtail;

    dtail->next = NULL;
    dtail->prev = dhead;

    obj->head = dhead;
    obj->tail = dtail;
    obj->length = 0;

    return obj;
}


/*
===============================================================================
 FUNCTION: myLinkedListGet
===============================================================================
 Purpose:
   Returns the value at index (0-based).

 Rules:
   - If index is invalid, return -1
   - Otherwise, return the node's value

 Optimization:
   Traverses from head or tail depending on index position.
*/
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length) return -1;

    if (index >= obj->length / 2) {
        // Traverse backward from tail
        Node* temp = obj->tail->prev;
        for (int i = obj->length - 1; i > index; i--) {
            temp = temp->prev;
        }
        return temp->val;
    } else {
        // Traverse forward from head
        Node* temp = obj->head->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
}


/*
===============================================================================
 FUNCTION: myLinkedListAddAtHead
===============================================================================
 Purpose:
   Inserts a new node before the first element.

 Effect:
   head <-> A   becomes   head <-> new <-> A

 Time Complexity:
   O(1)
*/
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* n = malloc(sizeof(Node));
    if (!n) return;

    Node* temp = obj->head->next;

    n->val = val;
    n->prev = obj->head;
    n->next = temp;

    obj->head->next = n;
    temp->prev = n;

    obj->length++;
}


/*
===============================================================================
 FUNCTION: myLinkedListAddAtTail
===============================================================================
 Purpose:
   Appends a new node after the last element.

 Effect:
   A <-> tail   becomes   A <-> new <-> tail

 Time Complexity:
   O(1)
*/
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* n = malloc(sizeof(Node));
    if (!n) return;

    Node* temp = obj->tail->prev;

    n->val = val;
    n->prev = temp;
    n->next = obj->tail;

    temp->next = n;
    obj->tail->prev = n;

    obj->length++;
}


/*
===============================================================================
 FUNCTION: myLinkedListAddAtIndex
===============================================================================
 Purpose:
   Inserts a node before the node at position index.

 Rules:
   - 0 <= index <= length -> insert
   - index == length -> insert at tail
   - otherwise -> do nothing
*/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->length) return;

    Node* temp;

    if (index >= obj->length / 2) {
        temp = obj->tail;
        for (int i = obj->length; i > index; i--) {
            temp = temp->prev;
        }
    } else {
        temp = obj->head->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }

    Node* n = malloc(sizeof(Node));
    if (!n) return;

    n->val = val;
    n->prev = temp->prev;
    n->next = temp;

    temp->prev->next = n;
    temp->prev = n;

    obj->length++;
}


/*
===============================================================================
 FUNCTION: myLinkedListDeleteAtIndex
===============================================================================
 Purpose:
   Deletes the node at position index.

 Rules:
   - Valid indices: 0 <= index < length
   - Invalid index -> do nothing
*/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length) return;

    Node* temp;

    if (index >= obj->length / 2) {
        temp = obj->tail->prev;
        for (int i = obj->length - 1; i > index; i--) {
            temp = temp->prev;
        }
    } else {
        temp = obj->head->next;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
    obj->length--;
}


/*
===============================================================================
 FUNCTION: myLinkedListFree
===============================================================================
 Purpose:
   Frees all memory associated with the list.

 Frees:
   - All real nodes
   - Dummy head
   - Dummy tail
   - List object itself
*/
void myLinkedListFree(MyLinkedList* obj) {
    if (!obj) return;

    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    free(obj);
}
