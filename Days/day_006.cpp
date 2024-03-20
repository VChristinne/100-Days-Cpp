#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data);
int insertAfter(Node* prev_node, int new_data);
int append(Node** head_ref, int new_data);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 1);

    printf("Linked List: ");
    printList(head);

    int new_insert = insertAfter(head, 2);
    printf("Insert %d after %d (head): ", new_insert, head->data);
    printList(head);

    int new_append = append(&head, 6);
    printf("Insert %d in the end: ", new_append);
    printList(head);

    return 0;
}

/*
 * Time complex: O(1), directly attach a node, constant amount of work
 * Space: O(1)
 */
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();   // allocate node
    new_node->data = new_data;     // put in the data
    new_node->next = (*head_ref);  // make next of new node as head
    (*head_ref) = new_node;        // move the head to point the next node
}

/*
 * Time complex: O(1), prev_node is already give, so no need to iterate over list
 * Space: O(1), constant space
 */
int insertAfter(Node* prev_node, int new_data) {
    if (prev_node == nullptr) {
        printf("The given previous node cannot be NULL");
        return 0;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;  // make next of new node as next of prev_node
    prev_node->next = new_node;        // move the next of prev_node as new_node
    return new_data;
}

/*
 * Time complex: O(N), there's a loop
 * Space: O(1)
 */
int append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;  // make next as NULL

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return 0;
    }

    // traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }
    
    last->next = new_node;   // change next of last node
    return new_data;
}

void printList(Node* node) {
    while (node != nullptr) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}