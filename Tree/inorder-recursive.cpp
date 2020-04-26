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

// Recursive function to perform in-order traversal of the tree
void inorder(Node *root)
{
    // return if the current node is empty
    if (root == nullptr)
        return;

    // Traverse the left subtree
    inorder(root->left);

    // Display the data part of the root (or current node)
    cout << root->data << " ";

    // Traverse the right subtree
    inorder(root->right);
}