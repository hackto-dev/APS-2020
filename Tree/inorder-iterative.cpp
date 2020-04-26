#include<bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int key)
    {
        this->data = key;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform in-order traversal of the tree
void inorderIterative(Node *root)
{
    // create an empty stack
    stack<Node *> stack;

    // start from root node (set current node to root node)
    Node *curr = root;

    // if current node is null and stack is also empty, we're done
    while (!stack.empty() || curr != nullptr)
    {
        // if current node is not null, push it to the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            // else if current node is null, we pop an element from stack,
            // print it and finally set current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}