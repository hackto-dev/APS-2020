#include <iostream>
#include <list>
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

// Iterative function to calculate height of given binary tree
// by doing level order traversal of the tree
int height(Node *root)
{
    // empty tree has height 0
    if (root == nullptr)
        return 0;

    // create an empty queue and enqueue root node
    list<Node *> queue;
    queue.push_back(root);

    Node *front = nullptr;
    int height = 0;

    // do till queue is not empty
    while (!queue.empty())
    {
        // calculate number of nodes in current level
        int size = queue.size();

        // process each node of current level and enqueue their
        // non-empty left and right child to queue
        while (size--)
        {
            front = queue.front();
            queue.pop_front();

            if (front->left)
                queue.push_back(front->left);

            if (front->right)
                queue.push_back(front->right);
        }

        // increment height by 1 for each level
        height++;
    }

    return height;
}

// main function
int main()
{
    Node *root = nullptr;

    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    cout << "The height of the binary tree is " << height(root);

    return 0;
}