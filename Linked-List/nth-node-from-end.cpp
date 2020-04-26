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
    Node *next;
};

typedef struct node Node;

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int getNthFromLast(Node *head, int n)
{
    // Your code here
    int i = 1;
    Node *ans = NULL, *th = head;
    while (th != NULL)
    { // Traverse th throught the linked list
        if (i < n)
            i++; // While i is less than n increase it
        else if (i == n)
        {
            i++;
            ans = head;
        } // After i reaches 'n' set ans as head
        else
            ans = ans->next; // After that keep on increasing ans till th reaches end.
        th = th->next;
    }
    if (ans != NULL)
        return (ans->data);
    return (-1);
}