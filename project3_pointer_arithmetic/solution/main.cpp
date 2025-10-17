/**
 * Project 3: Pointer Arithmetic Workshop - SOLUTION
 * COS 110 - Pointers and Dynamic Memory
 *
 * An interactive workshop demonstrating pointer arithmetic concepts.
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

    section1_basicPointerArithmetic();
    section2_subscriptVsPointer();
    section3_pointerDifferences();
    section4_differentDataTypes();
    interactiveExercises();

    cout << "Programme complete!" << endl;

    return 0;
}

void section1_basicPointerArithmetic()
{
    cout << "--- Section 1: Basic Pointer Arithmetic ---" << endl << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "We have an array: int arr[] = {10, 20, 30, 40, 50};" << endl;
    cout << "The array starts at memory address: " << arr << endl << endl;

    cout << "Let\'s explore pointer arithmetic:" << endl << endl;

    // Display each element's address and value using pointer arithmetic
    for (int i = 0; i < size; i++)
    {
        cout << "arr + " << i << " points to: " << (arr + i);
        cout << "  (value: " << *(arr + i) << ")" << endl;
    }

    cout << endl;
    cout << "Notice: Each address increases by " << sizeof(int) << " bytes (sizeof(int) = " << sizeof(int) << ")" << endl;
    cout << endl;
}

void section2_subscriptVsPointer()
{
    cout << "--- Section 2: Array Subscript vs Pointer Notation ---" << endl << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "These two notations are equivalent:" << endl << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] is the same as *(arr + " << i << ") = " << *(arr + i) << endl;
    }

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

    // Calculate and display the pointer difference
    int difference = ptr2 - ptr1;
    cout << "ptr2 - ptr1 = " << difference << " elements" << endl;

    // Calculate byte difference
    long byteDiff = (char*)ptr2 - (char*)ptr1;
    cout << "Byte difference: " << byteDiff << " bytes" << endl;
    cout << "(Which is " << difference << " elements * " << sizeof(int) << " bytes per int)" << endl;

    cout << endl;
}

void section4_differentDataTypes()
{
    cout << "--- Section 4: Different Data Types ---" << endl << endl;

    // Demonstrate with int
    int intArr[] = {1, 2, 3};
    cout << "int array:" << endl;
    cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
    cout << "intArr:     " << (void*)intArr << endl;
    cout << "intArr + 1: " << (void*)(intArr + 1) << endl;
    cout << "Difference: " << ((char*)(intArr + 1) - (char*)intArr) << " bytes" << endl;
    cout << endl;

    // Demonstrate with char
    char charArr[] = {\'A\', \'B\', \'C\'};
    cout << "char array:" << endl;
    cout << "sizeof(char) = " << sizeof(char) << " byte" << endl;
    cout << "charArr:     " << (void*)charArr << endl;
    cout << "charArr + 1: " << (void*)(charArr + 1) << endl;
    cout << "Difference: " << ((charArr + 1) - charArr) << " byte" << endl;
    cout << endl;

    // Demonstrate with double
    double doubleArr[] = {1.1, 2.2, 3.3};
    cout << "double array:" << endl;
    cout << "sizeof(double) = " << sizeof(double) << " bytes" << endl;
    cout << "doubleArr:     " << (void*)doubleArr << endl;
    cout << "doubleArr + 1: " << (void*)(doubleArr + 1) << endl;
    cout << "Difference: " << ((char*)(doubleArr + 1) - (char*)doubleArr) << " bytes" << endl;
    cout << endl;

    cout << "Key point: Adding 1 to a pointer increases the address by sizeof(type) bytes!" << endl;
    cout << endl;
}

void interactiveExercises()
{
    cout << "--- Interactive Exercises ---" << endl << endl;

    int score = 0;
    int total = 5;

    // Exercise 1
    {
        cout << "Exercise 1:" << endl;
        int values[] = {100, 200, 300, 400};
        int* ptr = values;

        cout << "Given: int values[] = {100, 200, 300, 400};" << endl;
        cout << "       int* ptr = values;" << endl << endl;
        cout << "Question: What is the value of *(ptr + 2)?" << endl;
        cout << "Your answer: ";

        int answer1;
        cin >> answer1;

        if (answer1 == 300)
        {
            cout << "Correct! *(ptr + 2) accesses the element at index 2, which is 300." << endl;
            score++;
        }
        else
        {
            cout << "Incorrect. *(ptr + 2) is the same as values[2], which is 300." << endl;
        }
        cout << endl;
    }

    // Exercise 2
    {
        cout << "Exercise 2:" << endl;
        int data[] = {50, 60, 70, 80, 90};
        int* p = data + 1;  // Points to second element

        cout << "Given: int data[] = {50, 60, 70, 80, 90};" << endl;
        cout << "       int* p = data + 1;" << endl << endl;
        cout << "Question: What is the value of *(p + 2)?" << endl;
        cout << "Your answer: ";

        int answer2;
        cin >> answer2;

        if (answer2 == 80)
        {
            cout << "Correct! p points to data[1] (60), so p + 2 points to data[3] (80)." << endl;
            score++;
        }
        else
        {
            cout << "Incorrect. p points to 60, so p + 2 points to 80." << endl;
        }
        cout << endl;
    }

    // Exercise 3
    {
        cout << "Exercise 3:" << endl;
        int nums[] = {10, 20, 30, 40, 50, 60};
        int* first = nums;
        int* last = nums + 5;

        cout << "Given: int nums[] = {10, 20, 30, 40, 50, 60};" << endl;
        cout << "       int* first = nums;" << endl;
        cout << "       int* last = nums + 5;" << endl << endl;
        cout << "Question: What is the value of (last - first)?" << endl;
        cout << "Your answer: ";

        int answer3;
        cin >> answer3;

        if (answer3 == 5)
        {
            cout << "Correct! The pointer difference gives the number of elements between them." << endl;
            score++;
        }
        else
        {
            cout << "Incorrect. Subtracting pointers gives the number of elements: 5." << endl;
        }
        cout << endl;
    }

    // Exercise 4
    {
        cout << "Exercise 4:" << endl;
        int sequence[] = {2, 4, 6, 8};

        cout << "Given: int sequence[] = {2, 4, 6, 8};" << endl << endl;
        cout << "Question: Rewrite sequence[3] using pointer notation." << endl;
        cout << "What value does it represent? ";

        int answer4;
        cin >> answer4;

        if (answer4 == 8)
        {
            cout << "Correct! sequence[3] is *(sequence + 3) = 8." << endl;
            score++;
        }
        else
        {
            cout << "Incorrect. sequence[3] is *(sequence + 3) = 8." << endl;
        }
        cout << endl;
    }

    // Exercise 5
    {
        cout << "Exercise 5:" << endl;
        cout << "Given: sizeof(int) = " << sizeof(int) << " bytes" << endl;
        cout << "       int* ptr is at address 0x1000" << endl << endl;
        cout << "Question: What address does (ptr + 3) point to? (in hex)" << endl;
        cout << "Hint: Calculate 0x1000 + (3 * " << sizeof(int) << ")" << endl;
        cout << "Enter as decimal: ";

        int answer5;
        cin >> answer5;

        int expected = 0x1000 + (3 * sizeof(int));
        if (answer5 == expected)
        {
            cout << "Correct! Adding 3 to the pointer adds 3 * sizeof(int) = " << (3 * sizeof(int)) << " bytes." << endl;
            score++;
        }
        else
        {
            cout << "Incorrect. The answer is " << expected << " (0x" << hex << expected << dec << ")." << endl;
            cout << "Adding 3 adds 3 * sizeof(int) = " << (3 * sizeof(int)) << " bytes to the address." << endl;
        }
        cout << endl;
    }

    // Display final score
    cout << "=== Exercise Results ===" << endl;
    cout << "You scored " << score << " out of " << total << endl;
    double percentage = (static_cast<double>(score) / total) * 100;
    cout << "Percentage: " << percentage << "%" << endl << endl;

    if (score == total)
    {
        cout << "Perfect score! You\'ve mastered pointer arithmetic!" << endl;
    }
    else if (score >= 3)
    {
        cout << "Good job! Review the missed questions to improve further." << endl;
    }
    else
    {
        cout << "Keep practising! Pointer arithmetic takes time to master." << endl;
    }
    cout << endl;
}
