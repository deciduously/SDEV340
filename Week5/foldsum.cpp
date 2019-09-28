// Week 5 Group Discussion example code

#include <functional>
#include <iostream>
#include <vector>

// Highest number that we can sum a vector of 0..n-1 of without a core dump
static const unsigned int MAX = 43642;

// Fold a binary operation over a vector of ints
int fold(std::vector<int> nums, int acc, std::function<int(int, int)> func)
{
    int length = nums.size();
    if (length == 0)
    {
        // base case - empty list
        // Sub-problem is trivial - we're already done.  The passed accumulator holds the result
        return acc;
    }
    else
    {
        // Calculation is not complete - sub-problem is also trivial
        // Call function on accumulator using first element in vector as operand
        int newAcc = func(acc, nums[0]);
        // Create a new input from the second element onward of the current input
        std::vector<int> newInput(nums.begin() + 1, nums.end());
        // Recur with rest of list and new accumulator
        return fold(newInput, newAcc, func);
    }
}

// Pretty-print a vector
template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> vec)
{
    stream << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        stream << vec[i];
        if (i < vec.size() - 1)
        {
            stream << ", ";
        }
    }
    stream << "]";
    return stream;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::vector;
    vector<int> nums;
    for (int i = 0; i < MAX; i++)
    {
        nums.push_back(i);
    }
    int acc = 0;
    cout << "Summing...\n";
    int result = fold(nums, acc, [](int acc, int curr) { return acc + curr; });
    cout << "Result: " << result;
    return 0;
}