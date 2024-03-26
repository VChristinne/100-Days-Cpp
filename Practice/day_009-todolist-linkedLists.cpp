#include <iostream>
#include <sstream>
using std::cin, std::cout, std::string;

class Task {
public:
    string title;
    string description;
    bool done{false};
    int data{};
    Task* next{};
};

void push(Task** head_ref, int& taskNumber);
void deleteTask(Task** head_ref);
Task* search(Task* head);
void showTask(Task* node);
void editTask(Task** head_ref);
bool showTasks(Task* node);
void updateTaskNumbers(Task** head_ref);
int menu();

int main() {
    Task* head = nullptr;
    int taskNumber = 1;

    while (true) {
        int choice = menu();

        switch (choice) {
            case 1: {
                push(&head, taskNumber);
                continue;
            }

            case 2: {
                deleteTask(&head);
                continue;
            }

            case 3: {
                showTasks(head) ? cout : cout << "No tasks to show\n";
                continue;
            }

            case 4: {
                search(head) ? cout : cout << "No tasks to show\n";
                continue;
            }

            case 5: {
                editTask(&head);
                continue;
            }

            case 6: {
                return 0;
            }

            default: {
                cout << "Invalid choice\n";
            }
        }
    }
}

int menu() {
    int choice;
    cout << "\n1. Add a task\n";
    cout << "2. Delete task\n";
    cout << "3. Show tasks\n";
    cout << "4. Search task\n";
    cout << "5. Edit task\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void push(Task** head_ref, int& taskNumber) {
    Task* new_task = new Task();

    cout << "\nTask title: ";
    cin >> new_task->title;
    cout << "Task description: ";
    cin >> new_task->description;
    string doneInput;
    cout << "Task done? (yes/no): ";
    cin >> doneInput;
    new_task->done = (doneInput == "yes");

    new_task->data = taskNumber++;
    new_task->next = (*head_ref);
    (*head_ref) = new_task;

    cout << "Task added\n";
}

void deleteTask(Task** head_ref) {
    Task* taskToDelete = search(*head_ref);
    if (taskToDelete == nullptr) {
        return;
    }

    if (*head_ref == taskToDelete) {
        *head_ref = taskToDelete->next;
    } else {
        Task* prev = *head_ref;
        while (prev->next != taskToDelete) {
            prev = prev->next;
        }
        prev->next = taskToDelete->next;
    }
    updateTaskNumbers(head_ref);
    delete taskToDelete;
}

Task* search(Task* head) {
    string userInput;
    cout << "\nEnter search input: ";
    cin >> userInput;

    Task* current = head;
    while (current != nullptr) {
        std::ostringstream oss;
        oss << current->data;
        string taskNumber = oss.str();

        if (taskNumber == userInput || current->title == userInput || current->description == userInput) {
            showTask(current);
            return current;
        }
        current = current->next;
    }
    cout << "Task not found\n";
    return nullptr;
}

void showTask(Task* node) {
    if (node == nullptr) {
        cout << "Task not found\n";
        return;
    }
    cout << "\nTask number: " << node->data;
    cout << "\nTask title: " << node->title;
    cout << "\nTask description: " << node->description;
    cout << "\nTask Status: " << (node->done ? "Done" : "Pending");
    cout << "\n";
}

bool showTasks(Task* node) {
    if (node == nullptr) {
        return false;
    }
    Task* current = node;
    while (current != nullptr) {
        cout << "\nTask number: " << current->data;
        cout << "\nTask title: " << current->title;
        cout << "\nTask description: " << current->description;
        cout << "\nTask Status: " << (current->done ? "Done" : "Pending");
        cout << "\n";
        current = current->next;
    }
    return true;
}

void editTask(Task** head_ref) {
    Task* taskToEdit = search(*head_ref);

    if (taskToEdit != nullptr) {
        cout << "Enter new title: ";
        cin >> taskToEdit->title;
        cout << "Enter new description: ";
        cin >> taskToEdit->description;
        string doneInput;
        cout << "Task done? (yes/no): ";
        cin >> doneInput;
        taskToEdit->done = (doneInput == "yes");
        cout << "Task updated\n";
        return;
    }
}

void updateTaskNumbers(Task** head_ref) {
    Task* current = *head_ref;
    int taskNumber = 1;
    while (current != nullptr) {
        current->data = taskNumber++;
        current = current->next;
    }
}
