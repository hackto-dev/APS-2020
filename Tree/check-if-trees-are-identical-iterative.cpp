#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Iterative function to check if two given binary trees are identical or not
bool isIdentical(Node *x, Node *y)
{
    // if both trees are empty, return true
    if (x == nullptr && y == nullptr)
        return true;

    // if first tree is empty (& second tree is non-empty), return false
    if (x == nullptr)
        return false;

    // if second tree is empty (& first tree is non-empty), return false
    if (y == nullptr)
        return false;

    // create a stack to hold Node* pairs
    stack<pair<Node *, Node *>> stack;
    stack.push({x, y});

    // do till stack is not empty
    while (!stack.empty())
    {
        // pop top pair from the stack and process it
        Node *x = stack.top().first;
        Node *y = stack.top().second;
        stack.pop();

        // if value of their root node don't match, return false
        if (x->key != y->key)
            return false;

        // if left subtree of both x and y exists, push their addresses
        // to stack else return false if only one left child exists
        if (x->left && y->left)
            stack.push({x->left, y->left});
        else if (x->left || y->left)
            return false;

        // if right subtree of both x and y exists, push their addresses
        // to stack else return false if only one right child exists
        if (x->right && y->right)
            stack.push({x->right, y->right});
        else if (x->right || y->right)
            return false;
    }

    // if we reach here, both binary trees are identical
    return true;
}

// main function
int main()
{
    // construct first tree
    Node *x = nullptr;

    x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);

    // construct second tree
    Node *y = nullptr;

    y = new Node(15);
    y->left = new Node(10);
    y->right = new Node(20);
    y->left->left = new Node(8);
    y->left->right = new Node(12);
    y->right->left = new Node(16);
    y->right->right = new Node(25);

    if (isIdentical(x, y))
        cout << "Given binary Trees are identical";
    else
        cout << "Given binary Trees are not identical";

    return 0;
}