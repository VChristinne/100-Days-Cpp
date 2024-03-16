/*
 * Data Structures: a way of storing data and permits some operations on the data.
 * Array: sequence of elements of the same data type, include the contained type and the length.
    * One-dimensional: store multiple values of similar data types;
    * Two-dimensional: arrange elements in rows and columns;
    * Three-dimensional: collection of two-dimensional arrays pilled on top of each other.
 * Linked List:
 * Stack:
 * Queue:
 * Hash Table:
 */

#include <iostream>
using namespace std;

void array_1D();
void array_2D();
void array_3D();

int main() {
    // TODO: test arrays w/ values double for output
    ios_base::sync_with_stdio(false);
    printf("*** Array 1D ***");
    array_1D();
    printf("\n\n*** Array 2D ***\n");
    array_2D();
    printf("\n\n*** Array 3D ***\n");
    array_3D();
}

void array_1D() {
    int my_array[100];

    int arr[] = {1, 2, 3, 4};
    printf("\nThird element: %i", arr[2]);
    arr[2] = 30;
    printf("\nThird element: %i", *(arr + 2));

    unsigned int maximum = 0;
    unsigned int minimum = UINT_MAX;
    unsigned int values[] = {0, 50, 20, 40, 0};
    for (unsigned int value : values) {
        if (value > maximum) maximum = value;
        if (value < minimum) minimum = value;
    }
    printf("\nThe maximum value: %i", maximum);
    printf("\nThe minimum value: %i", minimum);

    printf("\nSize of arr[0]: %lu", sizeof(arr[0]));
    printf("\nSize of arr: %lu", sizeof(arr));

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nLength of an array: %i", n);
}

void array_2D() {
    int arr[4][4];

    // initialize 2D
    for (int i=0; i<4; i++) {
        for (int j=0;j<4; j++) {
            arr[i][j] = i+j;
        }
    }

    for (auto& i : arr) {
        for (int j : i) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void array_3D() {
    int arr[5][4][4];

    for (int d=0; d<5; d++) {
        for (int r=0; r<4; r++) {
            for (int c=0; c<4; c++) {
                arr[d][r][c] = d+r+c;
            }
        }
    }

    for (int d=0; d<5; d++) {
        printf("%ist layer\n", d+1);
        for (int r=0; r<4; r++) {
            for (int c=0; c<4; c++) {
                printf("%d ", arr[d][r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
}