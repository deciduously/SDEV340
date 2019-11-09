/*
* SDEV 340 Week 11 Problem 2
* Modified SearchableVector (Gaddis 1012-1013) example performing binary search instead of linear
* Benjamin Lovy
*/
#include <iostream>
#include "SimpleVector.h"

static const int SIZE = 5;

template <class T>
class SearchableVector : public SimpleVector<T>
{
    int binarySearch(int left, int right, T item);

public:
    // Constructor
    SearchableVector(int s) : SimpleVector<T>(s)
    {
    }
    // Copy constructor
    SearchableVector(const SearchableVector &obj);
    // Additional constructor
    SearchableVector(const SimpleVector<T> &obj) : SimpleVector<T>(obj) {}
    int findItem(T);
};

// Copy constructor just passes it through
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) : SimpleVector<T>(obj)
{
}

// Recursive binary search function
template <class T>
int SearchableVector<T>::binarySearch(int left, int right, T item)
{
    try
    {
        // Find midpoint
        int midpoint = left + (right - left) / 2;

        // Did we find it?
        if (this->operator[](midpoint) == item)
            return midpoint;

        // Otherwise, search either the left or the right half
        if (this->operator[](midpoint) > item)
            return binarySearch(left, midpoint - 1, item);
        else
            return binarySearch(midpoint + 1, right, item);
    }
    catch (IndexOutOfRangeException)
    {
        // Not found
        return -1;
    }
}

// findItem uses binary search to locate the item.  `T` must be comparable with >\<, list must be sorted. Returns index if found or -1
template <class T>
int SearchableVector<T>::findItem(T item)
{
    return binarySearch(0, SIZE, item);
}

int main()
{
    using std::cout;
    // Init vectors
    SearchableVector<int> int_vec(SIZE);
    SearchableVector<char> char_vec(SIZE);
    // Populate vectors
    for (int i = 0; i < SIZE; i++)
        int_vec[i] = i;
    for (int i = 0; i < SIZE; i++)
        char_vec[i] = 'a' + i;
    // Demonstrate ints
    cout << "Ints: ";
    int_vec.print();
    cout << "\nIndex of 3: " << int_vec.findItem(3) << "\nIndex of 8: " << int_vec.findItem(8) << "\n\n";
    // Demonstrate chars
    cout << "Chars: ";
    char_vec.print();
    cout << "\nIndex of 'c': " << char_vec.findItem('c') << "\nIndex of 'q': " << char_vec.findItem('q') << "\n";
    // Exit success
    return 0;
}