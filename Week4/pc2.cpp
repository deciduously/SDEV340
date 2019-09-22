/*
* SDEV 340 Week 4 Problem 2
* Display a joke form one file, then locate and siplay the punchline from another, discarding garbage
* Benjamin Lovy
*/

#include <fstream>
#include <iostream>
#include <string>

class JokeViewer
{
    std::ifstream jokeFile;
    std::ifstream punchlineFile;
    // Display each line in the jokefile
    void displayJoke();
    // Display the final line by seeking to the end
    void displayPunchline();

public:
    // Constructor
    JokeViewer();
    // Destructor
    ~JokeViewer();
    // Display joke and punchline
    void joke();
};

// Constructor
JokeViewer::JokeViewer()
{
    using std::cin;
    using std::cout;
    using std::string;
    string fileName;
    cout << "Enter joke filename> ";
    getline(cin, fileName);
    jokeFile.open(fileName);
    if (jokeFile.fail())
    {
        std::cerr << "The file was not found\n";
        std::exit(1);
    }
    cout << "Enter punchline filename> ";
    cin.clear();
    getline(cin, fileName);
    punchlineFile.open(fileName);
    if (punchlineFile.fail())
    {
        std::cerr << "The file was not found\n";
        std::exit(1);
    }
}

// Destructor
JokeViewer::~JokeViewer()
{
    jokeFile.close();
    punchlineFile.close();
}

// Display each line in the jokefile
void JokeViewer::displayJoke()
{
    using std::cin;
    using std::cout;
    using std::string;
    string line;
    while (getline(jokeFile, line))
    {
        cout << line << "\n";
    }
}

// Display the final line of the punchline
void JokeViewer::displayPunchline()
{
    using std::cout;
    using std::ios;
    using std::streampos;
    using std::string;

    // Seek through file
    // Store each beginning of line position
    // When EOF, jump back to latest stored pos

    // Storage for each beginning of line
    streampos latestLineBegin = punchlineFile.tellg();

    // Seek to end, locating the last line beginning
    while (!punchlineFile.eof())
    {
        punchlineFile.seekg(1L, ios::cur);
        char next = punchlineFile.peek();
        // If we find the end fo the line, overwrite the current line beginning
        if (next == '\n')
            latestLineBegin = punchlineFile.tellg() + 1L;
    }
    // Seek back to stored line beginning
    punchlineFile.clear();
    long offset = punchlineFile.tellg() - latestLineBegin;
    punchlineFile.seekg(-offset, ios::cur);

    // Display line
    string line;
    getline(punchlineFile, line);
    cout << line << "\n";
}

// Display joke and punchline
void JokeViewer::joke()
{
    displayJoke();
    displayPunchline();
}

int main()
{
    // Instantiate object
    JokeViewer jv;
    // Dsiplay joke
    jv.joke();
    // Exit success
    return 0;
}