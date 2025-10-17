# Project 1: Dynamic Array Manager

**Difficulty:** EO1
**Topic:** Dynamic Memory Allocation and Basic Pointer Operations

## Learning Objectives

By completing this project, you will:
- Allocate and deallocate dynamic arrays using `new` and `delete[]`
- Use pointers to access and modify array elements
- Implement basic array operations (input, output, calculations)
- Practice proper memory management to avoid memory leaks
- Work with pointer arithmetic

## Problem Statement

Create a program that manages a dynamic array of integers. Your program should:

1. Ask the user how many integers they want to store
2. Dynamically allocate an array of that size
3. Allow the user to fill the array with values
4. Display all values in the array
5. Calculate and display:
   - The sum of all values
   - The average of all values
   - The minimum value
   - The maximum value
6. Properly deallocate the array when finished

## Sample Output

```
=== Dynamic Array Manager ===

How many integers would you like to store? 5

Enter value 1: 42
Enter value 2: 17
Enter value 3: 89
Enter value 4: 3
Enter value 5: 56

Your array contains: 42 17 89 3 56

Statistics:
Sum: 207
Average: 41.4
Minimum: 3
Maximum: 89

Memory deallocated. Programme complete.
```

## Requirements

- Use **dynamic memory allocation** (`new` and `delete[]`)
- Do **NOT** use static arrays or vectors
- Use **pointer arithmetic** to access at least one array element
- Include **NULL checks** after deletion
- Handle **edge cases** (e.g., array size of 0 or 1)
- Use **British spelling** in your output

## Compilation and Running

### Using the Makefile (Recommended)

```bash
make
./array_manager
```

To clean up compiled files:
```bash
make clean
```

### Manual Compilation

```bash
g++ -std=c++98 -Wall -Wextra -o array_manager main.cpp
./array_manager
```

## GitHub Codespaces

You can work on this project directly in your browser using GitHub Codespaces:

1. Click the green "Code" button at the top of this repository
2. Select "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the environment to load
5. Use the terminal to compile and run your programme

## Tips and Hints

- Remember to check if `new` succeeds before using the pointer
- Don't forget to call `delete[]` (with square brackets) for arrays
- Set your pointer to `NULL` or `0` after deletion to avoid dangling pointers
- You can use array subscript notation (`arr[i]`) or pointer arithmetic (`*(arr + i)`)
- Think about what should happen if the user enters 0 for the array size

## Common Mistakes to Avoid

- Using `delete` instead of `delete[]` for arrays
- Forgetting to deallocate memory (memory leak)
- Accessing array elements after deletion (dangling pointer)
- Not handling the case where `new` might fail
- Dividing by zero when calculating the average of an empty array

## Extension Challenges (Optional)

If you finish early and want extra practice:

1. **Search function**: Add a feature to search for a specific value in the array
2. **Sort function**: Implement a simple sorting algorithm (e.g., bubble sort)
3. **Resize function**: Allow the user to resize the array (requires creating a new array and copying data)
4. **Multiple operations**: Let the user perform multiple operations without restarting the programme

## Need Help?

- Review the lecture notes on dynamic memory allocation
- Check the practice quiz questions on pointers and dynamic arrays
- Test your code with different array sizes (0, 1, 10, 100)
- Use `valgrind` to check for memory leaks (if available on your system)

Good luck, and remember: every `new` needs a `delete[]`!
