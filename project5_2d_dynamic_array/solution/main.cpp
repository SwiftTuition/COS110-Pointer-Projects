/**
 * Project 5: 2D Dynamic Array Manager - SOLUTION
 * COS 110 - Pointers and Dynamic Memory
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

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid dimensions. Programme terminated." << endl;
        return 1;
    }

    cout << endl << "Matrix allocated: " << rows << " rows x " << cols << " columns" << endl;

    // Allocate 2D array
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

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

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << endl << "Matrix filled successfully." << endl;
}

void fillRandom(int** matrix, int rows, int cols)
{
    cout << "--- Fill Matrix with Random Values ---" << endl << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    cout << "Matrix filled with random values (0-99)." << endl;
}

void displayMatrix(int** matrix, int rows, int cols)
{
    cout << "--- Current Matrix (" << rows << " x " << cols << ") ---" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
}

void calculateRowSums(int** matrix, int rows, int cols)
{
    cout << "--- Row Sums ---" << endl;

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
        cout << "Row " << i << ": " << sum << endl;
    }

    cout << endl;
}

void calculateColumnSums(int** matrix, int rows, int cols)
{
    cout << "--- Column Sums ---" << endl;

    for (int j = 0; j < cols; j++)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum += matrix[i][j];
        }
        cout << "Column " << j << ": " << sum << endl;
    }

    cout << endl;
}

void findMinMax(int** matrix, int rows, int cols)
{
    cout << "--- Min and Max Values ---" << endl;

    int minVal = matrix[0][0];
    int maxVal = matrix[0][0];
    int minRow = 0, minCol = 0;
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < minVal)
            {
                minVal = matrix[i][j];
                minRow = i;
                minCol = j;
            }
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "Minimum: " << minVal << " (at row " << minRow << ", column " << minCol << ")" << endl;
    cout << "Maximum: " << maxVal << " (at row " << maxRow << ", column " << maxCol << ")" << endl;
    cout << endl;
}

void transposeMatrix(int**& matrix, int& rows, int& cols)
{
    cout << "--- Transpose Matrix ---" << endl;
    cout << "Original matrix was " << rows << " x " << cols << endl;

    // Create new matrix with swapped dimensions
    int** newMatrix = new int*[cols];
    for (int i = 0; i < cols; i++)
    {
        newMatrix[i] = new int[rows];
    }

    // Copy with swapped indices
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            newMatrix[j][i] = matrix[i][j];
        }
    }

    // Deallocate old matrix
    deallocateMatrix(matrix, rows);

    // Update matrix pointer and dimensions
    matrix = newMatrix;
    int temp = rows;
    rows = cols;
    cols = temp;

    cout << "Transposed matrix is " << rows << " x " << cols << endl << endl;

    cout << "New matrix:" << endl;
    displayMatrix(matrix, rows, cols);
}

void addMatrices(int** matrix, int rows, int cols)
{
    cout << "--- Add Another Matrix ---" << endl << endl;

    int rows2, cols2;
    cout << "Enter rows for second matrix: ";
    cin >> rows2;
    cout << "Enter columns for second matrix: ";
    cin >> cols2;

    if (rows2 != rows || cols2 != cols)
    {
        cout << "Dimensions do not match! Cannot add matrices." << endl;
        cout << "First matrix is " << rows << " x " << cols << endl;
        cout << "Second matrix is " << rows2 << " x " << cols2 << endl;
        return;
    }

    // Allocate second matrix
    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = new int[cols2];
    }

    // Fill second matrix
    cout << endl << "Fill second matrix:" << endl;
    char fillChoice;
    cout << "Fill (m)anually or (r)andomly? ";
    cin >> fillChoice;

    if (fillChoice == 'm' || fillChoice == 'M')
    {
        fillManually(matrix2, rows2, cols2);
    }
    else
    {
        fillRandom(matrix2, rows2, cols2);
    }

    // Create result matrix
    int** result = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new int[cols];
    }

    // Add corresponding elements
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }

    cout << endl << "Result of addition:" << endl;
    displayMatrix(result, rows, cols);

    // Deallocate temporary matrices
    deallocateMatrix(matrix2, rows2);
    deallocateMatrix(result, rows);
}

void deallocateMatrix(int** matrix, int rows)
{
    // Deallocate each row first
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    // Then deallocate array of pointers
    delete[] matrix;
}
