/**
 * Project 3: Pointer Arithmetic Workshop
 * COS 110 - Pointers and Dynamic Memory
 *
 * An interactive workshop demonstrating pointer arithmetic concepts.
 *
 * Learning focus:
 * - Pointer arithmetic with different data types
 * - Relationship between arrays and pointers
 * - Pointer differences and offset calculations
 * - Memory address calculations
 */

#include <iostream>
using namespace std;

// Function prototypes
void section1_basicPointerArithmetic();
void section2_subscriptVsPointer();
void section3_pointerDifferences();
void section4_differentDataTypes();
void interactiveExercises();

int main()
{
    cout << "=== Pointer Arithmetic Workshop ===" << endl << endl;

    // Section 1: Basic pointer arithmetic
    section1_basicPointerArithmetic();

    // Section 2: Array subscript vs pointer notation
    section2_subscriptVsPointer();

    // Section 3: Pointer differences
    section3_pointerDifferences();

    // Section 4: Different data types
    section4_differentDataTypes();

    // Interactive exercises
    interactiveExercises();

    cout << "Programme complete!" << endl;

    return 0;
}

void section1_basicPointerArithmetic()
{
    cout << "--- Section 1: Basic Pointer Arithmetic ---" << endl << endl;

    // TODO: Create an array
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "We have an array: int arr[] = {10, 20, 30, 40, 50};" << endl;
    cout << "The array starts at memory address: " << arr << endl << endl;

    cout << "Let's explore pointer arithmetic:" << endl << endl;

    // TODO: Display each element's address and value using pointer arithmetic
    // For example:
    // cout << "arr points to:      " << arr << "  (value: " << *arr << ")" << endl;
    // cout << "arr + 1 points to:  " << (arr + 1) << "  (value: " << *(arr + 1) << ")" << endl;
    // Continue for all elements...

    cout << endl;
    cout << "Notice: Each address increases by " << sizeof(int) << " bytes (sizeof(int) = " << sizeof(int) << ")" << endl;
    cout << endl;
}

void section2_subscriptVsPointer()
{
    cout << "--- Section 2: Array Subscript vs Pointer Notation ---" << endl << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    // TODO: Show equivalence between arr[i] and *(arr + i)
    // For each element, display both notations
    // For example:
    // cout << "arr[0] is the same as *(arr + 0) = " << *(arr + 0) << endl;
    // Continue for all elements...

    cout << endl;
}

void section3_pointerDifferences()
{
    cout << "--- Section 3: Pointer Differences ---" << endl << endl;

    int arr[] = {100, 200, 300, 400, 500};
    int* ptr1 = arr;      // Points to first element
    int* ptr2 = arr + 4;  // Points to last element

    cout << "We have two pointers:" << endl;
    cout << "ptr1 points to: " << ptr1 << " (value: " << *ptr1 << ")" << endl;
    cout << "ptr2 points to: " << ptr2 << " (value: " << *ptr2 << ")" << endl << endl;

    // TODO: Calculate and display the pointer difference
    // int difference = ptr2 - ptr1;
    // cout << "ptr2 - ptr1 = " << difference << " elements" << endl;

    // TODO: Calculate byte difference
    // cout << "Byte difference: " << (char*)ptr2 - (char*)ptr1 << " bytes" << endl;

    cout << endl;
}

void section4_differentDataTypes()
{
    cout << "--- Section 4: Different Data Types ---" << endl << endl;

    // Demonstrate with int
    int intArr[] = {1, 2, 3};
    cout << "int array:" << endl;
    cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
    // TODO: Show address differences
    cout << endl;

    // Demonstrate with char
    char charArr[] = {'A', 'B', 'C'};
    cout << "char array:" << endl;
    cout << "sizeof(char) = " << sizeof(char) << " byte" << endl;
    // TODO: Show address differences
    cout << endl;

    // Demonstrate with double
    double doubleArr[] = {1.1, 2.2, 3.3};
    cout << "double array:" << endl;
    cout << "sizeof(double) = " << sizeof(double) << " bytes" << endl;
    // TODO: Show address differences
    cout << endl;
}

void interactiveExercises()
{
    cout << "--- Interactive Exercises ---" << endl << endl;

    int score = 0;
    int total = 5;

    // Exercise 1
    cout << "Exercise 1:" << endl;
    int values[] = {100, 200, 300, 400};
    int* ptr = values;

    cout << "Given: int values[] = {100, 200, 300, 400};" << endl;
    cout << "       int* ptr = values;" << endl << endl;
    cout << "Question: What is the value of *(ptr + 2)?" << endl;
    cout << "Your answer: ";

    int answer1;
    cin >> answer1;

    // TODO: Check if answer is correct (should be 300)
    // TODO: Update score if correct
    // TODO: Display explanation

    cout << endl;

    // TODO: Implement Exercise 2
    // Given a pointer and offset, ask for the value

    // TODO: Implement Exercise 3
    // Ask about pointer differences

    // TODO: Implement Exercise 4
    // Convert subscript to pointer notation

    // TODO: Implement Exercise 5
    // Predict the next memory address

    // Display final score
    cout << "=== Exercise Results ===" << endl;
    cout << "You scored " << score << " out of " << total << endl;
    double percentage = (static_cast<double>(score) / total) * 100;
    cout << "Percentage: " << percentage << "%" << endl << endl;
}
