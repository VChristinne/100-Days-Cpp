#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data);
void printList(Node* node);

int main() {
    Node* head = nullptr;

    push(&head, 6);
    push(&head, 4);
    push(&head, 8);
    push(&head, 2);
    printList(head);

    return 0;
}

/*
 * Time complex: 0(1), directly attach a node, constant amount of work
 * Space: 0(1)
 */
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();   // allocate node
    new_node->data = new_data;     // put in the data
    new_node->next = (*head_ref);  // make next of new node as head
    (*head_ref) = new_node;        // move the head to point the next node
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
    cout << "\n";
}