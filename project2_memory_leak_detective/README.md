# Project 2: Memory Leak Detective

**Difficulty:** EO1-EO2
**Topic:** Memory Leaks, Dangling Pointers, and Debugging

## Learning Objectives

By completing this project, you will:
- Identify common memory management errors in C++ code
- Understand what causes memory leaks and dangling pointers
- Fix broken code that misuses dynamic memory
- Apply defensive programming techniques
- Use debugging tools to detect memory problems

## Problem Statement

You've been given several broken C++ code snippets that contain memory management errors. Your task is to:

1. **Identify** the errors in each code snippet
2. **Explain** why each error is problematic
3. **Fix** the code to manage memory correctly
4. **Test** your fixes to ensure they work

The programme provides several scenarios with buggy code. For each scenario, you'll:
- Read and analyse the broken code
- Write a corrected version
- Run tests to verify your fix

## Types of Errors You'll Find

1. **Memory Leaks** - Allocated memory that's never freed
2. **Dangling Pointers** - Pointers that reference deleted memory
3. **Double Deletion** - Attempting to delete the same memory twice
4. **Wrong Delete Operator** - Using `delete` instead of `delete[]` or vice versa
5. **Lost Addresses** - Overwriting pointers before freeing memory

## Sample Scenarios

### Scenario 1: Simple Memory Leak
```cpp
void leakyFunction()
{
    int* numbers = new int[100];
    numbers[0] = 42;
    cout << numbers[0] << endl;
    // Function ends - where's the delete[]?
}
```

**Problem:** Memory allocated but never freed.

**Fix:** Add `delete[] numbers;` before function ends.

### Scenario 2: Dangling Pointer
```cpp
void danglingFunction()
{
    int* ptr = new int(10);
    delete ptr;
    *ptr = 20;  // Danger!
    cout << *ptr << endl;
}
```

**Problem:** Using pointer after deletion.

**Fix:** Don't access `ptr` after `delete`, or set `ptr = 0` after deletion.

### Scenario 3: Lost Address
```cpp
void lostAddress()
{
    int* first = new int(5);
    first = new int(10);  // Lost the first allocation!
    delete first;
}
```

**Problem:** First allocation's address is lost, causing a memory leak.

**Fix:** Delete `first` before reassigning, or use a different pointer.

## Programme Structure

Your programme should:

1. Display a menu of scenarios to test
2. For each scenario:
   - Show the buggy code
   - Ask the user to identify the problem
   - Show the correct code
   - Run both versions to demonstrate the issue
3. Keep track of which scenarios the user has reviewed
4. Provide hints if requested

## Sample Output

```
=== Memory Leak Detective ===

Choose a scenario to investigate:
1. Simple Memory Leak
2. Dangling Pointer
3. Double Deletion
4. Wrong Delete Operator
5. Lost Address
6. Array Memory Leak
7. Exit

Enter your choice: 1

--- Scenario 1: Simple Memory Leak ---

Here's the buggy code:
-------------------
void leakyFunction()
{
    int* numbers = new int[100];
    numbers[0] = 42;
    cout << numbers[0] << endl;
}
-------------------

What's wrong with this code?
(a) Nothing - it's fine
(b) Memory leak - never deleted
(c) Dangling pointer
(d) Wrong delete operator

Your answer: b

Correct! This code allocates 100 integers but never frees them.

Here's the fixed code:
-------------------
void fixedFunction()
{
    int* numbers = new int[100];
    numbers[0] = 42;
    cout << numbers[0] << endl;
    delete[] numbers;  // Properly deallocate
    numbers = 0;        // Avoid dangling pointer
}
-------------------

Press Enter to continue...
```

## Requirements

- Present at least **6 different scenarios** with memory errors
- Each scenario should test understanding of a different concept
- Provide **explanations** for why code is wrong and how to fix it
- Include a **scoring system** to track correct answers
- Allow users to review scenarios multiple times
- Use **British spelling** in all output

## Compilation and Running

### Using the Makefile (Recommended)

```bash
make
./leak_detective
```

To clean up compiled files:
```bash
make clean
```

### Manual Compilation

```bash
g++ -std=c++98 -Wall -Wextra -o leak_detective main.cpp
./leak_detective
```

## GitHub Codespaces

You can work on this project directly in your browser using GitHub Codespaces:

1. Click the green "Code" button at the top of this repository
2. Select "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the environment to load
5. Use the terminal to compile and run your programme

## Tips and Hints

- Use clear explanations that help users understand *why* each error is problematic
- Consider using colour codes (if your terminal supports them) to highlight errors
- Think about edge cases - what if the user enters invalid input?
- Make your programme educational - it should teach, not just test

## Common Mistakes to Avoid

- Don't make the scenarios too similar - vary the types of errors
- Ensure your "fixed" code is actually correct
- Provide enough context in each code snippet to understand the problem
- Remember to free all dynamically allocated memory in your own programme

## Extension Challenges (Optional)

If you finish early and want extra practice:

1. **Visual Memory Tracker**: Show a visual representation of allocated/freed memory
2. **Memory Leak Simulator**: Create a scenario where leaks accumulate and cause problems
3. **Interactive Fixing**: Let users type their fix and compile it on the fly
4. **Difficulty Levels**: Categorise scenarios by difficulty (beginner, intermediate, advanced)
5. **Valgrind Integration**: If available, run code through valgrind to show actual leak detection

## Need Help?

- Review the lecture notes on memory leaks and dangling pointers
- Check the practice quiz questions on debugging and memory management
- Start with simple scenarios and gradually add complexity
- Use comments in your code to explain each error

Good luck tracking down those memory bugs!
