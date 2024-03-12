#include <iostream>

using std::cout, std::cin, std::endl, std::string;

struct Task {
    string title;
    string description;
    bool done;
};

Task getTask(Task);
void showTask(const Task&);

int main() {
    Task item;
    item = getTask(item);
    showTask(item);

    return 0;
}

Task getTask(Task item) {
    cout << "\nTask Title: ";
    cin >> (item.title);

    cout << "\nTask Description: ";
    cin >> (item.description);

    string doneInput;
    cout << "\nTask Status (yes/no): ";
    cin >> doneInput;
    item.done = (doneInput == "yes");

    return item;
}

void showTask(const Task& item) {
    cout << "\nTask Title: " << item.title;
    cout << "\nTask Description: " << item.description;
    cout << "\nTask Status: " << (item.done ? "Done" : "Pending");
}

