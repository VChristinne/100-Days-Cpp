#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data);
void deleteFirst(Node** head);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 1);

    printf("Linked List: ");
    printList(head);

    deleteFirst(&head);
    printf("Deleted first: ");
    printList(head);

    return 0;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();   // allocate node
    new_node->data = new_data;     // put in the data
    new_node->next = (*head_ref);  // make next of new node as head
    (*head_ref) = new_node;        // move the head to point the next node
}

/*
 * Time complex: O(1)
 * Space: O(1)
 */
void deleteFirst(Node** head_ref) {
    if (*head_ref == nullptr) {
        printf("List empty, nothing to delete");
        return;
    }
    Node* temp_node = *head_ref;     // store the current node
    (*head_ref) = (*head_ref)->next;  // move the head to point the next node
    delete temp_node;  // free memory
}


void printList(Node* node) {
    while (node != nullptr) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}