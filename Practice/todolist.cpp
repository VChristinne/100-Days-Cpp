#include <iostream>
#include <list>

using namespace std;

struct Task {
    string title;
    string description;
    bool done;
};

Task getTask(Task);
void showTask(const Task&);

int main() {
    Task item;
    list<Task> tasks;

    Task newTask = getTask(item);
    tasks.push_back(newTask);

    for (const Task& task : tasks) {
        showTask(task);
    }

    return 0;
}

Task getTask(Task item) {
    cout << "\nTask Title: ";
    cin >> item.title;

    cout << "Task Description: ";
    cin >> item.description;

    string doneInput;
    cout << "Task Status (done/no): ";
    cin >> doneInput;
    item.done = (doneInput == "done");

    return item;
}

void showTask(const Task& item) {
    cout << "\nTask Title: " << item.title;
    cout << "\nTask Description: " << item.description;
    cout << "\nTask Status: " << (item.done ? "Done" : "Pending");
}
