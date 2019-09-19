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
    static const std::string jokeFilename;
    static const std::string punchlineFilename;
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

const std::string JokeViewer::jokeFilename = "joke.txt";
const std::string JokeViewer::punchlineFilename = "punchline.txt";

// Constructor
JokeViewer::JokeViewer()
{
    jokeFile.open(jokeFilename);
    punchlineFile.open(punchlineFilename);
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
    using std::string;
    // seek to last character of file
    punchlineFile.seekg(-1L, ios::end);
    // if its a newline, seek back again
    if (punchlineFile.peek() == '\n')
        punchlineFile.seekg(-1, ios::cur);

    // seek backwards to previous newline
    char ch;
    do
    {
        punchlineFile.seekg(-1L, ios::cur);
        punchlineFile.get(ch);
        cout << ch;
    } while (ch != '\n');

    // output the rest of the file
    // first, clear clags - EOF got set
    punchlineFile.clear();
    while (!punchlineFile.eof())
    {
        punchlineFile.seekg(1L, ios::cur);
    }
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