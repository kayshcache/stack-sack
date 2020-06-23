# Learning C++ Project 2
## Pack it in the stack
## General notes
Code compiles with:
```bash
$ g++ Main.cpp libGenerate.a -o KAP
```
3. Other than the initial command line input, the program runs without user input.
## A Stacksack
Knapsack problems relate to resource allocation. There is not going to any attempt to optimise in this
case, you just add objects as they arrive, if they fit. There is a collection of classes A to G, provided in
collect.h and you will need to pass instances of them to a knapsack in the order they arrive, until the
next object cannot fit. You are to write a Knapsack class and the main to support and demonstrate the
functionality required here. Your program should compile to KAP and run as:

./KAP size seed
- size : A positive integer. The size of the knapsack.
- seed : A positive integer. Random seed to be passed to the generate function.

A function generate(int) is prototyped in collect.h and defined in the library libGenerate.a. It
returns a letter (char) that identifies which object you need to try and fit into your knapsack.
You need to pass an object of that type to the knapsack using a function template/template function
defined inside Knapsack. That function template should take an object of arbitrary type and attempt to
”add it” to the knapsack. If the object fits, based on the size using sizeof, you record that object as being
included, using the name attribute of the classes. The object itself should not be stored in the knapsack.
Once the next object to be passed cannot be added to the knapsack, you should stop generating objects
and provide two reports:
- Knapsack size, fill size, and a list of object types in the order added:
```bash
Knapsack size: ...
Added object size: ...
BADACEGD
```
- A list of object types in alphabetical order with the size of each type and the number of each included:
```bash
A : size, 2
B : size, 1
C : size, 1
D : size, 2
E : size, 1
G : size, 1
```
Your reports shouldn’t reference classes that haven’t been added to the Knapsack and the Knapsack should
never specifically reference the A to G types in collect.h, or their sizes. The Knapsack class should
support the use of other types that contain a char accessible through a getName() member function.
	Note that the collect.h and libGenerate.a can be changed for testing, so you shouldn’t hardcode
sizes or attempt to predict the output from libGenerate.a. Some example output, based on specific
input, will be provided soon.
## Notes on submission
Submission is via Moodle. Your code must compile on capa with the instructions you provide. If it doesn’t
you will likely be given zero for this assignment.
Please submit your source, so .cpp and .h files, and makefile if you have one, in a zip file
A3.zip. There shouldn’t be any directory structure within the zip file. Please don’t submit
collect.h or libGenerate.a.
1. The deadline is 11:55pm Sunday 14 th June 2020.
2. Late submissions will be marked with a 25% deduction for each day, including days over the weekend.
3. Submissions more than three days late will not be marked, unless an extension has been granted.
4. If you need an extension apply through SOLS, if possible before the assignment deadline.
5. Plagiarism is treated seriously. Students involved will likely receive zero.

## Marksheet
- User Username Comments Lab ‐‐> Lab
- capa Compilation : g++ A3.cpp libGenerate.a ‐o KAP 0.5 0 for the rest if compile fails.
- KAP runs, no breaking, even if incorrect 0.5
- Check number of arguments before use 0.5
- Check size, seed : positive 0.5
- Case 1: KAP 1 C1.txt
- Case 2: KAP 1 C2.txt
- Case 3: KAP 1 C3.txt
- Case 4: KAP 1 C4.txt
- Case 5: KAP 1 C5.txt
- Penalty: Memory leak. Max penalty ‐2 0 0 Check.txt
- Knapsack class : overall structure 1
- Access specifiers 1
- Function template 2
- Correct call to generate 1
- Check return from generate : don't assume A‐G 1
- getName() used in template 1
- sizeof in Knapsack to get object sizes 1
- Knapsack size, fill size report 1
- List of object types in the order added 1
- Alphabetic objects 1
- Size and number 1
- Sensible main 1
- No function templating ‐4
- No Knapsack ‐4
- Hardcoding names/sizes references to A to G in Knapsack ‐4
- Requiring user input other than on the command line ‐4
- Poor commenting. ‐1
- Poor code layout. ‐1
- Poor variable/function names ‐1
- Other bad stuff: To be specified. ‐2
- Total before penalties 20 0
- Total after penalties 0
© Luke McAven, SCIT-EIS-UOW, 2020.
