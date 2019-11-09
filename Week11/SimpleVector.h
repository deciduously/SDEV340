// Gaddis 1009-1010
#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

// Exception for index out of range
struct IndexOutOfRangeException
{
    const int index;
    IndexOutOfRangeException(int ix) : index(ix) {}
};

template <class T>
class SimpleVector
{
    unique_ptr<T[]> aptr;
    int arraySize;

public:
    SimpleVector(int);
    SimpleVector(const SimpleVector &);
    int size() const { return arraySize; }
    T &operator[](int); // Overloaded[] operator
    void print() const; // Outputs the array elements
};

// Constructor
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    aptr = make_unique<T[]>(s);
    for (int count = 0; count < arraySize; count++)
        aptr[count] = T();
}

// Copy constructor
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    aptr = make_unique<T[]>(arraySize);
    for (int count = 0; count < arraySize; count++)
        aptr[count] = obj[count];
}

// Overloaded []
template <class T>
T &SimpleVector<T>::operator[](int sub)
{
    if (sub < 0 || sub >= arraySize)
        throw IndexOutOfRangeException(sub);
    return aptr[sub];
}

// Print all entries
template <class T>
void SimpleVector<T>::print() const
{
    for (int k = 0; k < arraySize; k++)
        cout << aptr[k] << "  ";
    cout << endl;
}
