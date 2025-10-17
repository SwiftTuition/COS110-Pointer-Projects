/**
 * Project 1: Dynamic Array Manager - SOLUTION
 * COS 110 - Pointers and Dynamic Memory
 *
 * This programme manages a dynamic array of integers,
 * allowing the user to input values and view statistics.
 */

#include <iostream>
using namespace std;

int main()
{
    int* array = 0;  // Initialise pointer to NULL
    int size = 0;

    // Display programme header
    cout << "=== Dynamic Array Manager ===" << endl << endl;

    // Get the array size from the user
    cout << "How many integers would you like to store? ";
    cin >> size;

    // Handle edge case - size must be positive
    if (size <= 0)
    {
        cout << "Invalid size. Programme terminated." << endl;
        return 1;
    }

    cout << endl;

    // Allocate the dynamic array
    array = new int[size];

    // Check if allocation succeeded (good practice)
    if (array == 0)
    {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    // Fill the array with user input
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> array[i];  // Could also use *(array + i)
    }

    cout << endl;

    // Display all values in the array
    cout << "Your array contains: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;

    // Calculate statistics
    cout << "Statistics:" << endl;

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    cout << "Sum: " << sum << endl;

    // Calculate average
    double average = static_cast<double>(sum) / size;
    cout << "Average: " << average << endl;

    // Find minimum and maximum
    int min = array[0];  // Start with first element
    int max = array[0];

    for (int i = 1; i < size; i++)  // Start from second element
    {
        // Using pointer arithmetic for demonstration
        if (*(array + i) < min)
        {
            min = *(array + i);
        }
        if (*(array + i) > max)
        {
            max = *(array + i);
        }
    }

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    cout << endl;

    // Deallocate the array
    delete[] array;

    // Set pointer to NULL after deletion to avoid dangling pointer
    array = 0;

    cout << "Memory deallocated. Programme complete." << endl;

    return 0;
}
