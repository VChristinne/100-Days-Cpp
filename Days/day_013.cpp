#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int insertEnd(Node** head_ref, int data);
void deleteBegin(Node** head_ref);
void deleteEnd(Node** head_ref);
void deleteAfter(Node* prev_node);
void printList(Node* head);

int main() {
    Node* head = nullptr;

    int first_node = insertEnd(&head, 12);
    insertEnd(&head, 9);
    insertEnd(&head, 6);
    int last_node = insertEnd(&head, 3);

    printList(head);

    printf("\nDelete Begin (%d): ", first_node);
    deleteBegin(&head);
    printList(head);

    printf("\nDelete End (%d): ", last_node);
    deleteEnd(&head);
    printList(head);

    printf("\nDelete After (%d): ", head->data);
    deleteAfter(head);
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
 * Time complex: O(1)
 * Space: O(1)
 */
void deleteBegin(Node** head_ref) {
    if (*head_ref == nullptr) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    if ((*head_ref)->next == *head_ref) {
        delete *head_ref;
        *head_ref = nullptr;
    } else {
        Node* temp = *head_ref;
        Node* current = *head_ref;
        while (current->next != *head_ref) {
            current = current->next;
        }
        *head_ref = (*head_ref)->next;
        current->next = *head_ref;
        delete temp;
    }
}

/*
 * Time complex: O(n)
 * Space: O(1)
 */
void deleteEnd(Node** head_ref) {
    if (*head_ref == nullptr) {
        cout << "List is empty, cannot delete" << endl;
        return;
    }

    if ((*head_ref)->next == *head_ref) {
        delete *head_ref;
        *head_ref = nullptr;
    } else {
        Node* current = *head_ref;
        Node* prev = nullptr;
        while (current->next != *head_ref) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
    }
}

/*
 * Time complex: O(1)
 * Space: O(1)
 */
void deleteAfter(Node* prev_node) {
    if (prev_node == nullptr) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }
    Node* next_node = prev_node->next;
    prev_node->next = next_node->next;
    delete next_node;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}