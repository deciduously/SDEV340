/*
* SDEV 340 Week 6 Problem 2
* Recursively determine whether a given member is in an array
* Benjamin Lovy
*/

#include <iostream>
#include <limits>

class RecursiveMemberTest
{
    int *arr;
    int arrLength;
    // Recursively search for value in array of ints
    static bool isMember(int *array, int length, int value)
    {
        // If we find it, we're done
        if (*array == value)
            return true;
        if (length == 1)
        {
            // If we're at the end, we didn't find it
            return false;
        }
        else
        {
            return isMember(array + 1, length - 1, value);
        }
    }

public:
    // Default constructor will prompt for array
    RecursiveMemberTest();
    // Destructor
    ~RecursiveMemberTest();
    // Prompt user for number and search for it, displaying result
    void findAndShow();
};

int main()
{
    // Instantiate object
    RecursiveMemberTest rmt;
    // Run
    rmt.findAndShow();
    // Exit success
    return 0;
}

// Default constructor will prompt for array
RecursiveMemberTest::RecursiveMemberTest()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    // Init length to 0
    arrLength = 0;
    // Prompt for length 1 or greter
    do
    {
        cout << "Enter array length> ";
        cin >> arrLength;
        if (cin.fail())
        {
            // Reset cin, ignore input
            cin.clear();
            // Ignore bad input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Admonish user
            cerr << "Please enter a positive integer.\n";
            arrLength = 0;
        }
    } while (arrLength < 1);
    // Init array
    arr = new int[arrLength];
    // Prompt for entry
    for (int i = 0; i < arrLength; i++)
    {
        // Loop until success
        for (;;)
        {
            cout << "Enter value " << i << "> ";
            cin >> arr[i];
            if (cin.fail())
            {
                // Reset cin, ignore input
                cin.clear();
                // Ignore bad input
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Admonish user
                cerr << "Please enter an integer.\n";
            }
            else
                break;
        }
    }
}

// Destructor
RecursiveMemberTest::~RecursiveMemberTest()
{
    delete[] arr;
}

// Prompt user for number and search for it, displaying result
void RecursiveMemberTest::findAndShow()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    // Prompt for value to search for
    int needle;
    for (;;)
    {
        cout << "Enter value to search for> ";
        cin >> needle;
        if (cin.fail())
        {
            // Reset cin, ignore input
            cin.clear();
            // Ignore bad input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Admonish user
            cerr << "Please enter an integer.\n";
        }
        else
            break;
    }
    bool result = isMember(arr, arrLength, needle);
    cout << "Found: ";
    if (result)
        cout
            << "true";
    else
        cout << "false";
    cout << "\n";
}