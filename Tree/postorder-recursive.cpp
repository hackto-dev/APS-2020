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

// Recursive function to perform post-order traversal of the tree
void postorder(Node *root)
{
    // if the current node is empty
    if (root == nullptr)
        return;

    // Traverse the left subtree
    postorder(root->left);

    // Traverse the right subtree
    postorder(root->right);

    // Display the data part of the root (or current node)
    cout << root->data << " ";
}