/**
 * Project 4: Student Records System
 * COS 110 - Pointers and Dynamic Memory
 *
 * A menu-driven programme for managing student records using dynamic arrays.
 *
 * Learning focus:
 * - Dynamic arrays of structs
 * - Memory management in larger applications
 * - Searching and sorting with pointers
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Student structure
struct Student
{
    char studentNumber[20];
    char name[50];
    int marks[3];
    double average;
};

// Function prototypes
void displayMenu();
void addStudent(Student* students, int& count, int capacity);
void displayAllStudents(Student* students, int count);
void searchStudent(Student* students, int count);
void findTopStudent(Student* students, int count);
void calculateClassAverage(Student* students, int count);
void sortByAverage(Student* students, int count);
double calculateAverage(int mark1, int mark2, int mark3);

int main()
{
    Student* students = 0;  // Pointer to dynamic array
    int capacity = 0;       // Maximum number of students
    int count = 0;          // Current number of students added

    cout << "=== Student Records System ===" << endl << endl;

    // Get the number of students to track
    cout << "How many students would you like to track? ";
    cin >> capacity;
    cin.ignore();  // Clear newline from buffer

    // TODO: Allocate the dynamic array
    // students = new Student[capacity];

    // TODO: Check if allocation succeeded

    int choice = 0;

    while (choice != 7)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear newline

        switch (choice)
        {
            case 1:
                addStudent(students, count, capacity);
                break;
            case 2:
                displayAllStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                findTopStudent(students, count);
                break;
            case 5:
                calculateClassAverage(students, count);
                break;
            case 6:
                sortByAverage(students, count);
                break;
            case 7:
                cout << "Cleaning up memory..." << endl;
                // TODO: Deallocate the array
                // delete[] students;
                // students = 0;
                cout << "Programme complete!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
        }
    }

    return 0;
}

void displayMenu()
{
    cout << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Add student record" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Search for student" << endl;
    cout << "4. Find top student" << endl;
    cout << "5. Calculate class average" << endl;
    cout << "6. Sort by average" << endl;
    cout << "7. Exit" << endl << endl;
}

void addStudent(Student* students, int& count, int capacity)
{
    cout << endl << "--- Add Student Record ---" << endl;

    // TODO: Check if array is full
    if (count >= capacity)
    {
        cout << "Cannot add more students. Array is full." << endl;
        return;
    }

    cout << "Student " << (count + 1) << " of " << capacity << ":" << endl << endl;

    // Get student information
    cout << "Student number: ";
    // TODO: Read student number into students[count].studentNumber
    // Use cin.getline() for strings with possible spaces

    cout << "Student name: ";
    // TODO: Read name into students[count].name

    // Get marks with validation
    for (int i = 0; i < 3; i++)
    {
        cout << "Module " << (i + 1) << " mark: ";
        // TODO: Read mark into students[count].marks[i]
        // TODO: Validate mark is between 0 and 100
    }

    // TODO: Calculate and store the average
    // students[count].average = calculateAverage(...);

    cout << endl << "Student added. Average: " << fixed << setprecision(2);
    cout << students[count].average << "%" << endl;

    count++;  // Increment the count
}

void displayAllStudents(Student* students, int count)
{
    cout << endl << "--- All Student Records ---" << endl << endl;

    // TODO: Check if there are any students to display
    if (count == 0)
    {
        cout << "No student records to display." << endl;
        return;
    }

    // Display table header
    cout << left;
    cout << setw(15) << "Student Number" << " | ";
    cout << setw(20) << "Name" << " | ";
    cout << setw(5) << "Mod1" << " | ";
    cout << setw(5) << "Mod2" << " | ";
    cout << setw(5) << "Mod3" << " | ";
    cout << "Average" << endl;
    cout << string(75, \'-\') << endl;

    // TODO: Loop through and display each student
    for (int i = 0; i < count; i++)
    {
        // TODO: Display students[i] information in table format
        // Use setw() for alignment
    }

    cout << endl;
}

void searchStudent(Student* students, int count)
{
    cout << endl << "--- Search for Student ---" << endl << endl;

    // TODO: Check if there are any students
    if (count == 0)
    {
        cout << "No student records to search." << endl;
        return;
    }

    char searchNumber[20];
    cout << "Enter student number to search: ";
    cin.getline(searchNumber, 20);

    // TODO: Search for the student
    // Use strcmp() to compare C-strings
    // If found, display their full record
    // If not found, display appropriate message

    cout << "TODO: Implement search functionality" << endl;
}

void findTopStudent(Student* students, int count)
{
    cout << endl << "--- Top Student ---" << endl << endl;

    // TODO: Check if there are any students
    if (count == 0)
    {
        cout << "No student records available." << endl;
        return;
    }

    // TODO: Find student with highest average
    // Keep track of index of top student
    // Display their information

    cout << "TODO: Implement find top student" << endl;
}

void calculateClassAverage(Student* students, int count)
{
    cout << endl << "--- Class Average ---" << endl << endl;

    // TODO: Check if there are any students
    if (count == 0)
    {
        cout << "No student records available." << endl;
        return;
    }

    // TODO: Calculate the average of all student averages
    double total = 0.0;
    // Loop through and sum up all averages
    // Divide by count

    cout << "TODO: Implement class average calculation" << endl;
}

void sortByAverage(Student* students, int count)
{
    cout << endl << "--- Sort by Average ---" << endl << endl;

    // TODO: Check if there are any students
    if (count == 0)
    {
        cout << "No student records to sort." << endl;
        return;
    }

    // TODO: Implement sorting (bubble sort is fine)
    // Sort in descending order (highest average first)
    // Swap entire Student structs

    cout << "Students sorted by average (descending):" << endl;

    // TODO: Display sorted list
    displayAllStudents(students, count);
}

double calculateAverage(int mark1, int mark2, int mark3)
{
    // TODO: Calculate and return average of three marks
    return 0.0;  // Placeholder
}
