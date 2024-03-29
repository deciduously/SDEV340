/*
* SDEV340 Problem 1
* Gather statistical data about movie watching habits, and display averages
* Benjamin Lovy
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// Function prototypes
double mean(const int *const numArr, int numStudents);
double median(int *const numArr, int numStudents);
int mode(const int *const numArr, int numStudents);

int main()
{
    // Imports
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::endl;

    // Prompt for total number of students
    // Loop while input is not usable
    int numStudents = 0;
    do
    {
        cout << "How many students were surveyed? ";
        cin >> numStudents;

        if (!cin)
        {
            // reset failbit
            cin.clear();
            // Ignore bad input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Admonish user
            cerr << "Please enter a positive number." << endl;
            numStudents = 0;
        }

    } while (numStudents <= 0);

    // Allocate input array
    int *movieArr = new int[numStudents];

    // Prompt user to populate input array with collected data
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Enter amount of movies watched for Student #" << i + 1 << "> ";
        cin >> movieArr[i];
    }

    // Output averages
    cout << endl
         << "Mean: " << mean(movieArr, numStudents) << endl;
    cout << "Median: " << median(movieArr, numStudents) << endl;
    cout << "Mode: " << mode(movieArr, numStudents) << endl;

    // Clean up array
    delete[] movieArr;
    movieArr = nullptr;

    // Return success
    return 0;
}

// Calculate the mean of an array of ints
double mean(const int *const numArr, int numStudents)
{
    int sum = 0;
    for (int i = 0; i < numStudents; i++)
    {
        sum += *(numArr + i);
    }

    return static_cast<double>(sum) / static_cast<double>(numStudents);
}

// Calculate the median of an array of ints
double median(int *const numArr, int numStudents)
{
    // first, sort arrray
    std::sort(numArr, numArr + numStudents);
    // If numStudents is odd, return the middle, else get the two around the middle and return the midpoint
    if (numStudents % 2 != 0)
    {
        size_t middleIdx = (numStudents - 1) / 2;
        return *(numArr + middleIdx);
    }
    else
    {
        // grab higher and lower values
        size_t middleIdx = (numStudents / 2);
        int lower = *(numArr + (middleIdx - 1));
        int higher = *(numArr + middleIdx);
        // add them and divide by two
        return (static_cast<double>(higher) + static_cast<double>(lower)) / 2.0;
    }
}

// Frequency type
typedef struct statFreq
{
    int member;
    int freq;
    statFreq()
    {
        member = 0;
        freq = 0;
    }
    statFreq(int n)
    {
        member = n;
        freq = 1;
    }
    void inc()
    {
        freq++;
    }
} statFreq;

// Calculate the mode of an array of ints
int mode(const int *const numArr, int numStudents)
{
    // Collect frequencies of each element
    std::vector<statFreq> frequencies = {};

    // For each element, check if seen before.  If so, increment, frequency, otherwise push new frequency
    for (int i = 0; i < numStudents; i++)
    {
        bool found = false;
        for (auto& f : frequencies)
        {
            if (f.member == numArr[i])
            {
                // If we found an entry, increment the frequency and move on
                f.inc();
                found = true;
                break;
            }
        }
        if (!found) {
            // If we didn't locate and increment a frequency, add a new one
            frequencies.push_back(statFreq(numArr[i]));
        }
    }

    // Return the highest frequency
    statFreq max{};

    for (auto f : frequencies)
    {
        if (f.freq > max.freq)
        {
            max = f;
        }
    }

    return max.member;
}
