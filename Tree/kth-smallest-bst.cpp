#include <iostream>
#include <climits>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// Function to perform in-order traversal of the tree
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive function to insert a key into BST
Node *insert(Node *root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr)
        return newNode(key);

    // if given key is less than the root node, recur for left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // if given key is more than the root node, recur for right subtree
    else
        root->right = insert(root->right, key);

    return root;
}

// Function to find k'th smallest element in BST
// Here i denotes the number of nodes processed so far
int kthSmallest(Node *root, int *i, int k)
{
    // base case
    if (root == nullptr)
        return INT_MAX;

    // search in left subtree
    int left = kthSmallest(root->left, i, k);

    // if k'th smallest is found in left subtree, return it
    if (left != INT_MAX)
        return left;

    // if current element is k'th smallest, return its value
    if (++*i == k)
        return root->data;

    // else search in right subtree
    return kthSmallest(root->right, i, k);
}

// Function to find k'th smallest element in BST
int kthSmallest(Node *root, int k)
{
    // maintain index to count number of nodes processed so far
    int i = 0;

    // traverse the tree in in-order fashion and return k'th element
    return kthSmallest(root, &i, k);
}

// main function
int main()
{
    Node *root = nullptr;
    int keys[] = {15, 10, 20, 8, 12, 16, 25};

    for (int key : keys)
        root = insert(root, key);

    int k = 2;
    int res = kthSmallest(root, k);

    if (res != INT_MAX)
        cout << res;
    else
        cout << "Invalid Input";

    return 0;
}