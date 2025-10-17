/**
 * Project 2: Memory Leak Detective
 * COS 110 - Pointers and Dynamic Memory
 *
 * An educational programme that helps students identify and fix
 * common memory management errors in C++.
 *
 * Learning focus:
 * - Identifying memory leaks
 * - Recognising dangling pointers
 * - Understanding proper delete usage
 * - Debugging memory errors
 */

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void displayMenu();
void scenario1_simpleMemoryLeak();
void scenario2_danglingPointer();
void scenario3_doubleDeletion();
void scenario4_wrongDeleteOperator();
void scenario5_lostAddress();
void scenario6_arrayMemoryLeak();

int main()
{
    int choice = 0;
    int score = 0;
    int attempted = 0;

    cout << "=== Memory Leak Detective ===" << endl;
    cout << "Learn to identify and fix memory management errors" << endl << endl;

    while (choice != 7)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        // TODO: Handle invalid input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                scenario1_simpleMemoryLeak();
                // TODO: Update score and attempted count
                break;
            case 2:
                scenario2_danglingPointer();
                // TODO: Update score and attempted count
                break;
            case 3:
                scenario3_doubleDeletion();
                // TODO: Update score and attempted count
                break;
            case 4:
                scenario4_wrongDeleteOperator();
                // TODO: Update score and attempted count
                break;
            case 5:
                scenario5_lostAddress();
                // TODO: Update score and attempted count
                break;
            case 6:
                scenario6_arrayMemoryLeak();
                // TODO: Update score and attempted count
                break;
            case 7:
                cout << "=== Final Results ===" << endl;
                // TODO: Display final score
                cout << "Thank you for using Memory Leak Detective!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select 1-7." << endl << endl;
        }
    }

    return 0;
}

void displayMenu()
{
    cout << "Choose a scenario to investigate:" << endl;
    cout << "1. Simple Memory Leak" << endl;
    cout << "2. Dangling Pointer" << endl;
    cout << "3. Double Deletion" << endl;
    cout << "4. Wrong Delete Operator" << endl;
    cout << "5. Lost Address" << endl;
    cout << "6. Array Memory Leak" << endl;
    cout << "7. Exit" << endl << endl;
}

void scenario1_simpleMemoryLeak()
{
    cout << "--- Scenario 1: Simple Memory Leak ---" << endl << endl;

    cout << "Here's the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void leakyFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* numbers = new int[100];" << endl;
    cout << "    numbers[0] = 42;" << endl;
    cout << "    cout << numbers[0] << endl;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What's wrong with this code?" << endl;
    cout << "(a) Nothing - it's fine" << endl;
    cout << "(b) Memory leak - never deleted" << endl;
    cout << "(c) Dangling pointer" << endl;
    cout << "(d) Wrong delete operator" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    // TODO: Check if answer is correct (answer should be 'b' or 'B')
    // TODO: Display appropriate feedback
    // TODO: Show the fixed code

    cout << "Here's the fixed code:" << endl;
    cout << "-------------------" << endl;
    cout << "void fixedFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* numbers = new int[100];" << endl;
    cout << "    numbers[0] = 42;" << endl;
    cout << "    cout << numbers[0] << endl;" << endl;
    cout << "    delete[] numbers;  // Properly deallocate" << endl;
    cout << "    numbers = 0;        // Avoid dangling pointer" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    // TODO: Wait for user to press Enter
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
}

void scenario2_danglingPointer()
{
    cout << "--- Scenario 2: Dangling Pointer ---" << endl << endl;

    // TODO: Implement this scenario
    // Show buggy code with dangling pointer
    // Ask user to identify the problem
    // Show fixed code
    // Explain the issue

    cout << "TODO: Implement Scenario 2" << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
}

void scenario3_doubleDeletion()
{
    cout << "--- Scenario 3: Double Deletion ---" << endl << endl;

    // TODO: Implement this scenario
    // Show code that deletes the same pointer twice
    // Ask user to identify the problem
    // Show fixed code

    cout << "TODO: Implement Scenario 3" << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
}

void scenario4_wrongDeleteOperator()
{
    cout << "--- Scenario 4: Wrong Delete Operator ---" << endl << endl;

    // TODO: Implement this scenario
    // Show code using delete instead of delete[] or vice versa
    // Ask user to identify the problem
    // Show fixed code

    cout << "TODO: Implement Scenario 4" << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
}

void scenario5_lostAddress()
{
    cout << "--- Scenario 5: Lost Address ---" << endl << endl;

    // TODO: Implement this scenario
    // Show code that overwrites a pointer before freeing memory
    // Ask user to identify the problem
    // Show fixed code

    cout << "TODO: Implement Scenario 5" << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
}

void scenario6_arrayMemoryLeak()
{
    cout << "--- Scenario 6: Array Memory Leak ---" << endl << endl;

    // TODO: Implement this scenario
    // Show code with a more complex array memory leak
    // Ask user to identify the problem
    // Show fixed code

    cout << "TODO: Implement Scenario 6" << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
}
