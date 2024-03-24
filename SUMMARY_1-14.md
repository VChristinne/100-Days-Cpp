# Summary of Day 1 to Day 14

Go back to [README.md](README.md)

## Day 0: Introduction to C++

* General-purpose programming language.
* It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.
* Compiled language, with implementations of it available on many platforms.

## Day 1: [Basic Syntax](Days/day_001.cpp)

* C++ programs are composed of a series of statements.
* A statement can be an expression, a declaration, a function call, or a control structure.
* The `main` function is the entry point of a C++ program, and it must return an integer value.
* The `#include` directive is used to include the contents of a file in the program.
* The `using namespace std` directive allows the use of elements from the `std` namespace without needing to prefix them with `std::`.

### Data Types
* `int` types can be signed or unsigned and can have different sizes.
* `float` types can represent real numbers and have different precisions.
* `double` type has double precision.
* `char` type can store a single character.
* `bool` type can store a truth value.
* `void` type is used to represent the absence of type.
* `auto` keyword can be used to automatically deduce the data type of variable.
* `const` keyword can be used to define a constant variable.

### **Derived data**
* `Arrays` are used to store multiple values of the same data type under a single name.
* `Pointers` are used to store the memory address of another variable.
* `References` are used to create an alias for a variable.

### **User-defined**
* `Structures` are used to define a group of variables under a single name;
* `Unions` are similar to structures, but they use the same memory location for all their members;
* `Enumerations` are used to define a group of named constants;
* `Classes` are used to define a blueprint for objects.

## Day 2: [Morse Code Arduino Project](Practice/day_002-morse-code-arduino.cpp)

* Created a simple Arduino project to convert a string into Morse code.
* Used an LED to represent the Morse code output.

## Day 3: [Calculator Project](Practice/day_003-calculator.cpp)

* Take user input for two numbers.
* Perform the operation based on the user's choice.
* Used lambda functions to perform the operations.

## Day 4: [Guessing Game](Practice/day_004-guessing-game.cpp)

* Generate a random number between 1 and 100.
* Have 3 levels of difficulty: easy, medium, and hard.
* Provide hints when the number is higher or lower than the user's guess.
* Allow the user to play again after winning or losing.
* Used `#include <cstdlib>` and `#include <random>` to generate random numbers.

## Day 5: [Arrays](Days/day_005.cpp)

* Arrays sequence of elements of the same data type, include the contained type and the length.
  * `One dimensional` arrays store multiple values of similar data types;
  * `Two-dimensional` arrange elements in rows and columns;
  * `Three-dimensional` collection of two-dimensional arrays pilled on top of each other.


* The elements of an array can be accessed using an index, which is an integer value that starts at 0.
  * The `index` is used to specify the position of an element in the array;
  * The `index` can be used to access or modify the value of an element in the array.


* The size of an array must be a constant value, and it determines the maximum number of elements that can be stored in the array.

## Day 6: [Linked Lists](Days/day_006.cpp)

* Collection of nodes, where each node contains data and a reference to the next node in the sequence.
  * `Node` typically consists of two components;
  * `Data holds` the actual value or data associated with the node;
  * `Next pointer` stores the reference to the next node in the sequence;
  * `Head and Tail` pointers are used to keep track of the first and last nodes in the list.

### Singly Linked Lists

* Each node points to the **next node** in the sequence.
* Allows for traversal in one direction.
* Useful for applications that require forward traversal.
* **[Code](Days/day_006.cpp)** for singly linked list insertion.
* **[Code](Days/day_007.cpp)** for singly linked list deletion.

<img width="600" alt="singly linked lists" src="https://github.com/VChristinne/100-Days-Cpp/assets/141720673/d9970249-73b8-4bba-a417-3e8a6edc3b92">

### Doubly Linked Lists

* Each node points to the **next and previous nodes** in the sequence.
* Allows for traversal in both directions.
* Useful for applications that require reverse traversal.

<img width="600" alt="doubly linked lists" src="https://github.com/VChristinne/100-Days-Cpp/assets/141720673/c1daefe1-e9c2-4f0f-b53d-28708c9d1960">

### Circular Linked Lists

* The last node points **back to the first node** in the sequence.
* Can be singly or doubly linked.
* Useful for applications that require continuous access to the elements.
  
<img width="600" alt="circular linked lists" src="https://github.com/VChristinne/100-Days-Cpp/assets/141720673/f04c3494-6943-4fbd-8e7c-077294e30cfa">


### Advantages for using linked lists
  * `Dynamic size` can grow or shrink at runtime based on the operations;
  * `Efficient insertion and deletion` operations;
  * `No need for contiguous memory` allocation;
  * `Versatile` can be used to implement other data structures.

### Disadvantages of linked lists
  * `No direct access` elements traversal required to access elements;
  * `Extra memory` required to store the next pointer;
