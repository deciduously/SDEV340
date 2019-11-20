#include <iostream>
#include <vector>

template <class T>
class SimpleStack
{
    std::vector<T> contents;

public:
    SimpleStack()
    {
        contents = std::vector<T>();
    }
    bool isEmpty() const
    {
        return top() == 0;
    }
    void push(T item)
    {
        contents.push_back(item);
    }
    void pop(T &item)
    {
        item = contents.back();
        contents.pop_back();
    }
    int top() const
    {
        return contents.size();
    }
};

int main()
{
    SimpleStack<int> ss;
    ss.push(1); // 1
    ss.push(2); // 2 1
    ss.push(3); // 3 2 1
    // Should print 3 2 1
    while (!ss.isEmpty())
    {
        int current;
        ss.pop(current);
        std::cout << current << " ";
    }
    return 0;
}