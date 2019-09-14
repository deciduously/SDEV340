/*
* SDEV340 Week 3 Problem 2
* Ask for a First, Middle, and Last name from a user, then display as 'Last, First Middle'
* Benjamin Lovy
*/

#include <cstring>
#include <iostream>

// Maximum buffer size for each name character array
const unsigned int MAX = 40;

// Class to re-arrange a three-part name
class NameArranger
{
    char first[MAX];
    char middle[MAX];
    char last[MAX];
    // Nicely display the member character arrays by building a fourth character array
    void prettyPrint() const;

public:
    // Default constructor will prompt for name and display result
    NameArranger();
};

// Default constructor will prompt for name and display result
NameArranger::NameArranger()
{
    using std::cin;
    using std::cout;
    // Prompt for names and store inputs
    cout << "Enter first name: ";
    cin.getline(first, MAX);
    cout << "Enter middle name: ";
    cin.getline(middle, MAX);
    cout << "Enter last name: ";
    cin.getline(last, MAX);
    // Display result
    prettyPrint();
}

// Nicely display the member character arrays by building a fourth character array
void NameArranger::prettyPrint() const
{
    // fillers
    char space[] = " ";
    char comma[] = ",";
    // Get lengths of each member
    int firstLen = strlen(first);
    int middleLen = strlen(middle);
    int lastLen = strlen(last);
    // we will be adding a comma and two spaces, and a null terminator
    int outputLen = firstLen + middleLen + lastLen + 4;

    // Init output array, starting with last name
    char output[outputLen];
    strcpy(output, last);

    // add comma and space
    strcat(output, comma);
    strcat(output, space);
    // first name
    strcat(output, first);
    // just space
    strcat(output, space);
    // middle name
    strcat(output, middle);
    // send cstring to stdout
    std::cout << output << std::endl;
}

int main()
{
    // Instantiate object
    NameArranger na;
    // Exit success
    return 0;
}