# Project 5: 2D Dynamic Array Manager

**Difficulty:** EO2-EO3
**Topic:** Two-Dimensional Dynamic Arrays and Advanced Pointer Operations

## Learning Objectives

By completing this project, you will:
- Allocate and manage 2D dynamic arrays (array of pointers to arrays)
- Understand the difference between static and dynamic 2D arrays
- Work with nested loops and pointer-to-pointer types
- Properly deallocate multi-level dynamic structures
- Implement matrix operations using dynamic arrays

## Problem Statement

Create a programme that manages dynamic 2D arrays (matrices) with various operations. Your programme should:

1. Allow the user to specify matrix dimensions (rows and columns)
2. Allocate a 2D dynamic array
3. Fill the matrix with user input or random values
4. Perform operations:
   - Display the matrix
   - Calculate row and column sums
   - Find minimum and maximum values
   - Transpose the matrix (swap rows and columns)
   - Add two matrices
5. Properly deallocate all memory (including each row and the array of pointers)

## Sample Output

```
=== 2D Dynamic Array Manager ===

Enter number of rows: 3
Enter number of columns: 4

Matrix allocated: 3 rows x 4 columns

Main Menu:
1. Fill matrix manually
2. Fill matrix with random values
3. Display matrix
4. Calculate row sums
5. Calculate column sums
6. Find min and max
7. Transpose matrix
8. Add another matrix
9. Exit

Enter your choice: 2

Matrix filled with random values (0-99).

Enter your choice: 3

--- Current Matrix (3 x 4) ---
  42   17   89   23
  56   34   91   12
   8   67   45   71

Enter your choice: 4

--- Row Sums ---
Row 0: 171
Row 1: 193
Row 2: 191

Enter your choice: 5

--- Column Sums ---
Column 0: 106
Column 1: 118
Column 2: 225
Column 3: 106

Enter your choice: 6

--- Min and Max Values ---
Minimum: 8 (at row 2, column 0)
Maximum: 91 (at row 1, column 2)

Enter your choice: 7

--- Transpose Matrix ---
Original matrix was 3 x 4
Transposed matrix is 4 x 3

New matrix:
  42   56    8
  17   34   67
  89   91   45
  23   12   71

Enter your choice: 9

Deallocating matrix...
Programme complete!
```

## 2D Dynamic Array Structure

A 2D dynamic array is an **array of pointers**, where each pointer points to a dynamic array (a row):

```cpp
// Allocate array of row pointers
int** matrix = new int*[rows];

// Allocate each row
for (int i = 0; i < rows; i++)
{
    matrix[i] = new int[cols];
}

// Access elements: matrix[row][col]
```

## Memory Layout

Unlike a static 2D array, a dynamic 2D array is **not contiguous** in memory:

```
matrix (int**) --> [ptr0] --> [element][element][element]  (row 0)
                   [ptr1] --> [element][element][element]  (row 1)
                   [ptr2] --> [element][element][element]  (row 2)
```

Each row is a separate dynamic array!

## Requirements

- Allocate a **2D dynamic array** using pointer-to-pointer (`int**`)
- Allow rows and columns to be **different sizes**
- Implement **all 8 menu options** with proper functionality
- Use **British spelling** in all output
- Include **NULL checks** after allocation
- **Deallocate properly**: delete each row, then delete the array of pointers
- Handle **edge cases** (empty matrices, mismatched dimensions for addition)

## Menu Options Details

### 1. Fill Matrix Manually
- Prompt user for each element
- Use nested loops: outer for rows, inner for columns
- Store values in `matrix[row][col]`

### 2. Fill with Random Values
- Use `rand()` to generate values (0-99 range recommended)
- Seed random generator with `srand(time(0))`
- Fill entire matrix automatically

### 3. Display Matrix
- Use nested loops to display in grid format
- Align columns with `setw()`
- Show row and column labels if helpful

### 4. Calculate Row Sums
- For each row, sum all column values
- Display the sum for each row

### 5. Calculate Column Sums
- For each column, sum all row values
- Display the sum for each column

### 6. Find Min and Max
- Scan entire matrix to find smallest and largest values
- Display both values and their positions (row, column)

### 7. Transpose Matrix
- Create a new matrix with swapped dimensions (cols x rows)
- Copy values: `newMatrix[col][row] = oldMatrix[row][col]`
- Deallocate old matrix and use new one
- **Challenging**: dimensions change!

### 8. Add Another Matrix
- Prompt for dimensions of second matrix
- Check if dimensions match (must be same for addition)
- Create result matrix
- Add corresponding elements: `result[i][j] = matrix1[i][j] + matrix2[i][j]`
- Display result

## Deallocation (Critical!)

**This is the most important part for 2D arrays:**

```cpp
// Delete each row first
for (int i = 0; i < rows; i++)
{
    delete[] matrix[i];
}

// Then delete the array of pointers
delete[] matrix;

// Set to NULL
matrix = 0;
```

**Common mistake**: Deleting `matrix` before deleting the rows causes memory leaks!

## Compilation and Running

### Using the Makefile (Recommended)

```bash
make
./matrix_manager
```

To clean up compiled files:
```bash
make clean
```

### Manual Compilation

```bash
g++ -std=c++98 -Wall -Wextra -o matrix_manager main.cpp
./matrix_manager
```

## GitHub Codespaces

You can work on this project directly in your browser using GitHub Codespaces:

1. Click the green "Code" button at the top of this repository
2. Select "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the environment to load
5. Use the terminal to compile and run your programme

## Tips and Hints

- Always allocate the array of pointers **first**, then allocate each row
- Always deallocate rows **before** deallocating the array of pointers
- Draw memory diagrams to visualise the structure
- Test with small matrices (2x2 or 3x3) first
- For transpose, remember: new_rows = old_cols, new_cols = old_rows

## Common Mistakes to Avoid

- Forgetting to allocate each individual row
- Using `delete` instead of `delete[]`
- Deallocating in wrong order (rows must be deleted first)
- Trying to add matrices with different dimensions
- Not handling the dimension change in transpose correctly

## Extension Challenges (Optional)

If you finish early and want extra practice:

1. **Matrix Multiplication**: Implement matrix multiplication (requires dimensions check)
2. **Rotate 90°**: Rotate the matrix 90 degrees clockwise
3. **Diagonal Sums**: Calculate sums of main and anti-diagonals
4. **Identity Matrix**: Generate an identity matrix of size n
5. **File I/O**: Save/load matrices from files
6. **Jagged Arrays**: Allow rows to have different lengths (advanced!)

## Need Help?

- Review the lecture notes on 2D dynamic arrays
- Remember the allocation pattern: array of pointers first, then each row
- Test deallocation with valgrind to check for leaks
- Start with simpler operations (fill, display) before complex ones (transpose)
- Draw pictures of memory layout

Good luck mastering 2D dynamic arrays!
