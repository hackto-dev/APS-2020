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

int32_t main()
{
    fastIO

        int t,
        n;

    cin >> t;

    while (t--)
    {

        cin >> n;

        int a[n], b[n];

        rep(i, 0, n)
        {
            cin >> a[i];
        }

        rep(i, 0, n)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n);

        int sum = 0;
        rep(i, 0, n)
        {
            if (a[i] > b[i])
                sum += b[i];

            else
                sum += a[i];
        }

        cout << sum << endl;
    }

    return 0;
}