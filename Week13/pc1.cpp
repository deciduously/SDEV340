/*
* SDEV 340 Week 13 Problem 1
* Store the contents of a file reversed character-by-character into a second file
* November 19, 2019
* Benjamin Lovy
*/

#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class FileReverser
{
    std::string name;
    std::ifstream inFile;
    std::ofstream outFile;
    static std::string outSuffix;
    static void reverseFile(std::ifstream &in, std::ofstream &out);

public:
    class CouldNotOpenException;
    FileReverser(std::string filename);
    ~FileReverser();
    std::string outFileName() const;
};

void FileReverser::reverseFile(std::ifstream &in, std::ofstream &out)
{
    using std::stack;
    using std::vector;

    // init stack
    stack<char, vector<char>> characters;

    // push each character into the stack
    char c;
    while (in.get(c))
        characters.push(c);

    // write outFile by popping from stack
    while (!characters.empty())
    {
        out.put(characters.top());
        characters.pop();
    }
}

class FileReverser::CouldNotOpenException
{
public:
    std::string file;
    CouldNotOpenException(std::string s)
    {
        file = s;
    }
};

std::string FileReverser::outSuffix = "-reversed";

FileReverser::FileReverser(std::string filename)
{
    name = filename;
    // Open infile
    inFile.open(name);
    if (inFile.fail())
    {
        throw CouldNotOpenException(name);
    }
    // Create outfile
    outFile.open(outFileName());
    if (outFile.fail())
    {
        throw CouldNotOpenException(outFileName());
    }
    // Reverse file
    reverseFile(inFile, outFile);
}

FileReverser::~FileReverser()
{
    inFile.close();
    outFile.close();
}

std::string FileReverser::outFileName() const
{
    return name + outSuffix;
}

int main()
{
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::string;
    // Prompt for filename
    string name;
    cout << "Enter filename to reverse: ";
    getline(cin, name);
    // Run reverser
    try
    {
        FileReverser fr(name);
        cout << "Output saved to " << fr.outFileName() << "\n";
    }
    catch (FileReverser::CouldNotOpenException ex)
    {
        cerr << "Could not open " << ex.file << ".";
        std::exit(1);
    }
    // Exit success
    return 0;
}