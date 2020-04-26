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

unsigned int t,n,m;

int a[100005];

int32_t main()
{
    fastIO
    cin >> t;

    while(t--) {
        int count = 0,sum = 0;

        cin >> n >> m;

        rep(i,1,m+1) {
            cin >> a[i];
            count += a[i];
        }

        if(count < n) {
            cout << -1 << endl;
            continue;
        }

        sort(a+1,a+m+1);

        while(m) {
            if(a[m] <= n) {
                n -= a[m];
                count -= a[m];
                m -= 1;
                continue;
            }

            if(count - a[m] < n) {
                a[m] /= 2;
                a[m+1] = a[m];
                m += 1;
                sum += 1;
                continue;
            }

            count -= a[m];
            m -= 1;
        }

        cout << sum << endl;
    }

    return 0;
}
