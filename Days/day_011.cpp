#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void push(Node** head_ref, int new_data);
void deleteFirst(Node** head_ref);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 3);
    push(&head, 6);
    push(&head, 9);

    deleteFirst(&head);
    printList(head);

    return 0;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    // list not empty
    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void deleteFirst(Node** head_ref) {
    if (*head_ref == nullptr) {
        printf("List empty, nothing to delete");
        return;
    }
    Node* temp_node = *head_ref;
    (*head_ref) = (*head_ref)->next;
    if (*head_ref != nullptr) {
        (*head_ref)->prev = nullptr;
    }
    delete temp_node;
}

void printList(Node* node) {
    Node* last;
    printf("Traversal in forward direction: ");
    while (node != nullptr) {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    printf("\n");

    printf("Traversal in reverse direction: ");
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    printf("\n");
}