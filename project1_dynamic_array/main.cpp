/**
 * Project 1: Dynamic Array Manager
 * COS 110 - Pointers and Dynamic Memory
 *
 * This programme manages a dynamic array of integers,
 * allowing the user to input values and view statistics.
 *
 * Learning focus:
 * - Dynamic memory allocation with new/delete[]
 * - Pointer operations and array access
 * - Memory management and leak prevention
 */

#include <iostream>
using namespace std;

int main()
{
    // TODO: Declare a pointer for the dynamic array
    // int* array = ?

    // Display programme header
    cout << "=== Dynamic Array Manager ===" << endl << endl;

    // TODO: Get the array size from the user
    cout << "How many integers would you like to store? ";
    int size;
    cin >> size;

    // TODO: Handle edge case - what if size is 0 or negative?

    cout << endl;

    // TODO: Allocate the dynamic array
    // array = new int[?];

    // TODO: Fill the array with user input
    // Use a loop to get each value
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value " << (i + 1) << ": ";
        // TODO: Store the value in the array
        // You can use array[i] or *(array + i)
    }

    cout << endl;

    // TODO: Display all values in the array
    cout << "Your array contains: ";
    // TODO: Loop through and print each value

    cout << endl << endl;

    // TODO: Calculate statistics
    cout << "Statistics:" << endl;

    // Calculate sum
    int sum = 0;
    // TODO: Add up all values in the array

    cout << "Sum: " << sum << endl;

    // Calculate average
    // TODO: Handle division by zero if size is 0
    if (size > 0)
    {
        double average = 0.0;  // TODO: Calculate average
        cout << "Average: " << average << endl;
    }

    // Find minimum and maximum
    if (size > 0)
    {
        int min = 0;  // TODO: Find the minimum value
        int max = 0;  // TODO: Find the maximum value

        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
    }

    cout << endl;

    // TODO: Deallocate the array
    // Use delete[] for arrays, not delete
    // delete[] array;

    // TODO: Set pointer to NULL after deletion
    // array = 0;  // or NULL

    cout << "Memory deallocated. Programme complete." << endl;

    return 0;
}
