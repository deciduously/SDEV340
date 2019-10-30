/*
* SDEV 340 Week 10 Problem 2
* Implementations of min and max template functions
* Benjamin Lovy
*/

#include <iostream>

// If x is smaller or equal, return x, else y
template <class T>
T min(T x, T y)
{
    if (x <= y)
        return x;
    else
        return y;
}

// If x is larger or equal, return x, else y
template <class T>
T max(T x, T y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    using std::cout;
    // Instantiate test values
    int intX = 2;
    int intY = 5;
    double doubleX = 2.3;
    double doubleY = 6.7;
    float floatX = 1.8;
    float floatY = 10.8;
    // Display
    cout << "Integers\nx: " << intX << " | y: " << intY << " | min: " << min(intX, intY) << " | max: " << max(intX, intY) << std::endl;
    cout << "Doubles\nx: " << doubleX << " | y: " << doubleY << " | min: " << min(doubleX, doubleY) << " | max: " << max(doubleX, doubleY) << std::endl;
    cout << "Floats\nx: " << floatX << " | y: " << floatY << " | min: " << min(floatX, floatY) << " | max: " << max(floatX, floatY) << std::endl;
    // Exit success
    return 0;
}