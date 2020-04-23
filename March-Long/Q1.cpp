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
    fastIO

        int t,
        n, m, ma, ans;
    cin >> t;
    int a[10000], b[10000];
    while (t--)
    {
        cin >> n >> m;
        map<int, int> m1;
        rep(i, 0, n)
        {
            //  cout<<"iske ansar\n";
            cin >> a[i];
        }
        rep(i, 0, n)
        {

            cin >> b[i];
            m1[a[i]] += b[i];
            // 			cout<<m1[a[i]]<<endl;
        }
        ma = infinity;

        rr(m1)
        {
            //  cout<<val.fi<< " "<<val.se<<endl;
            if (val.se < ma)
            {
                ma = val.se;
                ans = val.fi;
            }
        }
        cout << ma << endl;
    }

    return 0;
}
