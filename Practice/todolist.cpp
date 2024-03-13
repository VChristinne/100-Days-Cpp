#include <iostream>
#include <list>

using namespace std;

struct Task {
    string title;
    string description;
    bool done{false};
};

int menu();
Task getTask(Task);
void showTask(const Task&);

int main() {
    list<Task> tasks;

    while (true) {
        int choice = menu();

        switch (choice) {
            case 1: {
                Task task;
                task = getTask(task);
                tasks.push_back(task);
                break;
            }

            case 2: {
                try {
                    if (tasks.empty()) {
                        throw std::runtime_error("No tasks to show");
                    } else {
                        for (const auto& task : tasks) {
                            showTask(task);
                        }
                    }
                } catch (const std::exception& e) {
                    cout << e.what() << "\n";
                }
                continue;
            }

            case 3: {
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
    cout << "2. Show tasks\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

Task getTask(Task item) {
    cout << "\nTask Title: ";
    cin.ignore();
    getline(cin, item.title);

    cout << "Task Description: ";
    getline(cin, item.description);

    return item;
}

void showTask(const Task& item) {
    cout << "\nTask Title: " << item.title;
    cout << "\nTask Description: " << item.description;
    cout << "\nTask Status: " << (item.done ? "Done" : "Pending");
    cout << "\n";
}
