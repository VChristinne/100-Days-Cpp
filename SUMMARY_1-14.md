# Summary of Day 1 to Day 14

## Table of Contents

1. [Introduction to C++](#day-0-introduction-to-c)
2. [Basic Syntax](#day-1-basic-syntax)
3. [Morse Code Arduino Project](#day-2-morse-code-arduino-project)
4. [Calculator Project](#day-3-calculator-project)
5. [Guess the Number Game](#day-4-guess-the-number-game)
6. [Data Structures](#day-5-data-structures)

## Day 0: Introduction to C++

* General-purpose programming language.
* It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.
* Compiled language, with implementations of it available on many platforms.

## Day 1: Basic Syntax

* C++ programs are composed of a series of statements.
* A statement can be an expression, a declaration, a function call, or a control structure.
* The `main` function is the entry point of a C++ program, and it must return an integer value.
* The `#include` directive is used to include the contents of a file in the program.
* The `using namespace std` directive allows the use of elements from the `std` namespace without needing to prefix them with `std::`.

### Data Types

* Provides several basic data types, including `int`, `float`, `double`, `char`, and `bool`.
    * Integer types can be signed or unsigned and can have different sizes.
    * Floating-point types can represent real numbers and have different precisions.
    * The `double` type has double precision.
    * The `char` type can store a single character.
    * The `bool` type can store a truth value.
    * The `void` type is used to represent the absence of type.

* Data types determine the type of value a variable can hold and how much memory space it will occupy.
    * The `auto` keyword can be used to automatically deduce the data type of variable.
    * The `const` keyword can be used to define a constant variable.

* Derived data types include arrays, pointers, and references.
    * `Arrays` are used to store multiple values of the same data type under a single name.
    * `Pointers` are used to store the memory address of another variable.
    * `References` are used to create an alias for a variable.

* User-defined data types include structures, unions, and enumerations.
    * `Structures` are used to define a group of variables under a single name;
    * `Unions` are similar to structures, but they use the same memory location for all their members;
    * `Enumerations` are used to define a group of named constants;
    * `Classes` are used to define a blueprint for objects.

## Day 2: Morse Code Arduino Project

* Created a simple Arduino project to convert a string into Morse code.
* Used an LED to represent the Morse code output.

## Day 3: Calculator Project

* Take user input for two numbers.
* Perform the operation based on the user's choice.
* Used lambda functions to perform the operations.

## Day 4: Guess the Number Game

* Generate a random number between 1 and 100.
* Have 3 levels of difficulty: easy, medium, and hard.
* Provide hints when the number is higher or lower than the user's guess.
* Allow the user to play again after winning or losing.
* Used `#include <cstdlib>` and `#include <random>` to generate random numbers.

## Day 5: Data Structures

* A way of storing data and permits some operations on the data.
* Common data structures include arrays, linked lists, stacks, queues, trees, and graphs.
    * Arrays sequence of elements of the same data type, include the contained type and the length.
        * One dimensional arrays store multiple values of similar data types;
        * Two-dimensional: arrange elements in rows and columns;
        * Three-dimensional: collection of two-dimensional arrays pilled on top of each other.
    * Linked lists are a collection of nodes, where each node contains data and a reference to the next node in the sequence.
        * `Node` typically consists of two components;
        * `Data holds` the actual value or data associated with the node;
        * `Next pointer` stores the reference to the next node in the sequence;
        * `Head and Tail` pointers are used to keep track of the first and last nodes in the list.