#include <iostream>
#include <list>

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
    std::list<item> tasks = {};
    
    //item = getTask(item);
    //showTask(item);

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
