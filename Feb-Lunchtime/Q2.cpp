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
#define ump unordered_map<int, int>
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

void addEdge(vector<pi> adj[], int u, int v, int wt)
{
    adj[u].pub(mkp(v, wt));
    adj[v].pub(mkp(u, wt));
}

int32_t main()
{
    fastIO

        int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n >> k;

        vector<int> a(n);

        rep(i, 0, n)
                cin >>
            a[i];

        ump hash;

        int l = 0, r = 0, current, max_len = INT_MIN;

        while (r < n)
        {
            ++hash[a[r]];

            while (hash.sz >= k)
            {
                --hash[a[l]];

                if (hash[a[l]] == 0)
                    hash.erase(a[l]);

                ++l;
            }

            current = r - l + 1;
            max_len = max(max_len, current);
            ++r;
        }

        cout << max_len << endl;
    }

    return 0;
}