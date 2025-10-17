# Project 3: Pointer Arithmetic Workshop

**Difficulty:** EO1
**Topic:** Pointer Arithmetic and Array Traversal

## Learning Objectives

By completing this project, you will:
- Understand how pointer arithmetic works with different data types
- Practice using pointers to traverse arrays
- Compare subscript notation (`arr[i]`) with pointer notation (`*(arr + i)`)
- Learn about pointer differences and address calculations
- Work with `sizeof` to understand memory layout

## Problem Statement

Create an interactive workshop programme that demonstrates and practices pointer arithmetic concepts. Your programme should:

1. Display educational examples of pointer arithmetic
2. Allow users to practice pointer arithmetic calculations
3. Demonstrate the relationship between arrays and pointers
4. Show how pointer arithmetic works with different data types (`int`, `char`, `double`)
5. Include interactive exercises with immediate feedback

## Sample Output

```
=== Pointer Arithmetic Workshop ===

--- Section 1: Basic Pointer Arithmetic ---

We have an array: int arr[] = {10, 20, 30, 40, 50};
The array starts at memory address: 0x7fff5fbff8a0

Let's explore pointer arithmetic:

arr points to:      0x7fff5fbff8a0  (value: 10)
arr + 1 points to:  0x7fff5fbff8a4  (value: 20)
arr + 2 points to:  0x7fff5fbff8a8  (value: 30)
arr + 3 points to:  0x7fff5fbff8ac  (value: 40)
arr + 4 points to:  0x7fff5fbff8b0  (value: 50)

Notice: Each address increases by 4 bytes (sizeof(int) = 4)

--- Section 2: Array Subscript vs Pointer Notation ---

arr[0] is the same as *(arr + 0) = 10
arr[1] is the same as *(arr + 1) = 20
arr[2] is the same as *(arr + 2) = 30
arr[3] is the same as *(arr + 3) = 40
arr[4] is the same as *(arr + 4) = 50

--- Interactive Exercise 1 ---

Given: int values[] = {100, 200, 300, 400};
       int* ptr = values;

Question: What is the value of *(ptr + 2)?

Your answer: 300

Correct! *(ptr + 2) accesses the element at index 2, which is 300.

[Continue with more exercises...]

Programme complete!
```

## Programme Structure

Your workshop should include these sections:

1. **Basic Pointer Arithmetic** - Show how adding to pointers changes addresses
2. **Array Subscript vs Pointer Notation** - Demonstrate equivalence
3. **Pointer Differences** - Show how to find distance between pointers
4. **Different Data Types** - Compare `int`, `char`, and `double` pointer arithmetic
5. **Interactive Exercises** - Test the user's understanding

### Interactive Exercises (Minimum 5)

1. Calculate `*(ptr + offset)` for various offsets
2. Determine the difference between two pointers
3. Predict memory addresses given pointer arithmetic
4. Convert subscript notation to pointer notation
5. Identify errors in pointer arithmetic expressions

## Requirements

- Use dynamic arrays for demonstrations
- Display **actual memory addresses** (using pointer output)
- Show the **sizeof** different data types
- Provide **immediate feedback** for exercises
- Include a **scoring system** for the exercises
- Use **British spelling** in all output
- Properly **deallocate** all dynamic memory

## Compilation and Running

### Using the Makefile (Recommended)

```bash
make
./pointer_workshop
```

To clean up compiled files:
```bash
make clean
```

### Manual Compilation

```bash
g++ -std=c++98 -Wall -Wextra -o pointer_workshop main.cpp
./pointer_workshop
```

## GitHub Codespaces

You can work on this project directly in your browser using GitHub Codespaces:

1. Click the green "Code" button at the top of this repository
2. Select "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the environment to load
5. Use the terminal to compile and run your programme

## Tips and Hints

- Remember: `arr[i]` is exactly the same as `*(arr + i)`
- Pointer arithmetic automatically scales by the size of the data type
- Adding 1 to an `int*` increases the address by `sizeof(int)` bytes
- You can subtract pointers to find the distance between array elements
- Memory addresses will be different each time you run the programme

## Important Concepts to Demonstrate

1. **Automatic Scaling**: When you add 1 to a pointer, it doesn't add 1 byte - it adds `sizeof(type)` bytes
2. **Array Names as Pointers**: An array name is essentially a pointer to its first element
3. **Pointer Differences**: Subtracting two pointers gives the number of elements between them
4. **Out of Bounds**: Show what happens if you go beyond array boundaries (and why it's dangerous)

## Common Mistakes to Avoid

- Don't forget to dereference pointers when you want the value
- Remember that pointer arithmetic scales by type size
- Don't access memory beyond array boundaries
- Always deallocate dynamic memory

## Extension Challenges (Optional)

If you finish early and want extra practice:

1. **Reverse Traversal**: Show how to traverse an array backwards using pointers
2. **Pointer to Pointer**: Demonstrate using `int**` with pointer arithmetic
3. **Const Pointers**: Show the difference between `const int*`, `int* const`, and `const int* const`
4. **Function Parameters**: Demonstrate passing arrays as pointers to functions
5. **2D Arrays**: Explore pointer arithmetic with 2D arrays

## Need Help?

- Review the lecture notes on pointer arithmetic
- Check the practice quiz questions on pointers and arrays
- Remember: drawing memory diagrams helps visualise pointer arithmetic
- Test with small arrays first, then expand

Good luck mastering pointer arithmetic!
