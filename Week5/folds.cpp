// Week 5 Group Discussion example code

#include <iostream>
#include <vector>

namespace BenFolds
{
// fold - Fold a binary operation over a vector
template <typename T, typename BinOp>
T fold(std::vector<T> elems, T acc, BinOp func);
// Or - True if any element is true, else False
bool foldOr(std::vector<bool> bools);
// Any - True if any element satisfies predicate, else false
template <typename T, typename R, typename Predicate>
bool foldAny(std::vector<T> elems, Predicate p);
// Elem - True if element found in elements, else false
template <typename T>
bool foldElem(std::vector<T> elems, T elem);
// Map - Result of performing func() on each elem in elems
template <typename T, typename R, typename Op>
R foldMap(std::vector<T> elems, Op func);
}; // namespace BenFolds

// Fold a binary operation over a vector
template <typename T, typename R, typename BinOp>
R BenFolds::fold(std::vector<T> elems, T acc, BinOp func)
{
    int length = elems.size();
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
        int newAcc = func(acc, elems[0]);
        // Create a new input from the second element onward of the current input
        std::vector<T> newInput(elems.begin() + 1, elems.end());
        // Recur with rest of list and new accumulator
        return fold(newInput, newAcc, func);
    }
}

// Or
bool BenFolds::foldOr(std::vector<bool> bools)
{
    return fold(bools, false, [](bool acc, bool curr) { return acc || curr; });
}

// Any
template <typename T, typename R, typename Predicate>
bool BenFolds::foldAny(std::vector<T> elems, Predicate p)
{
    return fold(elems, false, [p](bool acc, T curr) { return acc || p(curr); });
}
// Elem
template <typename T>
bool BenFolds::foldElem(std::vector<T> elems, T elem)
{
    return foldAny(elems, [elem](bool acc, T curr) { return acc || elem == curr; });
}

// Map
template <typename T, typename R, typename Op>
R BenFolds::foldMap(std::vector<T> elems, Op func)
{
    return fold(elems, std::vector<R>(), [func](std::vector<R> acc, T curr) { return acc.push_back(func(curr)); });
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
    // Folds object
    vector<int> nums;
    for (int i = 0; i < 5; i++)
    {
        nums.push_back(i);
    }
    int acc = 0;
    cout << "Summing...\n";
    int result = BenFolds::fold(nums, acc, [](int acc, int curr) { return acc + curr; });
    cout << "Result: " << result;
    // Throwaway to ensure foldOr works
    vector<bool> bools = {false, false, false, true, false};
    cout << "This should be true: " << BenFolds::foldOr(bools) << "\n";
    // Check for any even elements - should be true
    //cout << "Are there even elements in the set: " << BenFolds::foldAny(nums, [](int n) { return n % 2 == 0; }) << "\n";
    // Check if the number '2' is in the set - should be true
    //cout << "Is the number 2 present in the set: " << BenFolds::foldElem(nums, 2) << "\n";
    // Double each number in the set
    //cout << "Here's each element doubled: " << BenFolds::foldMap(nums, [](int elem) { return elem * 2; }) << "\n";
    return 0;
}