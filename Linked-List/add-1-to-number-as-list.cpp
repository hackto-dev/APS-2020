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

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int addWithCarry(Node *head)
{
    if (head == NULL)
        return 1;

    int res = head->data + addWithCarry(head->next);
    head->data = (res) % 10;
    return (res) / 10;
}

Node *addOne(Node *head)
{
    int carry = addWithCarry(head);

    if (carry)
    {
        Node *newNode = new Node;
        newNode->data = carry;
        newNode->next = head;
        return newNode; 
    }

    return head;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

int32_t main()
{
    fastIO

    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);

    printf("List is ");
    printList(head);

    head = addOne(head);

    printf("\nResultant list is ");
    printList(head);

    return 0;
}
