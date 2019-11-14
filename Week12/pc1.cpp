/*
* SDEV 340 Week 12 Problem 1
* A class implementing a linked list
* Benjamin Lovy
*/

#include <iostream>

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
    ListNode<T> *head;
    // Helper to pretty-print a boolean
    static std::string showBool(bool b);

public:
    SimpleLinkedList();
    ~SimpleLinkedList();
    void add(T x);
    bool isMember(T x) const;
    // Helper to display isMember result
    void showIsMember(T x) const;
};

// Class methods

// Helper to pretty-print a boolean
template <class T>
std::string SimpleLinkedList<T>::showBool(bool b)
{
    if (b)
        return "true";
    else
        return "false";
}

template <class T>
SimpleLinkedList<T>::SimpleLinkedList()
{
    head = nullptr;
}

template <class T>
SimpleLinkedList<T>::~SimpleLinkedList()
{
    ListNode<T> *currentNodePtr = head;
    while (currentNodePtr)
    {
        ListNode<T> *toDelete = currentNodePtr;
        currentNodePtr = currentNodePtr->next;
        delete toDelete;
    }
}

template <class T>
void SimpleLinkedList<T>::add(T x)
{
    head = new ListNode<T>(x, head);
}

template <class T>
bool SimpleLinkedList<T>::isMember(T x) const
{
    ListNode<T> *currentNodePtr = head;
    while (currentNodePtr)
    {
        if (currentNodePtr->val == x)
            return true;
        currentNodePtr = currentNodePtr->next;
    }
    // End of list with no match
    return false;
}

template <class T>
void SimpleLinkedList<T>::showIsMember(T x) const
{
    using std::cout;
    cout << "Is " << x << " a member? " << showBool(isMember(x)) << "\n";
}

int main()
{
    //init list
    SimpleLinkedList<double> sll;
    // Populate
    std::cout << "Adding 3 and 5 to the list...\n";
    sll.add(3);
    sll.add(5);
    // Demonstrate
    sll.showIsMember(3);
    sll.showIsMember(4);
    sll.showIsMember(5);
    // Exit success
    return 0;
}
