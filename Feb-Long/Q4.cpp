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
        n, p, flag;

    cin >> t;

    while (t--)
    {

        cin >> n >> p;

        int d[n];
        int ans[n];

        clr(ans, 0)

            rep(i, 0, n)
        {
            cin >> d[i];
        }

        flag = 0;

        rep(i, 0, n)
        {
            if (p % d[i] != 0)
            {
                ans[i] = p / d[i] + 1;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            for (int i = 0; i < n - 1; i++)
            {

                if (d[i + 1] % d[i] != 0)
                {
                    flag = 1;
                    ans[i + 1] = p / d[i + 1] - 1;

                    ans[i] = d[i + 1] / d[i] + 1;
                    break;
                }
            }
        }

        if (flag == 0)
            cout << "NO" << endl;

        else
        {
            cout << "YES ";
            rep(i, 0, n)
                    cout
                << ans[i] << " ";
            cout << endl;
        }
    }

    return 0;
}