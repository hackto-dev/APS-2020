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

const int k = 16;
const int N = 1e5;

int table[N][k+1];
int arr[N];

void build(int n) {
    rep(i,0,n) {
        table[i][0] = arr[i];
    }

    rep(j,1,k+1) {
        rep(i,0,(n - (1 << j))+1) {
            table[i][j] = table[i][j-1] + table[i + (1 << (j - 1))][j-1];
        }
    }
}

int rangeSumQuery(int L,int R) {
    int sum = 0;

    for(int j = k ; j >= 0 ; j--) {
        if(L + (1 << j) - 1 <= R) {
            sum += table[L][j];
            L += (1 << j);
        }
    }

    return sum;
}

int32_t main()
{
    fastIO

    int n,L,R,q;

    cin >> n;

    rep(i,0,n)
        cin >> arr[i];

    build(n);

    cin >> q;

    rep(i,0,q) {
        cin >> L >> R;

        cout << rangeSumQuery(L,R) << endl;
    }

    return 0;
}
