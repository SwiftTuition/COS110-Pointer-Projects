/**
 * Project 4: Student Records System - SOLUTION
 * COS 110 - Pointers and Dynamic Memory
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

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
    Student* students = 0;
    int capacity = 0;
    int count = 0;

    cout << "=== Student Records System ===" << endl << endl;

    cout << "How many students would you like to track? ";
    cin >> capacity;
    cin.ignore();

    if (capacity <= 0)
    {
        cout << "Invalid capacity. Programme terminated." << endl;
        return 1;
    }

    students = new Student[capacity];

    if (students == 0)
    {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    int choice = 0;

    while (choice != 7)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

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
                delete[] students;
                students = 0;
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

    if (count >= capacity)
    {
        cout << "Cannot add more students. Array is full." << endl;
        return;
    }

    cout << "Student " << (count + 1) << " of " << capacity << ":" << endl << endl;

    cout << "Student number: ";
    cin.getline(students[count].studentNumber, 20);

    cout << "Student name: ";
    cin.getline(students[count].name, 50);

    for (int i = 0; i < 3; i++)
    {
        bool valid = false;
        while (!valid)
        {
            cout << "Module " << (i + 1) << " mark: ";
            cin >> students[count].marks[i];
            cin.ignore();

            if (students[count].marks[i] >= 0 && students[count].marks[i] <= 100)
            {
                valid = true;
            }
            else
            {
                cout << "Invalid mark. Please enter a value between 0 and 100." << endl;
            }
        }
    }

    students[count].average = calculateAverage(
        students[count].marks[0],
        students[count].marks[1],
        students[count].marks[2]
    );

    cout << endl << "Student added. Average: " << fixed << setprecision(2);
    cout << students[count].average << "%" << endl;

    count++;
}

void displayAllStudents(Student* students, int count)
{
    cout << endl << "--- All Student Records ---" << endl << endl;

    if (count == 0)
    {
        cout << "No student records to display." << endl;
        return;
    }

    cout << left;
    cout << setw(15) << "Student Number" << " | ";
    cout << setw(20) << "Name" << " | ";
    cout << setw(5) << "Mod1" << " | ";
    cout << setw(5) << "Mod2" << " | ";
    cout << setw(5) << "Mod3" << " | ";
    cout << "Average" << endl;
    cout << string(75, '-') << endl;

    for (int i = 0; i < count; i++)
    {
        cout << setw(15) << students[i].studentNumber << " | ";
        cout << setw(20) << students[i].name << " | ";
        cout << setw(5) << students[i].marks[0] << " | ";
        cout << setw(5) << students[i].marks[1] << " | ";
        cout << setw(5) << students[i].marks[2] << " | ";
        cout << fixed << setprecision(2) << students[i].average << "%" << endl;
    }

    cout << endl;
}

void searchStudent(Student* students, int count)
{
    cout << endl << "--- Search for Student ---" << endl << endl;

    if (count == 0)
    {
        cout << "No student records to search." << endl;
        return;
    }

    char searchNumber[20];
    cout << "Enter student number to search: ";
    cin.getline(searchNumber, 20);

    bool found = false;
    int foundIndex = -1;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].studentNumber, searchNumber) == 0)
        {
            found = true;
            foundIndex = i;
            break;
        }
    }

    if (found)
    {
        cout << endl << "Student found:" << endl;
        cout << "Student Number: " << students[foundIndex].studentNumber << endl;
        cout << "Name: " << students[foundIndex].name << endl;
        cout << "Module 1 mark: " << students[foundIndex].marks[0] << endl;
        cout << "Module 2 mark: " << students[foundIndex].marks[1] << endl;
        cout << "Module 3 mark: " << students[foundIndex].marks[2] << endl;
        cout << "Average: " << fixed << setprecision(2);
        cout << students[foundIndex].average << "%" << endl;
    }
    else
    {
        cout << "Student with number " << searchNumber << " not found." << endl;
    }
}

void findTopStudent(Student* students, int count)
{
    cout << endl << "--- Top Student ---" << endl << endl;

    if (count == 0)
    {
        cout << "No student records available." << endl;
        return;
    }

    int topIndex = 0;
    for (int i = 1; i < count; i++)
    {
        if (students[i].average > students[topIndex].average)
        {
            topIndex = i;
        }
    }

    cout << students[topIndex].name << " (" << students[topIndex].studentNumber << ")";
    cout << " has the highest average: " << fixed << setprecision(2);
    cout << students[topIndex].average << "%" << endl;
}

void calculateClassAverage(Student* students, int count)
{
    cout << endl << "--- Class Average ---" << endl << endl;

    if (count == 0)
    {
        cout << "No student records available." << endl;
        return;
    }

    double total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += students[i].average;
    }

    double classAvg = total / count;

    cout << "Class average: " << fixed << setprecision(2) << classAvg << "%" << endl;
}

void sortByAverage(Student* students, int count)
{
    cout << endl << "--- Sort by Average ---" << endl << endl;

    if (count == 0)
    {
        cout << "No student records to sort." << endl;
        return;
    }

    // Bubble sort - descending order
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].average < students[j + 1].average)
            {
                // Swap entire structs
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "Students sorted by average (descending):" << endl;
    displayAllStudents(students, count);
}

double calculateAverage(int mark1, int mark2, int mark3)
{
    return (mark1 + mark2 + mark3) / 3.0;
}
