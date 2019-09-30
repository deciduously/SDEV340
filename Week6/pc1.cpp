/*
* SDEV 340 Week 6 Problem 1
* Recursively sum a user-input array of numbers
* Benjamin Lovy
*/

#include <iostream>
#include <limits>

class RecursiveArraySum
{
    int *arr;
    int arrLength;
    // Recursively calculate sum of array of given length
    static int sum(int *values, unsigned int length)
    {
        if (length == 1)
            return *values;
        else
            return *values + sum(values + 1, length - 1);
    }

public:
    // Default constructor prompts for array
    RecursiveArraySum();
    // Destructor
    ~RecursiveArraySum();
    // Display sum of gathered array
    void showSum();
};

int main()
{
    // Instantiate object
    RecursiveArraySum ras;
    // Show result
    ras.showSum();
    // Exit success
    return 0;
}

// Default constructor prompts for array
RecursiveArraySum::RecursiveArraySum()
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

RecursiveArraySum::~RecursiveArraySum()
{
    delete[] arr;
}

// Display sum of gathered array
void RecursiveArraySum::showSum()
{
    int result = sum(arr, arrLength);
    std::cout << "Sum: " << result << "\n";
}