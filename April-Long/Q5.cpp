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

int lol(int n) {
    if((n-2)%4 == 0)
        return 0;

    return 1;
}

int32_t main()
{
    fastIO

    int t;
    cin >> t;

    while(t--) {
        int n, i, j, p, q, count = 0;
        set<int> s;
        cin >> n;
        
        vector<int> a(n + 5);
        
        rep(i, 0, n) {
            cin >> a[i];
            s.insert(a[i]);
        }

        int diff = 2;

        while (diff <= n) {
            int i, j, k, l;
            int prod = 1;
            for (i = 0; i < diff; i++)
                prod = prod * a[i];

            k = i - 1;
            s.insert(prod);
            
            for (j = k, l = 0; j < n - 1; j++, l++)
            {
                prod = prod * a[j + 1];
                prod = prod / a[l];
                s.insert(prod);
            }

            diff++;
        }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            count += lol(*it);
        }
        cout << count << endl;
    }

    return 0;
}
