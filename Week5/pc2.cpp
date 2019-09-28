/*
* SDEV 340 Week 5 Problem 2
* Write a recursive multiplication function and demonstrate with user-given input
* Benjamin Lovy
*/

#include <iostream>
#include <limits>

class RecursiveMultiplier
{
    unsigned int m;
    unsigned int n;
    // Identity of addition function
    static const int IDENTITY_ADD;
    // Identity of multiplication function
    static const int IDENTITY_MULT;
    // Maximum number allowed
    static const unsigned int MAX;
    // Recursive multiplier method
    static int recmult(unsigned int a, unsigned int b)
    {
        // if a is less than b, swap the numbers
        if (a < b)
        {
            // Call recursive function with identity of the addition sub-task as starting point
            return go(b, a);
        }
        else
            return go(a, b);
    }

    // Recursive inner function
    static int go(unsigned int a, unsigned int b)
    {
        if (b == IDENTITY_ADD || a == IDENTITY_ADD)
            return IDENTITY_ADD;
        else if (b == IDENTITY_MULT)
            return a;
        else
            return a + go(a, b - 1); // NOT tail recursive
    }

public:
    // Default constructor will prompt for input
    RecursiveMultiplier();
    // Recursively multiply m and n
    int multiply() const;
};

// Stream overload
std::ostream &operator<<(std::ostream &stream, const RecursiveMultiplier rm)
{
    stream << "m * n = " << rm.multiply();
    return stream;
}

int main()
{
    // Instantiate
    RecursiveMultiplier rm;
    // Show result
    std::cout << rm;
    // Exit success;
    return 0;
}

// Identity of addition function
const int RecursiveMultiplier::IDENTITY_ADD = 0;
// Identity of multiplication function
const int RecursiveMultiplier::IDENTITY_MULT = 1;
// Maximum number allowed for each operand - half the size of an int
const unsigned int RecursiveMultiplier::MAX = std::numeric_limits<short>::max();

// Default constructor will prompt for input
RecursiveMultiplier::RecursiveMultiplier()
{
    using std::cin;
    using std::cout;
    int userM, userN;
    do
    {
        cout << "Enter value for m in range [0, " << MAX << "]> ";
        cin >> userM;
    } while (userM > MAX);
    m = userM;
    do
    {
        cout << "Enter value for n in range [0, " << MAX << "]> ";
        cin >> userN;
    } while (userN > MAX);
    n = userN;
}

// Recursively multiply m and n
int RecursiveMultiplier::multiply() const
{
    return recmult(m, n);
}