# Summary of Day 14 to Day 21

Go back to [README.md](README.md)

## Introduction to Tree Data Structures

* Type of non-linear, hierarchical data structures that consists of nodes connected by edges.
* Tree is a collection of entities called nodes.
* Each node can have zero or more children nodes.
* A node that has no child is called a leaf node, and the top node is called the root.
* Trees are used to represent hierarchies, file systems, organization charts, etc.

## Day 14: Binary Trees

* Each node has at most two children, referred to as the left child and the right child.
* Used to implement binary search trees and binary heaps.
* Complete if all levels are completely filled except possibly for the last level, which is filled from left to right.

### [Binary Search Trees](Days/day_014.cpp)

* Used to **store data more efficiently** such that it can be searched and retrieved **quickly**.
* For exemple:
  * Sorted sequence of numbers: 1, 2, 3, 4, 5, 6, 7.
  * Image then that the center value becomes the root node. Those that are less than the root node are placed on the left, and those that are greater are placed on the right.
  * Pointers are used to connect the nodes: 
    ```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
    ```
  * A tree like above offers **dynamism** that an array does not. It can grow and shrink as needed.
  * Search time complexity: **O(log n)**.