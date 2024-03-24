#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data);
void deleteFirst(Node** head_ref);
void deleteAfter(Node* prev_node, Node** head_ref);
void deleteLast(Node** head_ref);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 5);
    push(&head, 7);
    push(&head, 9);
    push(&head, 2);
    push(&head, 8);
    push(&head, 1);

    printf("Linked List: ");
    printList(head);

    deleteFirst(&head);
    printf("Deleted first: ");
    printList(head);

    deleteAfter(head, &head);
    printf("Delete after head: ");
    printList(head);

    deleteLast(&head);
    printf("Deleted last: ");
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
    Node* temp_node = *head_ref;      // current node
    (*head_ref) = (*head_ref)->next;  // move the head to point the next node
    delete temp_node;  // free memory
}

/*
 * Time complex: O(1), prev_node is already give, so no need to iterate over list
 * Space: O(1)
 */
void deleteAfter(Node* prev_node, Node** head_ref) {
    if (prev_node == nullptr) {
        printf("The given previous node cannot be NULL");
        return;
    }
    Node* node_to_delete = prev_node->next;  // point to the node after prev_node
    prev_node->next = node_to_delete->next;  // point to the node after node_to_delete
    delete node_to_delete;
}

/*
 * Time complex: O(N), traverse the entire linked list to find the last node
 * Space: O(1), memory used by the function does not increase
 */
void deleteLast(Node** head_ref) {
    if (*head_ref == nullptr) {
        printf("List empty, nothing to delete");
        return;
    }

    // list w/ one node
    if ((*head_ref)->next == nullptr) {
        delete *head_ref;
        *head_ref = nullptr;
        return;
    }

    // pointers to traverse the list
    Node* current = *head_ref;
    Node* previous = nullptr;

    // traverse to find the last node and previous
    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    previous->next = nullptr;
    delete current;
}

void printList(Node* node) {
    while (node != nullptr) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}