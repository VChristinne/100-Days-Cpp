#include <iostream>

using std::cout, std::cin, std::endl;

int menu();

int main() {
    float num1, num2;

    int choice = menu();

    cout << "\nEnter an number: ";
    cin >> num1;

    cout << "Enter another number: ";
    cin >> num2;

    switch (choice)
    {
        case 1:
        {
            auto add = [] (float a, float b) {
                cout << "Addition = " << a + b << endl;
            };
            add(num1, num2);
            break;
        }

        case 2:
        {
            auto sub = [] (float a, float b) {
                cout << "Subtraction = " << a - b << endl;
            };
            sub(num1, num2);
            break;
        }

        case 3:
        {
            auto mult = [] (float a, float b) {
                cout << "Multiplication = " << a * b << endl;
            };
            mult(num1, num2);
            break;
        }

        case 4:
        {
            auto div = [] (float a, float b) {
                if(b != 0) {
                    cout << "Division = " << a / b << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
            };
            div(num1, num2);
            break;
        }

        case 5:
            cout << "Exiting...";
            break;
    }

    return 0;
}

int menu() {
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    return choice;
}