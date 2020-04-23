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

bool getFactors(int n,int k) {
    vector<int> v;

    while(n%2 == 0) {
        v.pub(2);
        n /= 2;
    }

    for(int i = 3 ; i <= sqrt(n) ; i += 2) {
        while(n%i == 0) {
            n /= i;
            v.pub(i);
        }
    }

    if(n > 2) {
        v.pub(n);
    }

    if(v.sz < k) { 
        //cout << "NO" << endl;
        return 0;
    }

    return 1;
}

int32_t main()
{
    fastIO

    int t;
    cin >> t;

    while(t--) {
        int x,k;

        cin >> x >> k;

        if(getFactors(x,k))
            cout << "1" << endl;

        else
            cout << "0" << endl;
    }

    return 0;
}
