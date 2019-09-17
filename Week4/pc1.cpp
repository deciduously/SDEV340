/*
* SDEV 340 Week 4 Problem 1
* Display the first 10 lines of a filename given.  If entire file is shown, indicate so
* Benjamin Lovy
*/

#include <fstream>
#include <iostream>
#include <string>

// Class to preview the first several lines of a file
class FileDisplay
{
    // File object
    std::ifstream f;
    // Number of lines included in preview
    static const int linesToShow;

public:
    // Constructor
    FileDisplay();
    // Destructor
    ~FileDisplay();
    // Show first lines of file
    void showPreview();
};

const int FileDisplay::linesToShow = 10;

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
// Show first lines of file
void FileDisplay::showPreview()
{
    using std::cout;
    using std::endl;
    using std::string;
    string line;
    int counter = 0;
    while (getline(f, line))
    {
        cout << line << endl;
        counter++;
        if (counter == linesToShow)
            break;
    }
    if (f.eof())
        cout << "Entire file displayed";
}
int main()
{
    // Instantiate object
    FileDisplay fd;
    // Show file preview
    fd.showPreview();
    // Exit success
    return 0;
}