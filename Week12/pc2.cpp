/*
* SDEV 340 Week 12 Problem 2
* Extension of pc1 SimpleLinkedList class that provdes a method returning the index of a found item, instead of just a boolean
* Benjamin Lovy
*/

// To avoid redefining "main", instead of including SimpleLinkedList
// I just copied the relevant parts of pc1's code into this file, and changed the head pointer to public instead of private
// Ideally, I'd have provided SimpleLinkedList.h separately but that starts needing a makefile

#include <iostream>
#include <string>

template <class T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode(T value, ListNode *nextptr = nullptr)
    {
        val = value;
        next = nextptr;
    }
};

//
// Class declaration
//

template <class T>
class SimpleLinkedList
{
protected:
    ListNode<T> *head;

public:
    SimpleLinkedList();
    void add(T x);
};

// Class methods

template <class T>
SimpleLinkedList<T>::SimpleLinkedList()
{
    head = nullptr;
}

template <class T>
void SimpleLinkedList<T>::add(T x)
{
    head = new ListNode<T>(x, head);
}

//
// Searchable derived class implementation
//

template <class T>
class SearchableLinkedList : public SimpleLinkedList<T>
{
public:
    // Inherits base class constructor
    SearchableLinkedList() : SimpleLinkedList<T>() {}
    // Run search
    int search(T x) const;
    // Display search result
    void showSearch(T x) const;
};

template <class T>
int SearchableLinkedList<T>::search(T x) const
{
    ListNode<T> *currentNodePtr = this->head;
    int ret = -1;
    int idx = 0;
    while (currentNodePtr)
    {
        if (currentNodePtr->val == x)
        {
            ret = idx;
            break;
        }
        currentNodePtr = currentNodePtr->next;
        idx++;
    }
    return ret;
}

template <class T>
void SearchableLinkedList<T>::showSearch(T x) const
{
    std::cout << "Index of " << x << ": " << search(x) << "\n";
}

int main()
{
    using std::cout;
    // Init
    SearchableLinkedList<double> sll;
    // Add numbers 1 through 5
    std::cout << "Adding numbers 1 though 10 (creating [10,9,8,7,6,5,4,3,2,1])...\n";
    for (int i = 1; i <= 10; i++)
        sll.add(i);
    // Search for 7
    sll.showSearch(7);
    // Search for 16
    sll.showSearch(16);
    // Exit success
    return 0;
}