/*
* SDEV 340 Week 8 Problem 1
* An abstract class for comparing sorting algortihms, with a simple sort subclass
* Benjamin Lovy
*/

#include <algorithm>
#include <iostream>

class AbstractSort
{
    // For tracking how many comparisons are performed
    int numCompares = 0;

protected:
    // Compare two elements, incrementing counter.  True if is 'one' is higher, else false
    bool compare(int one, int two);

public:
    // Retrieve total compares performed
    int getCompares() const;
    // Virtual sort() prototype
    virtual void sort(int arr[], int size) = 0;
};

// Compare two elements, incrementing counter.  True if is 'one' is higher, else false
bool AbstractSort::compare(int one, int two)
{
    numCompares++;
    return one > two;
}

// Retrieve total compares performed
int AbstractSort::getCompares() const
{
    return numCompares;
}

class SimpleSort : public AbstractSort
{
public:
    virtual void sort(int arr[], int size)
    {
        // Marker to track completion
        bool finished = true;
        // Iterate through collection, swapping until we're done
        do
        {
            // Assume complete
            finished = true;
            for (int i = 0; i < size - 1; i++)
            {
                // Compare i to i+1
                if (compare(arr[i], arr[i + 1]))
                {
                    // unset marker
                    finished = false;
                    // swap them
                    std::swap(arr[i], arr[i + 1]);
                }
            }
        } while (!finished);
    }
};

// Output an array
template <typename T>
void showArr(T arr[], int size)
{
    using std::cout;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    using std::cout;
    // Init collection
    const int numsLen = 6;
    int nums[numsLen] = {3, 6, 5, 2, 1, 4};
    cout << "Numbers: ";
    showArr(nums, numsLen);
    cout << "\n";
    // Init simple sort object
    SimpleSort ss;
    // Sort collection
    ss.sort(nums, numsLen);
    // Display result
    cout << "Sorted: ";
    showArr(nums, numsLen);
    cout << "\nTotal compares: " << ss.getCompares();
    // Exit success
    return 0;
}