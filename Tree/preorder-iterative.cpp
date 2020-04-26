#include <bits/stdc++.h>
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

// Iterative function to perform pre-order traversal of the tree
void preorderIterative(Node *root)
{
    // return if tree is empty
    if (root == nullptr)
        return;

    // create an empty stack and push root node
    stack<Node *> stack;
    stack.push(root);

    // run till stack is not empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node *curr = stack.top();
        stack.pop();

        cout << curr->data << " ";

        // push right child of popped node to the stack
        if (curr->right)
            stack.push(curr->right);

        // push left child of popped node to the stack
        if (curr->left)
            stack.push(curr->left);

        // important note - right child is pushed first so that left child
        // is processed first (FIFO order)
    }
}