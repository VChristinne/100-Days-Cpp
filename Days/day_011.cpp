#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

int push(Node** head_ref, int new_data);
void deleteFirst(Node** head_ref);
void deleteAfter(Node* prev_node, Node** head_ref);
void deleteBefore(Node* next_node);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 17);
    push(&head, 14);
    push(&head, 12);
    push(&head, 9);
    push(&head, 6);
    int first_node = push(&head, 3);

    printf("\nDelete First (%d)\n", first_node);
    deleteFirst(&head);
    printList(head);

    printf("\nDelete After %d\n", head->data);
    deleteAfter(head, &head);
    printList(head);

    printf("\nDelete Before %d\n", head->data);
    deleteBefore(head);
    printList(head);

    return 0;
}

int push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    // list not empty
    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
    return new_data;
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

void deleteAfter(Node* prev_node, Node** head_ref) {
    if (prev_node == nullptr || prev_node->next == nullptr) {
        printf("The given previous or next node cannot be NULL");
        return;
    }
    Node* temp_node = prev_node->next;
    prev_node->next = temp_node->next;
    if (prev_node->next != nullptr) {
        prev_node->next->prev = prev_node;
    }
    delete temp_node;
}

void deleteBefore(Node* next_node) {
    if (next_node == nullptr || next_node->prev == nullptr) {
        printf("The given next node or the previous node cannot be NULL\n");
        return;
    }
    Node* temp_node = next_node->prev;
    if (temp_node->prev != nullptr) {
        temp_node->prev->next = next_node;
    }
    next_node->prev = temp_node->prev;
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