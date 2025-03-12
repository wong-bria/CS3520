# Assignment: Deque



## Overview

In this assignment you will implement a generic deque (double-ended queue) as
a doubly-linked list using smart pointers.

The doubly linked list has a pointer to the head node and the tail
node so that elements can be efficiently pushed or popped on either end.
Each node has a pointer to next and previous node.

You will need to change the typedefs of raw pointers in DLLDeque to
smart pointers (either std::shared_ptr or std::weak_ptr). The smart
pointers must automatically manage the memory for the linked list.

You will also need to implement the iterator for DLLDeque, so it
can be used in STL algorithms and range-based for loops.

Remember to to fill out the ABOUT.txt (and LLM.txt if needed).

Requirements:
* **You must not directly call new or delete or use raw pointers (other than `this` and `nullptr`).**
* **Modifiable files:** You can edit `DLLDeque.tmpl.hpp` and the typedefs at the top of `DLLDeque.hpp`.
