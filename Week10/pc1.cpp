/*
* SDEV 340 Week 10 Problem 1
* A function that returns a square root, throws if parameter is not a perfect square
* Benjamin Lovy
*/

#include <cmath>
#include <iostream>

class SafeSqrt
{
        // Return the square root of this number
    double getSqrt(int x)
    {
        double ret = sqrt(x);
        if (abs(ret) != ret)
            throw NotPerfectSquare(x);
        else
            return sqrt(x);
    }
public:
    // Exception thrown if param passed is not a perfect square
    class NotPerfectSquare
    {
        public:
        int val;
        NotPerfectSquare(int x)
        {
            val = x;
        }
    };
    // Try a number
    void trySqrt(int x)
    {
        std::cout << "Trying " << x << "...\n";
        double result = 0.0;
        try
        {
            result = getSqrt(x);
        }
        catch (NotPerfectSquare ex)
        {
            std::cerr << "Caught NotPerfectSquare exception - " << ex.val << " is not a perfect square.\n";
            return;
        }
        std::cout << "Result: " << result << std::endl;
    }
};

int main()
{
    // Instantiate object
    SafeSqrt ss;
    // Attempt with a perfect square
    ss.trySqrt(9);
    // Attempt with a non-perfect square
    ss.trySqrt(8);
    // Exit success
    return 0;
}