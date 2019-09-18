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
    using std::ios;
    using std::string;
    // seek to end of file
    punchlineFile.seekg(0L, ios::end);
}

// Display joke and punchline
void JokeViewer::joke()
{
    displayJoke();
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