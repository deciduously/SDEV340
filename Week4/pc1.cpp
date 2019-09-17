/*
* SDEV 340 Week 4 Problem 1
* Display the first 10 lines of a filename given.  If entire file is shown, indicate this
* Benjamin Lovy
*/

#include <fstream>
#include <iostream>
#include <string>

class FileDisplay
{
    std::ifstream f;

public:
    // Constructor
    FileDisplay();
    // Destructor
    ~FileDisplay();
    // Show first ten lines of file
    void showPreview();
};

// Constructor
FileDisplay::FileDisplay()
{
    using std::cin;
    using std::cout;
    using std::string;
    string fileName;
    cout << "Enter filename> ";
    getline(cin, fileName);
    f.open(fileName);
    if (f.fail())
    {
        std::cerr << "The file was not found\n";
        std::exit(1);
    }
}
// Destructor
FileDisplay::~FileDisplay()
{
    f.close();
}
// Show first ten lines of file
void FileDisplay::showPreview()
{
    using std::cout;
    using std::endl;
    using std::string;
    string line;
    int counter = 0;
    while (getline(f, line) && counter < 10)
    {
        cout << line << endl;
        counter++;
    }
    if (counter < 9)
    {
        cout << "Entire file displayed\n";
    }
    else
    {
        cout << "Long file - first ten lines displayed\n";
    }
}
int main()
{
    FileDisplay fd;
    fd.showPreview();
    return 0;
}