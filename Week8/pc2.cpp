/*
* SDEV 340 Week 8 Problem 2
* An abstract class for comparing sorting algortihms, with a QuickSort subclass
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

// This implementaiton largely co-opted from my Week 6 discussion post solution
class QuickSort : public AbstractSort
{
    int partition(int arr[], int lowIdx, int highIdx)
    {
        using std::swap;
        // Select highest element
        int pivot = arr[highIdx];
        // Index of smaller element
        int i = lowIdx - 1;
        // Traverse
        for (int j = lowIdx; j <= highIdx - 1; j++)
        {
            // check against pivot
            if (compare(pivot, arr[j]))
            {
                // increment smaller idx
                i++;
                // swap i and j
                swap(arr[i], arr[j]);
            }
        }
        int ret = i + 1;
        swap(arr[ret], arr[highIdx]);
        return ret;
    }
    void quicksort(int arr[], int lowIdx, int highIdx)
    {
        if (lowIdx < highIdx)
        {
            int partitionIdx = partition(arr, lowIdx, highIdx);
            quicksort(arr, lowIdx, partitionIdx - 1);
            quicksort(arr, partitionIdx + 1, highIdx);
        }
    }

public:
    virtual void sort(int arr[], int size)
    {
        quicksort(arr, 0, size - 1);
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
    QuickSort qs;
    // Sort collection
    qs.sort(nums, numsLen);
    // Display result
    cout << "Sorted: ";
    showArr(nums, numsLen);
    cout << "\nTotal compares: " << qs.getCompares();
    // Exit success
    return 0;
}