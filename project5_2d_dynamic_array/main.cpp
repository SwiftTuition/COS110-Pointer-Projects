/**
 * Project 5: 2D Dynamic Array Manager
 * COS 110 - Pointers and Dynamic Memory
 *
 * A programme for managing 2D dynamic arrays (matrices) with various operations.
 *
 * Learning focus:
 * - Two-dimensional dynamic array allocation
 * - Pointer-to-pointer types (int**)
 * - Proper multi-level deallocation
 * - Matrix operations
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void displayMenu();
void fillManually(int** matrix, int rows, int cols);
void fillRandom(int** matrix, int rows, int cols);
void displayMatrix(int** matrix, int rows, int cols);
void calculateRowSums(int** matrix, int rows, int cols);
void calculateColumnSums(int** matrix, int rows, int cols);
void findMinMax(int** matrix, int rows, int cols);
void transposeMatrix(int**& matrix, int& rows, int& cols);
void addMatrices(int** matrix, int rows, int cols);
void deallocateMatrix(int** matrix, int rows);

int main()
{
    int** matrix = 0;
    int rows = 0;
    int cols = 0;

    cout << "=== 2D Dynamic Array Manager ===" << endl << endl;

    // Get matrix dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // TODO: Validate dimensions
    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid dimensions. Programme terminated." << endl;
        return 1;
    }

    cout << endl << "Matrix allocated: " << rows << " rows x " << cols << " columns" << endl;

    // TODO: Allocate 2D array
    // Step 1: Allocate array of row pointers
    // matrix = new int*[rows];
    
    // Step 2: Allocate each row
    // for (int i = 0; i < rows; i++)
    // {
    //     matrix[i] = new int[cols];
    // }

    // Seed random number generator
    srand(time(0));

    int choice = 0;

    while (choice != 9)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                fillManually(matrix, rows, cols);
                break;
            case 2:
                fillRandom(matrix, rows, cols);
                break;
            case 3:
                displayMatrix(matrix, rows, cols);
                break;
            case 4:
                calculateRowSums(matrix, rows, cols);
                break;
            case 5:
                calculateColumnSums(matrix, rows, cols);
                break;
            case 6:
                findMinMax(matrix, rows, cols);
                break;
            case 7:
                transposeMatrix(matrix, rows, cols);
                break;
            case 8:
                addMatrices(matrix, rows, cols);
                break;
            case 9:
                cout << "Deallocating matrix..." << endl;
                deallocateMatrix(matrix, rows);
                cout << "Programme complete!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMenu()
{
    cout << endl << "Main Menu:" << endl;
    cout << "1. Fill matrix manually" << endl;
    cout << "2. Fill matrix with random values" << endl;
    cout << "3. Display matrix" << endl;
    cout << "4. Calculate row sums" << endl;
    cout << "5. Calculate column sums" << endl;
    cout << "6. Find min and max" << endl;
    cout << "7. Transpose matrix" << endl;
    cout << "8. Add another matrix" << endl;
    cout << "9. Exit" << endl << endl;
}

void fillManually(int** matrix, int rows, int cols)
{
    cout << "--- Fill Matrix Manually ---" << endl << endl;

    // TODO: Use nested loops to get input for each element
    // Outer loop: rows (i from 0 to rows-1)
    // Inner loop: columns (j from 0 to cols-1)
    // Prompt: "Enter value for [i][j]: "
    // Store in matrix[i][j]

    cout << "TODO: Implement manual fill" << endl;
}

void fillRandom(int** matrix, int rows, int cols)
{
    cout << "--- Fill Matrix with Random Values ---" << endl << endl;

    // TODO: Use nested loops to fill with random values
    // matrix[i][j] = rand() % 100;  // Random value 0-99

    cout << "Matrix filled with random values (0-99)." << endl;
}

void displayMatrix(int** matrix, int rows, int cols)
{
    cout << "--- Current Matrix (" << rows << " x " << cols << ") ---" << endl;

    // TODO: Use nested loops to display matrix
    // Use setw(5) for alignment
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << setw(5) << matrix[i][j];
    //     }
    //     cout << endl;
    // }

    cout << "TODO: Implement display" << endl;
}

void calculateRowSums(int** matrix, int rows, int cols)
{
    cout << "--- Row Sums ---" << endl;

    // TODO: For each row, calculate sum of all columns
    // for (int i = 0; i < rows; i++)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < cols; j++)
    //     {
    //         sum += matrix[i][j];
    //     }
    //     cout << "Row " << i << ": " << sum << endl;
    // }

    cout << "TODO: Implement row sums" << endl;
}

void calculateColumnSums(int** matrix, int rows, int cols)
{
    cout << "--- Column Sums ---" << endl;

    // TODO: For each column, calculate sum of all rows
    // Note: Outer loop is columns, inner loop is rows!
    // for (int j = 0; j < cols; j++)
    // {
    //     int sum = 0;
    //     for (int i = 0; i < rows; i++)
    //     {
    //         sum += matrix[i][j];
    //     }
    //     cout << "Column " << j << ": " << sum << endl;
    // }

    cout << "TODO: Implement column sums" << endl;
}

void findMinMax(int** matrix, int rows, int cols)
{
    cout << "--- Min and Max Values ---" << endl;

    // TODO: Find minimum and maximum values
    // Keep track of min/max values and their positions
    // Start with first element as both min and max

    cout << "TODO: Implement min/max finder" << endl;
}

void transposeMatrix(int**& matrix, int& rows, int& cols)
{
    cout << "--- Transpose Matrix ---" << endl;
    cout << "Original matrix was " << rows << " x " << cols << endl;

    // TODO: Create new matrix with swapped dimensions
    // int** newMatrix = new int*[cols];  // Note: cols becomes rows!
    // for (int i = 0; i < cols; i++)
    // {
    //     newMatrix[i] = new int[rows];  // rows becomes cols!
    // }

    // TODO: Copy with swapped indices
    // newMatrix[j][i] = matrix[i][j];

    // TODO: Deallocate old matrix
    // deallocateMatrix(matrix, rows);

    // TODO: Update matrix pointer and dimensions
    // matrix = newMatrix;
    // int temp = rows;
    // rows = cols;
    // cols = temp;

    cout << "TODO: Implement transpose" << endl;
}

void addMatrices(int** matrix, int rows, int cols)
{
    cout << "--- Add Another Matrix ---" << endl << endl;

    int rows2, cols2;
    cout << "Enter rows for second matrix: ";
    cin >> rows2;
    cout << "Enter columns for second matrix: ";
    cin >> cols2;

    // TODO: Check if dimensions match
    if (rows2 != rows || cols2 != cols)
    {
        cout << "Dimensions do not match! Cannot add matrices." << endl;
        return;
    }

    // TODO: Allocate second matrix
    // TODO: Fill second matrix
    // TODO: Create result matrix
    // TODO: Add corresponding elements
    // TODO: Display result
    // TODO: Deallocate temporary matrices

    cout << "TODO: Implement matrix addition" << endl;
}

void deallocateMatrix(int** matrix, int rows)
{
    // TODO: Deallocate each row first
    // for (int i = 0; i < rows; i++)
    // {
    //     delete[] matrix[i];
    // }

    // TODO: Then deallocate array of pointers
    // delete[] matrix;

    // TODO: Set to NULL
    // matrix = 0;
}
