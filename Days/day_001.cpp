/*
 * Data types: determining the type of value a variable can hold and how much memory space it will occupy.
 * Basic data types in C++ include integers, floating-point numbers, characters, and booleans.
 * Derived data types include arrays, pointers, and references.
 * User-defined data types include structures, unions, and enumerations.
 * Structures are used to define a group of variables under a single name.
 * Unions are similar to structures, but they use the same memory location for all their members.
 * Enumerations are used to define a group of named constants.
 * Classes are used to define a blueprint for objects.
*/

#include <iostream>
using std::cout, std::endl, std::string;

void basic_datatypes();
void derived_datatypes();
void user_defined_datatypes();

int main() {
    basic_datatypes();
    derived_datatypes();
    user_defined_datatypes();

    return 0;
}

void basic_datatypes() {
    int a = 5;
    float b = 5.5;
    char c = 'A';
    bool d = true;

    cout << "Basic data types" << endl;
    cout << "Integer: " << a << endl;
    cout << "Floating-point number: " << b << endl;
    cout << "Character: " << c << endl;
    cout << "Boolean: " << d << endl;
}

void derived_datatypes() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int num1 = 42;
    int* pNum = &num1;
    int num2 = 60;
    int& numRef = num2;

    cout << "\nDerived data types" << endl;
    cout << "Array: " << numbers[3] << endl;
    cout << "Pointer: " << pNum << endl;
    cout << "Reference: " << numRef << endl;
}

void user_defined_datatypes() {
    struct Person {
        string name;
        int age;
        float height;
    };

    Person p1 = {"John", 6, 1.60};

    class Fruit {
    public:
        string name;
        string color;

        void printInfo() {
            cout << "Name: " << name << ", Color: " << color << endl;
        };
    };

    Fruit f1;
    f1.name = "Strawberry";
    f1.color = "Red";

    union Money {
        char note;
        float euros;
    };

    Money m1;
    m1.note = 'E';
    m1.euros = 42.5;

    cout << "\nUser-defined data types" << endl;
    cout << "Structure -> Name: " << p1.name << ", Age: " << p1.age << ", Height: " << p1.height << endl;
    cout << "Class -> ";
    f1.printInfo();
    // only use one member of the union at a time
    cout << "Union -> Euros: " << m1.euros;
}

