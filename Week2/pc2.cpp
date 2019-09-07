/*
* SDEV340 Week 2 Problem 2
* Print the calendar date from a number 0-365
* Benjamin Lovy
*/

#include <iostream>
#include <string>

using std::string;

// Class for getting a calendar date from a number
class DayOfYear
{
    unsigned int number;
    static string months[];

public:
    DayOfYear(unsigned int number);
    // Print the calendar year for this number
    void print() const;
    static unsigned int endOfMonth(unsigned int n); // lat day of month n, n < numMonths
};

// Statics
string DayOfYear::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

unsigned int DayOfYear::endOfMonth(unsigned int n)
{
    switch (n)
    {
    case 0:
        return 31;
        break;
    case 1:
        return 31 + 28;
        break;
    case 2:
        return 31 + 28 + 31;
        break;
    case 3:
        return 31 + 28 + 31 + 30;
        break;
    case 4:
        return 31 + 28 + 31 + 30 + 31;
        break;
    case 5:
        return 31 + 28 + 31 + 30 + 31 + 30;
        break;
    case 6:
        return 31 + 28 + 31 + 30 + 31 + 30 + 31;
        break;
    case 7:
        return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
    case 8:
        return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
    case 9:
        return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
    case 10:
        return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    case 11:
        return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31;
        break;
    default:
        std::cerr << "Warning: unknown month index!\n";
        return 0;
        break;
    }
}

DayOfYear::DayOfYear(unsigned int number)
{
    this->number = number;
}

void DayOfYear::print() const
{
    // Find which month we're in
    unsigned int month;
    for (unsigned int i = 0; i < 12; i++)
    {
        int endOfCurrent = endOfMonth(i);
        if (number <= endOfCurrent)
        {
            month = i;
            break;
        }
    }
    // Figure out what day of the month it is
    unsigned int rest;
    if (month > 0)
    {
        rest = number - endOfMonth(month - 1);
    }
    else
    {
        rest = number;
    }
    std::cout << months[month] << " " << rest;
}

int main()
{
    using std::cin;
    using std::cout;
    // Collect number in range
    unsigned int userVal;
    do
    {
        cout << "Enter number 0 - 365> ";
        cin >> userVal;
    } while (userVal > 365);
    // Instantiate object
    DayOfYear userNum(userVal);
    // Print output
    userNum.print();
    return 0;
}