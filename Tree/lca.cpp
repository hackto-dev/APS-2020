#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to check if given node is present in binary tree or not
bool isNodePresent(Node *root, Node *node)
{
    // base case
    if (root == nullptr)
        return false;

    // if node is found, return true
    if (root == node)
        return true;

    // return true if node is found in the left subtree or right subtree
    return isNodePresent(root->left, node) ||
           isNodePresent(root->right, node);
}

// Function to find lowest common ancestor of given nodes x and y where
// both x and y are present in the binary tree.
// The function returns true if x or y is found in subtree rooted at root
// lca -> stores LCA(x, y) and it is passed by reference to the function
bool findLCA(Node *root, Node *&lca, Node *x, Node *y)
{
    // base case 1: return false if tree is empty
    if (root == nullptr)
        return false;

    // base case 2: return true if either x or y is found
    if (root == x || root == y)
    {
        // set lca to current node
        lca = root;
        return true;
    }

    // recursively check if x or y exists in the left subtree
    bool left = findLCA(root->left, lca, x, y);

    // recursively check if x or y exists in the right subtree
    bool right = findLCA(root->right, lca, x, y);

    // if x is found in one subtree and y is found in other subtree,
    // update lca to current node
    if (left && right)
        lca = root;

    // return true if x or y is found in either left or right subtree
    return left || right;
}

// Function to find lowest common ancestor of nodes x and y
void findLCA(Node *root, Node *x, Node *y)
{
    // lca stores lowest common ancestor
    Node *lca = nullptr;

    // call LCA procedure only if both x and y are present in the tree
    if (isNodePresent(root, y) && isNodePresent(root, x))
        findLCA(root, lca, x, y);

    // if LCA exists, print it
    if (lca != nullptr)
        cout << "LCA is " << lca->data << endl;
    else
        cout << "LCA do not exist\n";
}

// main function
int main()
{
    Node *root = nullptr;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           / \
          7   8
    */

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right->right = new Node(8);

    findLCA(root, root->right->left->left, root->right->right);
    findLCA(root, root->right->left->left, new Node(10));
    findLCA(root, root->right->left->left, root->right->left->left);
    findLCA(root, root->right->left->left, root->right->left);
    findLCA(root, root->left, root->right->left);

    return 0;
}