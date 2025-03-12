# Assignment: Setup



## Overview

In this assignment you will get set up with tools for the
course, edit basic programs, and run their test cases.

Starting from the provided repository, which includes starter code, reference
implementations, and test cases, write the following programs
in C++.

Remember that when running the test script, the output will go into the file `test.log`.

Requirements:
* **Modifiable files:** You can edit each program's `.cpp` file. Each program should need only minor modifications.



### hello

This program prompts the user to enter their name, and then reads their name as a line from standard input.

If there is an input error, the program prints "Invalid input."

Otherwise, it prints "Hello, [name]!" to standard out.



### numbername

This program reads one integer N from standard input.

If N is <= 0 or >= 4, or there is an input error, the program prints "Invalid input." to
standard error and exits.
      
Otherwise, it prints the name of the number to standard out.



### circle

This program prompts the user to enter a circle's radius and reads one double X from standard input.

If X is < 0 or there is an input error, the program prints "Invalid input." to
standard error and exits.
      
Otherwise, it prints the diameter, circumference, and area of the circle to standard out.
