/*
* SDEV340 Week 3 Problem 2
* Ask for a first, middle, and last name from a user, then display as List, First Middle
* Benjamin Lovy
*/

#include <cstring>
#include <iostream>

// after reading, use a pointer and just change the pointer.  I think that's what wer'e getting at.

// Class to re-arrange a three-part name
class NameArranger
{
    char *first;
    char *middle;
    char *last;

public:
    // Default constructor will prompt for name and display result
    NameArranger();
    // Destructor
    ~NameArranger();
};

// Default constructor will prompt for name and display result
NameArranger::NameArranger()
{
    using std::cin;
    using std::cout;
    // Prompt for names
    char *f = new char;
    char *m = new char;
    char *l = new char;
    cout << "Enter name: ";
    cin.getline(f, ' ');
    cin.getline(m, ' ');
    cin.getline(l, ' ');
    cout << f << m << l;
}

// Destructor
NameArranger::~NameArranger()
{
    delete first;
    delete middle;
    delete last;
}

int main()
{
    // Instantiate object
    NameArranger na;
    // Exit success
    return 0;
}