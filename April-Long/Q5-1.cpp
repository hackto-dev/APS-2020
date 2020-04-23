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

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,a,b,c;
        cin >> n;

        vector<int> v(n);

        rep(i,0,n)
            cin >> v[i];

        int q, r, p;
        a = -1;
        b = -1;
        c = -1;

        p = (n * (n + 1)) / 2;
        
        int i, j;

        for (i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                b = i;
                break;
            }
        }
        
        if (i == n) {
            cout << (n * (n + 1)) / 2 << endl;
            continue;
        }

        for (j = i + 1; j < n; j++) {
            if (v[j] % 2 == 0) {
                c = j;
                q = min(b - a, c - b);
                r = max(b - a, c - b);
                p -= (q * (q + 1)) / 2;
                p -= (r - q) * q;
                p -= (((c - a - 1) - r) * (c - a - r)) / 2;
                a = b;
                b = c;
            }
        }
        
        c = j;
        q = min(b - a, c - b);
        r = max(b - a, c - b);
        p -= (q * (q + 1)) / 2;
        p -= (r - q) * q;
        p -= (((c - a - 1) - r) * (c - a - r)) / 2;
        cout << p << endl;
    }
    return 0;
}