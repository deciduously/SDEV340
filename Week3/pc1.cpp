/*
* SDEV340 Week 3 Problem 1
* Allow user to count vowels, consonants, or both in a C-string
* Benjamin Lovy
*/

#include <cstring>
#include <iostream>

// Class for counting vowels and consonants in a C-string
class LetterCounter
{
    // String to count
    char *cString;
    // Maximum string length
    static unsigned int maxLength;
    // Vowel characters
    static char vowels[];
    // Get number of consonants in cString
    int countConsonants() const;
    // Get number of vowels in cString
    int countVowels() const;
    // Get amount of spaces in cString
    int countSpaces() const;
    // Display number of consonants in cString
    void printConsonants() const;
    // Display number of vowels in cString
    void printVowels() const;
    // Predicate for whether character is lower case vowel
    static bool isVowel(const char c);
    // Prompt for a new cString
    void promptCString();
    // Show the letter counting options
    void showMenu() const;

public:
    // Default constructor will prompt user for string
    LetterCounter();
    // Destructor
    ~LetterCounter();
    // Run loop
    void run();
};

unsigned int LetterCounter::maxLength = 80;

char LetterCounter::vowels[] = {'a', 'e', 'i', 'o', 'u'}; // Excluding 'y' - that's a much tougher problem

// Default constructor will prompt user for string
LetterCounter::LetterCounter()
{
    promptCString();
}

// Destructor
LetterCounter::~LetterCounter()
{
    delete cString;
}

// Get number of consonants in cString
int LetterCounter::countConsonants() const
{
    int ret = 0;
    for (int i = 0; cString[i] != '\0'; i++)
    {
        if (tolower(cString[i]) >= 97 && tolower(cString[i]) <= 122 && !isVowel(cString[i]))
            ret++;
    }
    return ret;
}

// Get number of vowels in cString
int LetterCounter::countVowels() const
{
    int ret = 0;
    for (int i = 0; cString[i] != '\0'; i++)
    {
        if (isVowel(cString[i]))
            ret++;
    }
    return ret;
}

// Get amount of spaces in cString
int LetterCounter::countSpaces() const
{
    int ret = 0;
    for (int i = 0; cString[i] != '\0'; i++)
    {
        if (cString[i] == ' ')
            ret++;
    }
    return ret;
}

// Display number of consonants in cString
void LetterCounter::printConsonants() const
{
    std::cout << "Number of consonants in " << cString << ": " << countConsonants() << "\n";
}

// Display number of vowels in cString
void LetterCounter::printVowels() const
{
    std::cout << "Number of vowels in " << cString << ": " << countVowels() << "\n";
}

// Predicate for whether character is lower case vowel
bool LetterCounter::isVowel(const char c)
{
    // Vowel size won't change
    for (int i = 0; i < 5; i++)
    {
        // if match, return true
        if (vowels[i] == tolower(c))
            return true;
    }
    // If not found, return false
    return false;
}

// Prompt for a new cString
void LetterCounter::promptCString()
{
    using std::cin;
    using std::cout;
    // Instantiate to null string
    cString = new char;
    // Prompt user
    char userInput[maxLength];
    cout << "Enter string> ";
    cin.getline(userInput, maxLength);
    // Copy input into string
    strcpy(cString, userInput);
}

// Run loop
void LetterCounter::run()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    // Loop forever until exit
    for (;;)
    {
        char userInput;
        do
        {
            showMenu();
            cin >> userInput;
        } while (!cin);
        switch (tolower(userInput))
        {
        case 'a':
            printVowels();
            break;
        case 'b':
            printConsonants();
            break;
        case 'c':
            printVowels();
            printConsonants();
            break;
        case 'd':
            // Clear current and prompt for new
            delete cString;
            cin.ignore();
            promptCString();
            break;
        case 'e':
            // Quit!
            cout
                << "Goodbye!\n";
            return;
        default:
            cerr << "Unknown option, try again\n";
            continue;
        }
    }
}

// Show the letter counting options
void LetterCounter::showMenu() const
{
    using std::cout;
    cout << "String: " << cString << "\n\n";
    cout << "A) Count the number of vowels in the string\n";
    cout << "B) Count the number of consonants in the string\n";
    cout << "C) Count both the vowels and consonants in the string\n";
    cout << "D) Enter another string\n";
    cout << "E) Exit\n";
    cout << "> ";
}

int main()
{
    // Instantiate object
    LetterCounter lc;
    // Run loop
    lc.run();
    // Exit success
    return 0;
}