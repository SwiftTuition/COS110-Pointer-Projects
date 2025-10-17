/**
 * Project 2: Memory Leak Detective - SOLUTION
 * COS 110 - Pointers and Dynamic Memory
 *
 * An educational programme that helps students identify and fix
 * common memory management errors in C++.
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
bool checkAnswer(char userAnswer, char correctAnswer);

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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl << endl;
            continue;
        }

        bool correct = false;

        switch (choice)
        {
            case 1:
                correct = scenario1_simpleMemoryLeak();
                attempted++;
                if (correct) score++;
                break;
            case 2:
                correct = scenario2_danglingPointer();
                attempted++;
                if (correct) score++;
                break;
            case 3:
                correct = scenario3_doubleDeletion();
                attempted++;
                if (correct) score++;
                break;
            case 4:
                correct = scenario4_wrongDeleteOperator();
                attempted++;
                if (correct) score++;
                break;
            case 5:
                correct = scenario5_lostAddress();
                attempted++;
                if (correct) score++;
                break;
            case 6:
                correct = scenario6_arrayMemoryLeak();
                attempted++;
                if (correct) score++;
                break;
            case 7:
                cout << "=== Final Results ===" << endl;
                cout << "You attempted " << attempted << " scenarios." << endl;
                if (attempted > 0)
                {
                    cout << "You got " << score << " correct." << endl;
                    double percentage = (static_cast<double>(score) / attempted) * 100;
                    cout << "Score: " << percentage << "%" << endl << endl;
                }
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

bool checkAnswer(char userAnswer, char correctAnswer)
{
    return (userAnswer == correctAnswer || userAnswer == correctAnswer + 32 || userAnswer == correctAnswer - 32);
}

bool scenario1_simpleMemoryLeak()
{
    cout << "--- Scenario 1: Simple Memory Leak ---" << endl << endl;

    cout << "Here\'s the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void leakyFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* numbers = new int[100];" << endl;
    cout << "    numbers[0] = 42;" << endl;
    cout << "    cout << numbers[0] << endl;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What\'s wrong with this code?" << endl;
    cout << "(a) Nothing - it\'s fine" << endl;
    cout << "(b) Memory leak - never deleted" << endl;
    cout << "(c) Dangling pointer" << endl;
    cout << "(d) Wrong delete operator" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    bool correct = checkAnswer(answer, \'b\');

    if (correct)
    {
        cout << "Correct! This code allocates 100 integers but never frees them." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is (b)." << endl;
        cout << "This code allocates 100 integers with \'new int[100]\' but never" << endl;
        cout << "calls \'delete[]\' to free the memory. This is a memory leak." << endl;
    }
    cout << endl;

    cout << "Here\'s the fixed code:" << endl;
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

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;

    return correct;
}

bool scenario2_danglingPointer()
{
    cout << "--- Scenario 2: Dangling Pointer ---" << endl << endl;

    cout << "Here\'s the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void danglingFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* ptr = new int(10);" << endl;
    cout << "    delete ptr;" << endl;
    cout << "    *ptr = 20;  // What happens here?" << endl;
    cout << "    cout << *ptr << endl;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What\'s the main problem with this code?" << endl;
    cout << "(a) Memory leak" << endl;
    cout << "(b) Using pointer after deletion (dangling pointer)" << endl;
    cout << "(c) Wrong delete operator" << endl;
    cout << "(d) Double deletion" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    bool correct = checkAnswer(answer, \'b\');

    if (correct)
    {
        cout << "Correct! After \'delete ptr\', the pointer becomes dangling." << endl;
        cout << "Accessing it with \'*ptr = 20\' is undefined behaviour." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is (b)." << endl;
        cout << "Once you delete a pointer, you can\'t use it anymore." << endl;
        cout << "The memory it pointed to has been freed and may be reused." << endl;
    }
    cout << endl;

    cout << "Here\'s the fixed code:" << endl;
    cout << "-------------------" << endl;
    cout << "void fixedFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* ptr = new int(10);" << endl;
    cout << "    cout << *ptr << endl;  // Use it before deletion" << endl;
    cout << "    delete ptr;" << endl;
    cout << "    ptr = 0;  // Set to NULL to avoid accidents" << endl;
    cout << "    // Don\'t use ptr after this point" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;

    return correct;
}

bool scenario3_doubleDeletion()
{
    cout << "--- Scenario 3: Double Deletion ---" << endl << endl;

    cout << "Here\'s the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void doubleDeleteFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* value = new int(42);" << endl;
    cout << "    delete value;" << endl;
    cout << "    delete value;  // Delete again?" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What\'s wrong with this code?" << endl;
    cout << "(a) Memory leak" << endl;
    cout << "(b) Wrong delete operator" << endl;
    cout << "(c) Deleting the same pointer twice" << endl;
    cout << "(d) Nothing - it\'s fine" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    bool correct = checkAnswer(answer, \'c\');

    if (correct)
    {
        cout << "Correct! Deleting the same pointer twice is undefined behaviour." << endl;
        cout << "It can cause crashes or corrupt the memory management system." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is (c)." << endl;
        cout << "After the first \'delete value\', the memory is freed." << endl;
        cout << "The second \'delete value\' tries to free already-freed memory." << endl;
    }
    cout << endl;

    cout << "Here\'s the fixed code:" << endl;
    cout << "-------------------" << endl;
    cout << "void fixedFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* value = new int(42);" << endl;
    cout << "    delete value;" << endl;
    cout << "    value = 0;  // Set to NULL after deletion" << endl;
    cout << "    // Now deleting again is safe (delete 0 does nothing)" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;

    return correct;
}

bool scenario4_wrongDeleteOperator()
{
    cout << "--- Scenario 4: Wrong Delete Operator ---" << endl << endl;

    cout << "Here\'s the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void wrongDeleteFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* arr = new int[50];" << endl;
    cout << "    arr[0] = 10;" << endl;
    cout << "    delete arr;  // Is this correct?" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What\'s wrong with this code?" << endl;
    cout << "(a) Memory leak" << endl;
    cout << "(b) Should use \'delete[]\' for arrays" << endl;
    cout << "(c) Dangling pointer" << endl;
    cout << "(d) Nothing - it\'s fine" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    bool correct = checkAnswer(answer, \'b\');

    if (correct)
    {
        cout << "Correct! Arrays allocated with \'new[]\' must be freed with \'delete[]\'" << endl;
        cout << "Using just \'delete\' can cause undefined behaviour and memory leaks." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is (b)." << endl;
        cout << "When you allocate an array with \'new int[50]\', you must" << endl;
        cout << "deallocate it with \'delete[] arr\', not just \'delete arr\'." << endl;
    }
    cout << endl;

    cout << "Here\'s the fixed code:" << endl;
    cout << "-------------------" << endl;
    cout << "void fixedFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* arr = new int[50];" << endl;
    cout << "    arr[0] = 10;" << endl;
    cout << "    delete[] arr;  // Correct: use delete[] for arrays" << endl;
    cout << "    arr = 0;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;

    return correct;
}

bool scenario5_lostAddress()
{
    cout << "--- Scenario 5: Lost Address ---" << endl << endl;

    cout << "Here\'s the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void lostAddressFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* first = new int(5);" << endl;
    cout << "    int* second = new int(10);" << endl;
    cout << "    first = second;  // Uh oh..." << endl;
    cout << "    delete first;" << endl;
    cout << "    delete second;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What\'s the main problem with this code?" << endl;
    cout << "(a) Double deletion" << endl;
    cout << "(b) Lost the address of the first allocation (memory leak)" << endl;
    cout << "(c) Wrong delete operator" << endl;
    cout << "(d) Dangling pointer" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    bool correct = checkAnswer(answer, \'b\');

    if (correct)
    {
        cout << "Correct! When \'first = second\', we lose the address of the" << endl;
        cout << "original allocation (the int with value 5). This is a memory leak." << endl;
        cout << "Additionally, we now delete the same memory twice (double deletion)." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is (b)." << endl;
        cout << "The line \'first = second\' makes both pointers point to the same" << endl;
        cout << "memory. The original memory (int with value 5) is now inaccessible." << endl;
    }
    cout << endl;

    cout << "Here\'s the fixed code:" << endl;
    cout << "-------------------" << endl;
    cout << "void fixedFunction()" << endl;
    cout << "{" << endl;
    cout << "    int* first = new int(5);" << endl;
    cout << "    int* second = new int(10);" << endl;
    cout << "    delete first;   // Delete first allocation" << endl;
    cout << "    delete second;  // Delete second allocation" << endl;
    cout << "    first = 0;" << endl;
    cout << "    second = 0;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;

    return correct;
}

bool scenario6_arrayMemoryLeak()
{
    cout << "--- Scenario 6: Array Memory Leak ---" << endl << endl;

    cout << "Here\'s the buggy code:" << endl;
    cout << "-------------------" << endl;
    cout << "void processData(int size)" << endl;
    cout << "{" << endl;
    cout << "    int* data = new int[size];" << endl;
    cout << "    for (int i = 0; i < size; i++)" << endl;
    cout << "        data[i] = i * 2;" << endl;
    cout << "    " << endl;
    cout << "    if (size > 100)" << endl;
    cout << "        return;  // Early exit!" << endl;
    cout << "    " << endl;
    cout << "    delete[] data;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "What\'s wrong with this code?" << endl;
    cout << "(a) Wrong delete operator" << endl;
    cout << "(b) Memory leak when size > 100" << endl;
    cout << "(c) Dangling pointer" << endl;
    cout << "(d) Nothing - it\'s fine" << endl << endl;

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    cout << endl;

    bool correct = checkAnswer(answer, \'b\');

    if (correct)
    {
        cout << "Correct! When size > 100, the function returns early without" << endl;
        cout << "deleting the array. This is a memory leak on that execution path." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is (b)." << endl;
        cout << "If the condition \'size > 100\' is true, the function returns" << endl;
        cout << "before reaching the \'delete[] data\' statement. The array is never freed." << endl;
    }
    cout << endl;

    cout << "Here\'s the fixed code:" << endl;
    cout << "-------------------" << endl;
    cout << "void fixedFunction(int size)" << endl;
    cout << "{" << endl;
    cout << "    int* data = new int[size];" << endl;
    cout << "    for (int i = 0; i < size; i++)" << endl;
    cout << "        data[i] = i * 2;" << endl;
    cout << "    " << endl;
    cout << "    if (size > 100)" << endl;
    cout << "    {" << endl;
    cout << "        delete[] data;  // Clean up before return" << endl;
    cout << "        data = 0;" << endl;
    cout << "        return;" << endl;
    cout << "    }" << endl;
    cout << "    " << endl;
    cout << "    delete[] data;" << endl;
    cout << "    data = 0;" << endl;
    cout << "}" << endl;
    cout << "-------------------" << endl << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;

    return correct;
}
