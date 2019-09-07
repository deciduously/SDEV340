/*
* SDEV340 Week 2 Problem 1
* Convert an integer x: 0 <= x <= 9999 into its English string representation
* Benjamin Lovy
*/

#include <iostream>
#include <string>

using std::string;

// Class for pretty-printing a number 0-9999
class Numbers
{
    unsigned int number;
    static string hundred;
    static string lessThan20[];
    static string tensFromTwenty[];
    static string thousand;

public:
    Numbers(unsigned int value); // Constructor
    void print() const;          // Write the english representation to stdout
    // Static helper functions to print portions of numbers
    static void printLessThan20(unsigned int n);
    static void printLessThan100(unsigned int n);
    static void printLessThan1000(unsigned int n);
};

// Statics
string Numbers::hundred = "hundred";
string Numbers::lessThan20[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::tensFromTwenty[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string Numbers::thousand = "thousand";

void Numbers::printLessThan20(unsigned int n)
{
    std::cout << lessThan20[n];
}

void Numbers::printLessThan100(unsigned int n)
{
    if (n >= 20)
    {
        // get tens place and ones place
        unsigned int ones = n % 10;
        unsigned int tens = n / 10; // interger division will truncate the ones
        std::cout << tensFromTwenty[tens - 2];
        // Only display ones if not zero
        if (ones > 0)
            std::cout << " " << lessThan20[ones];
    }
    else
        printLessThan20(n);
}

void Numbers::printLessThan1000(unsigned int n)
{
    if (n == 0)
        std::cout << lessThan20[n];
    else
    {
        unsigned int hundreds = n / 100;
        std::cout << lessThan20[hundreds] << " " << hundred;
        unsigned int rest = n - (100 * hundreds);
        if (rest > 0)
        {
            std::cout << " ";
            printLessThan100(rest);
        }
    }
}

// Constructor
Numbers::Numbers(unsigned int value)
{
    number = value;
}

// Write the english representation to stdout
void Numbers::print() const
{
    using std::cout;
    if (number >= 1000)
    {
        unsigned int thousands = number / 1000;
        std::cout << lessThan20[thousands] << " " << thousand;
        unsigned int rest = number - (1000 * thousands);
        if (rest > 0)
        {
            std::cout << " ";
            printLessThan1000(rest);
        }
    }
    else
        printLessThan1000(number);
}

int main()
{
    using std::cin;
    using std::cout;
    // Collect number in range
    unsigned int userVal;
    do
    {
        cout << "Enter number 0 - 9999> ";
        cin >> userVal;
    } while (userVal > 9999);
    // Instantiate object
    Numbers userNum(userVal);
    // Print output
    userNum.print();
    return 0;
}