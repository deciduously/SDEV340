/*
* SDEV 340 Week 11 Problem 1
* Write a generic accumulation function that can add numbers or concatenate strings, anything with a + overload
* Benjamin Lovy
*/

#include <iostream>
#include <string>
#include <vector>

template <class T>
T accum(std::vector<T> v)
{
    T ret = T();
    for (auto el : v)
        ret += el;
    return ret;
}

// Prompt for a valid value
template <class T>
void prompt(std::vector<T> &coll, std::string message)
{
    using std::cin;
    using std::cout;
    T buf;
    do
    {
        cout << message << "> ";
        cin >> buf;
    } while (!cin);
    coll.push_back(buf);
}

int main()
{
    using std::cout;
    using std::string;
    using std::vector;

    // Init vectors
    vector<int> int_vec;
    vector<string> str_vec;
    // Number of elements to prompt for
    size_t vec_size = 3;

    // Fill int vec
    for (int i = 1; i <= vec_size; i++)
    {
        string message = "Enter integer #";
        message.push_back('0' + i);
        prompt(int_vec, message);
    }

    // Display result
    cout << "\nAccumulated: " << accum(int_vec) << "\n";

    // Fill string vec
    for (int i = 1; i <= vec_size; i++)
    {
        string message = "Enter string #";
        message.push_back('0' + i);
        prompt(str_vec, message);
    }

    // Display result
    cout << "\nAccumulated: " << accum(str_vec) << "\n";

    // Exit success
    return 0;
}