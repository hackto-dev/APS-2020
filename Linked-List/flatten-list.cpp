#include <bits/stdc++.h>
using namespace std;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define mkp make_pair
#define pi pair<int, int>
#define push push
#define all(v) v.begin(), v.end()
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define clr(a, x) memset(a, x, sizeof(a));
#define rr(v) for (auto &val : v)
#define print(v)             \
    for (const auto itr : v) \
    {                        \
        cout << itr << ' ';  \
    }                        \
    cout << endl;
#define init(v, x)      \
    for (auto &itr : v) \
    {                   \
        itr = x;        \
    }
#define minpq(x) x, vector<x>, greater<x>
#define ln length()
#define sz size()
#define infinity 1e18;
#define elif else if
#define mod 1e9;

struct node
{
    int data;
    struct node *right;
    struct node *down;
};

typedef struct node Node;

void insert(Node **head_ref, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->right = NULL;

    new_node->data = data;
    new_node->down = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->down;
    }

    cout << "NULL" << endl;
}

Node* merge(Node* a,Node* b) {
    if(a == NULL)
        return b;

    if(b == NULL)
        return a;

    Node* result;

    if(a->data < b -> data) {
        result = a;
        result->down = merge(a->down,b);
    } else {
        result = b;
        result->down = merge(a,b->down);
    }

    result->right = NULL;

    return result;
}

Node* flatten(Node* root) {
    if(root == NULL || root->right == NULL) {
        return root;
    }

    return merge(root,flatten(root->right));
}

int32_t main()
{
    fastIO

    Node *root = NULL;

    insert(&root, 30);
    insert(&root, 8);
    insert(&root, 7);
    insert(&root, 5);

    insert(&(root->right), 20);
    insert(&(root->right), 10);

    insert(&(root->right->right), 50);
    insert(&(root->right->right), 22);
    insert(&(root->right->right), 19);

    insert(&(root->right->right->right), 45);
    insert(&(root->right->right->right), 40);
    insert(&(root->right->right->right), 35);
    insert(&(root->right->right->right), 20);

    root = flatten(root);

    printList(root);

    return 0;
}
