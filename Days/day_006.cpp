#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data);
void insertAfter(Node* prev_node, int new_data);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 6);
    push(&head, 4);
    push(&head, 8);
    push(&head, 2);

    printf("Linked List: ");
    printList(head);

    insertAfter(head, 1);
    printf("Insert 1 after 2 (head): ");

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
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == nullptr) {
        printf("The given previous node cannot be NULL");
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;  // make next of new node as next of prev_node
    prev_node->next = new_node;        // move the next of prev_node as new_node
}

void printList(Node* node) {
    while (node != nullptr) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}