/*
* SDEV 340 Week 5 Problem 1
* Write an iterative factorial function and demonstrate with user-given input
* Benjamin Lovy
*/

#include <iostream>

class IterativeFactorial
{
    // Value to compute
    unsigned int n;
    // Maximum value user can input
    static const unsigned int MAX;

public:
    // Default constructor will prompt for input
    IterativeFactorial();
    // Calculate factorial using a loop
    int factorial() const;
};

// Stream overload
std::ostream &operator<<(std::ostream &stream, const IterativeFactorial itf)
{
    stream << "n1: " << itf.factorial();
    return stream;
}

// Default constructor will prompt for input
IterativeFactorial::IterativeFactorial()
{
    using std::cin;
    using std::cout;
    unsigned int userInput;

    do
    {
        cout << "Enter value for n in the range [0, " << MAX << "]> ";
        cin >> userInput;
    } while (userInput > MAX);
    n = userInput;
}

int main()
{
    // Instantiate
    IterativeFactorial itf;
    // Show result
    std::cout << itf;
    // Exit success
    return 0;
}

// Calcultate factorial using a loop
int IterativeFactorial::factorial() const
{
    // Init to identity
    int ret = 1;
    for (int i = n; i > 0; i--)
    {
        ret *= i;
    }
    return ret;
}

// Maximum value user can input
const unsigned int IterativeFactorial::MAX = 16;