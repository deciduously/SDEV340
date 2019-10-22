/*
* SDEV 340 Week 9 Problem 1
* An abstract class for representing a sequence, with two concrete subclass implementations to demonstrate
* Benjamin Lovy
*/

#include <iostream>

class AbstractSeq
{
public:
    // Return the kth value of the seq
    virtual int fun(int k) const = 0;
    // Print the sequence from k to m
    void printSeq(int k, int m) const;
    // Return the sum of the sequence from k to m
    int sumSeq(int k, int m) const;
    // Display the results of both printSeq and sumSeq
    void showSeq(int k, int m) const;
};

// Print the sequence from k to m
void AbstractSeq::printSeq(int k, int m) const
{
    using std::cout;
    // Ensure k < m
    if (k >= m)
    {
        std::cerr << "Error: did not meet constraint k < m\n";
        std::exit(1);
    }

    for (int i = k; i <= m; i++)
    {
        cout << fun(i);
        if (i < m)
            cout << ", ";
    }
}

// Return the sum of the sequence from k to m
int AbstractSeq::sumSeq(int k, int m) const
{

    // Ensure k < m
    if (k >= m)
    {
        std::cerr << "Error: did not meet constraint k < m\n";
        std::exit(1);
    }

    int sum = 0;
    for (int i = k; i <= m; i++)
    {
        sum += fun(i);
    }
    return sum;
}

// Display the results of both printSeq and sumSeq
void AbstractSeq::showSeq(int k, int m) const
{
    using std::cout;
    cout << "Sequence: ";
    printSeq(k, m);
    cout << "\nSum of sequence: " << sumSeq(k, m) << ".\n";
}

// Implement the odds
class OddSeq : public AbstractSeq
{
    virtual int fun(int k) const
    {
        return 2 * k + 1;
    }
};

// Implement the cubes
class CubeSeq : public AbstractSeq
{
    virtual int fun(int k) const
    {
        return k * k * k + 1;
    }
};

// Implement the Fibonacci seq
class FibonacciSeq : public AbstractSeq
{
    virtual int fun(int k) const
    {
        if (k == 0)
            return 1;
        else if (k == 1)
            return 1;
        else
            return (fun(k - 1) + fun(k - 2));
    }
};

int main()
{
    using std::cout;
    // Init upper and lower demo bounds
    int k = 0;
    int m = 15;
    cout << "k: " << k << "\nm: " << m << "\n";
    // init sequence objects
    OddSeq os;
    CubeSeq cs;
    FibonacciSeq fs;
    // Dislay results
    cout << "\nOdds:\n";
    os.showSeq(k, m);
    cout << "\nCubes:\n";
    cs.showSeq(k, m);
    cout << "\nFibonacci:\n";
    fs.showSeq(k, m);
    // Exit success
    return 0;
}