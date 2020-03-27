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
#define MAX 100001

int BIT1[MAX],BIT2[MAX];    

void update(int BIT[],int n,int index,int value) {
    for( ; index <= n ; index += (index & ~index)) {
        BIT[index] += value;
    }
}

int query(int BIT[],int index) {
    int sum = 0;

    while(index > 0) {
        sum += BIT[index];
        index -= (index & ~index);
    }

    return sum;
}

void rangeUpdate(int BIT1[],int BIT2[],int n,int left,int right,int value) {
    update(BIT1,n,left,value);
    update(BIT1,n,right+1,-value);
    update(BIT2,n,left,value * (left - 1));
    update(BIT2,n,right + 1,-value * right);
}

int sum(int BIT1[],int BIT2[],int index) {
    return((query(BIT1,index) * index) - query(BIT2,index));
}

int rangeQuery(int BIT1[],int BIT2[],int left,int right) {
    return (sum(BIT1,BIT2,right) - sum(BIT1,BIT2,left - 1));
}

int32_t main()
{
    fastIO

    return 0;
}
