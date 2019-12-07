/*
* SDEV 340 Week 14 Problem 1
* Implement a simple binary search tree
* December 7, 2019
* Benjamin Lovy
*/

#include <iostream>
#include <vector>

template <class T> // T must be numeric: int, double, etc, or have `<` and `==` overloaded
struct BTNode
{
    T val;
    BTNode *left;
    BTNode *right;
    BTNode(T, BTNode * = nullptr, BTNode * = nullptr);
};

template <class T>
BTNode<T>::BTNode(T value, BTNode *lptr, BTNode *rptr)
{
    val = value;
    left = lptr;
    right = rptr;
}

template <class T>
class SimpleBST {
    BTNode<T> *tree;
    static void destroySubTree(BTNode<T> *&);
    static void inorder(BTNode<T> *&, std::vector<T> &);
    static void insert(BTNode<T> *&, T);
    static bool search(T, BTNode<T> *&);
public:
    SimpleBST();
    ~SimpleBST();
    void insert(T);
    bool search(T);
    void inorder(std::vector<T> &);
};

template <class T>
SimpleBST<T>::SimpleBST()
{
    tree = nullptr;
}

template <class T>
SimpleBST<T>::~SimpleBST()
{
    destroySubTree(tree);
}

template <class T>
void SimpleBST<T>::destroySubTree(BTNode<T> *&tree)
{
    if (tree)
    {
        destroySubTree(tree->left);
        destroySubTree(tree->right);
        delete tree;
    }
}

template <class T>
void SimpleBST<T>::insert(T x)
{
    insert(tree, x);
}

template <class T>
bool SimpleBST<T>::search(T val)
{
    return search(val, tree);
}

template <class T>
void SimpleBST<T>::inorder(std::vector<T> &v)
{
    inorder(tree, v);
}

template <class T>
void SimpleBST<T>::inorder(BTNode<T> *&tree, std::vector<T> &v)
{
    if (!tree)
        return;
    inorder(tree->left, v);
    v.push_back(tree->val);
    inorder(tree->right, v);
}

template <class T>
void SimpleBST<T>::insert(BTNode<T> *&tree, T x)
{
    if (!tree)
    {
        tree = new BTNode<T>(x);
        return;
    }

    BTNode<T> *t = tree;
    while (t)
    {
        if (t->val == x)
            return; // it's already here
        else if (x < t->val)
        {
            if (t->left)
                t = t->left;
            else
            {
                t->left = new BTNode<T>(x);
                return;
            }
        }
        else
        {
            if (t->right)
                t = t->right;
            else
            {
                t->right = new BTNode<T>(x);
                return;
            }
        }
    }
}

template <class T>
bool SimpleBST<T>::search(T value, BTNode<T> *&tree)
{

    if (tree)
    {
        if (tree->val == value) // equal within tolerance
            return true;
        else if (value < tree->val)
            return search(value, tree->left);
        else
            return search(value, tree->right);
    }
    return false; // no tree - definitely no value match
}

// Pretty print overload
template <class T>
std::ostream &operator<<(std::ostream &s, SimpleBST<T> &Bst)
{
    using std::cout;
    using std::string;
    using std::vector;

    // Get contents in order
    vector<double> ordered_nums;
    Bst.inorder(ordered_nums);

    // Build string
    char ret [500];
    int cursor = 0;
    ret[cursor] = '[';
    cursor++;
    ret[cursor] = ' ';
    cursor++;

    for (auto n : ordered_nums)
        cursor += sprintf(ret + cursor, "%.3f ", n);

    ret[cursor] = ']';
    cursor++;
    ret[cursor] = '\0';

    return s << ret;
}

int main() {
    using std::cout;

    // Init tree
    SimpleBST<double> Bst;

    // Store some numbers, including a duplicate.
    double numbers [] = {303.4, 7.7, 9.23, 2.0, 5.45, 3.3, 45.0, 234.34, 67.4656, 28.9, 3.3, 27.5, 3.352938};
    for (auto n : numbers)
    {
        cout << "Inserting " << n << "\n";
        Bst.insert(n);
    }

    // Demonstrate search()
    cout << "Is 45.0 in the list? " << Bst.search(45.0) << "\n";
    cout << "Is 45.1 in the list? " << Bst.search(45.1) << "\n";

    // Demonstrate inorder()
    cout << "All in order: " << Bst << "\n";

    // Exit success
    return 0;
}