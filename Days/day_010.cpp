#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void push(Node** head_ref, int new_data);
int insertAfter(Node* prev_node, int new_data);
int insertBefore(Node** head_ref, Node* next_node, int new_data);
int append(Node** head_ref, int new_data);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 3);
    push(&head, 6);
    push(&head, 12);
    printList(head);

    int new_after = insertAfter(head, 9);
    printf("\nInsert %d after %d (head)\n", new_after, head->data);
    printList(head);

    int new_before = insertBefore(&head, head, 14);
    printf("\nInsert %d in forward begin\n", new_before);
    printList(head);

    int new_append = append(&head, 0);
    printf("\nInsert %d in the end\n", new_append);
    printList(head);

    return 0;
}

/*
 * Time complex: O(1)
 * Space: O(1)
 */
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

/*
 * Time complex: O(1)
 * Space: O(1)
 */
int insertAfter(Node* prev_node, int new_data) {
    if (prev_node == nullptr) {
        printf("The given previous node cannot be NULL");
        return 0;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    // list not empty
    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
    return new_data;
}

/*
 * Time complex: O(1)
 * Space: O(1)
 */
int insertBefore(Node** head_ref, Node* next_node, int new_data) {
    if (next_node == nullptr) {
        printf("The given next node cannot be NULL");
        return 0;
    }
    Node* new_node = new Node();
    Node* head = nullptr;
    new_node->data = new_data;
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;

    // list not empty
    if (new_node->prev != nullptr) {
        new_node->prev->next = new_node;
    } else {
        (*head_ref) = new_node;
    }
    return new_data;
}

/*
 * Time complex: O(n)
 * Space: O(1)
 */
int append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;  // last node

    // list empty
    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return 0;
    }

    // traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return new_data;
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