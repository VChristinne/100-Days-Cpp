/*
 * Data Structures:
 * Array: sequence of elements of the same data type, include the contained type and the length.
 * Linked List:
 * Stack:
 * Queue:
 * Hash Table:
 */

#include <iostream>
using namespace std;

void array_type();

int main() {
    ios_base::sync_with_stdio(false);
    array_type();
}

void array_type() {
    int my_array[100];

    int arr[] = {1, 2, 3, 4};
    printf("\nThird element: %i", arr[2]);
    arr[2] = 30;
    printf("\nThird element: %i", arr[2]);

    unsigned int maximum = 0;
    unsigned int minimum = UINT_MAX;
    unsigned int values[] = {10, 50, 20, 40, 0};
    for (unsigned int value : values) {
        if (value > maximum) maximum = value;
        if (value < minimum) minimum = value;
    }
    printf("\nThe maximum value: %i", maximum);
    printf("\nThe minimum value: %i", minimum);

    size_t n_elements = sizeof(values) / sizeof(values[0]);
    printf("\nSize: %lu", n_elements);
}