#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int insertEnd(Node** head_ref, int data);
int insertBegin(Node** head_ref, int data);
int insertAfter(Node* prev_node, int data);
void printList(Node* head);

int main() {
    Node* head = nullptr;

    insertEnd(&head, 12);
    insertEnd(&head, 9);
    insertEnd(&head, 6);
    insertEnd(&head, 3);
    insertBegin(&head, 15);
    insertAfter(head->next->next, 10);

    printList(head);

    return 0;
}

/*
 * Time complex: O(n)
 * Space: O(1)
 */
int insertEnd(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    Node* current = (*head_ref);

    if (current == nullptr) {
        new_node->next = new_node;
        (*head_ref) = new_node;
    } else {
        while (current->next != (*head_ref)) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = (*head_ref);
    }
    return new_node->data;
}

/*
 * Time complex: O(n)
 * Space: O(1)
 */
int insertBegin(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    Node* current = (*head_ref);

    if (current == nullptr) {
        new_node->next = new_node;
        (*head_ref) = new_node;
    } else {
        while (current->next != (*head_ref)) {
            current = current->next;
        }
        current->next = new_node;
        (*head_ref) = new_node;
    }
    return new_node->data;
}

/*
 * Time complex: O(n)
 * Space: O(1)
 */
int insertAfter(Node* prev_node, int data) {
    if (prev_node == nullptr) {
        cout << "The given previous node cannot be NULL" << endl;
        return -1;
    }
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return new_node->data;
}

void printList(Node* head) {
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

