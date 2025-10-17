# Project 4: Student Records System

**Difficulty:** EO2
**Topic:** Dynamic Arrays with Structs and Memory Management

## Learning Objectives

By completing this project, you will:
- Work with structs and dynamic arrays together
- Manage dynamically allocated arrays of structs
- Implement searching and sorting algorithms using pointers
- Practice proper memory management in a realistic scenario
- Build a complete menu-driven application

## Problem Statement

Create a student records management system that stores student information using dynamic arrays. Your programme should:

1. Allow the user to specify how many students to track
2. Store each student's:
   - Student number (string)
   - Name (string)
   - Marks for 3 modules (integers)
   - Average mark (calculated)
3. Provide functionality to:
   - Add student records
   - Display all students
   - Search for a specific student
   - Find the student with the highest average
   - Calculate the class average
   - Sort students by average mark
4. Properly manage all dynamic memory

## Sample Output

```
=== Student Records System ===

How many students would you like to track? 3

Main Menu:
1. Add student record
2. Display all students
3. Search for student
4. Find top student
5. Calculate class average
6. Sort by average
7. Exit

Enter your choice: 1

--- Add Student Record ---
Student 1 of 3:

Student number: u12345678
Student name: Alice Smith
Module 1 mark: 75
Module 2 mark: 82
Module 3 mark: 79

Student added. Average: 78.67%

Enter your choice: 1

--- Add Student Record ---
Student 2 of 3:

Student number: u23456789
Student name: Bob Jones
Module 1 mark: 90
Module 2 mark: 88
Module 3 mark: 92

Student added. Average: 90%

[Continue adding students...]

Enter your choice: 2

--- All Student Records ---

Student Number | Name           | Mod1 | Mod2 | Mod3 | Average
---------------|----------------|------|------|------|--------
u12345678      | Alice Smith    |  75  |  82  |  79  | 78.67%
u23456789      | Bob Jones      |  90  |  88  |  92  | 90.00%
u34567890      | Carol Williams |  68  |  71  |  73  | 70.67%

Enter your choice: 4

--- Top Student ---
Bob Jones (u23456789) has the highest average: 90%

Enter your choice: 7

Cleaning up memory...
Programme complete!
```

## Data Structure

Use a struct to represent each student:

```cpp
struct Student
{
    char studentNumber[20];
    char name[50];
    int marks[3];
    double average;
};
```

Then create a dynamic array of Students:

```cpp
Student* students = new Student[numStudents];
```

## Requirements

- Use **dynamic memory allocation** for the student array
- Calculate and store the **average mark** for each student
- Implement **all 6 menu options** with proper functionality
- Use **British spelling** in output (programme, colour, etc.)
- Include **input validation** (check for valid marks 0-100)
- Properly **deallocate memory** before exiting
- Handle **edge cases** (empty records, invalid searches, etc.)

## Menu Options Details

### 1. Add Student Record
- Prompt for all student information
- Validate that marks are between 0 and 100
- Calculate and store the average
- Keep track of how many students have been added
- Don't allow adding more than the specified capacity

### 2. Display All Students
- Show all students in a formatted table
- Include all fields (number, name, 3 marks, average)
- Handle case where no students have been added yet

### 3. Search for Student
- Ask for student number to search for
- Display full record if found
- Display appropriate message if not found

### 4. Find Top Student
- Find the student with the highest average
- Display their full information
- Handle case where no students exist yet

### 5. Calculate Class Average
- Calculate the average of all student averages
- Display the result
- Handle empty records

### 6. Sort by Average
- Sort students by average mark (descending order)
- Display sorted list
- Use any sorting algorithm (bubble sort is fine)

## Compilation and Running

### Using the Makefile (Recommended)

```bash
make
./student_records
```

To clean up compiled files:
```bash
make clean
```

### Manual Compilation

```bash
g++ -std=c++98 -Wall -Wextra -o student_records main.cpp
./student_records
```

## GitHub Codespaces

You can work on this project directly in your browser using GitHub Codespaces:

1. Click the green "Code" button at the top of this repository
2. Select "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the environment to load
5. Use the terminal to compile and run your programme

## Tips and Hints

- Use a counter variable to track how many students have been added
- Remember that arrays of structs still use dynamic allocation
- You can access struct members through pointer: `students[i].name` or `(students + i)->name`
- For string input with spaces, consider using `cin.getline()`
- Sort by swapping entire struct objects, not just individual fields

## Common Mistakes to Avoid

- Forgetting to allocate the array before using it
- Not checking if array is full before adding
- Accessing uninitialised student records
- Memory leaks (not deallocating the array)
- Not handling the case when no students have been added

## Extension Challenges (Optional)

If you finish early and want extra practice:

1. **Dynamic Resizing**: Allow adding more students than initially specified by reallocating
2. **File I/O**: Save records to a file and load them on startup
3. **Multiple Sorts**: Allow sorting by name or student number
4. **Edit Records**: Add functionality to modify existing records
5. **Delete Records**: Remove specific student records
6. **Statistics**: Add more stats (median, standard deviation, pass rate)

## Need Help?

- Review the lecture notes on dynamic arrays and structs
- Start with the basic structure (menu loop, array allocation)
- Implement one menu option at a time and test thoroughly
- Draw memory diagrams to visualise your data structure
- Remember: every `new` needs a `delete[]`

Good luck building your student records system!
