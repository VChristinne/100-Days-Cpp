/*
 * Data Structures:
 * Array: sequence of elements of the same data type, include the contained type and the length.
 * Linked List:
 * Stack:
 * Queue:
 * Hash Table:
 */

#include <iostream>
using std::cout, std::cin, std::endl;

void array_type();

int main() {
    array_type();
}

void array_type() {
    int my_array[100];

    int arr[] = {1, 2, 3, 4};
    cout << "Third element: " << arr[2] << endl;
    arr[2] = 30;
    cout << "Third element: " << arr[2] << endl;

    unsigned int maximum = 0;
    unsigned int minimum = UINT_MAX;
    unsigned int values[] = {10, 50, 20, 40, 0};
    for (unsigned int value : values) {
        if (value > maximum) maximum = value;
        if (value < minimum) minimum = value;
    }
    cout << "The maximum value: " << maximum << endl;
    cout << "The minimum value: " << minimum << endl;

    size_t n_elements = sizeof(values) / sizeof(values[0]);
    cout << "Size: " << n_elements << endl;
}