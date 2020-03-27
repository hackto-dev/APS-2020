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

int block;

bool compare(pi x,pi y) {
    if(x.fi/block != y.fi/block)
        return x.fi/block < y.fi/block;

    return x.se < y.se;
}

int query(int a[],int n,vector<pi> v,int m) {
    block = (int)sqrt(n);

    sort(v.begin(),v.begin()+m,compare);

    int current_left = 0,current_right = 0;
    int current_sum = 0;

    rep(i,0,m) {
        int L = v[i].fi,R = v[i].se;

        while(current_left < L) {
            current_sum -= a[current_left];
            current_left += 1;
        }

        while(current_left > L) {
            current_sum += a[current_left - 1];
            current_left -= 1;
        } 

        while(current_right <= R) {
            current_sum += a[current_right];
            current_right += 1;
        }

        while(current_right >= R + 1) {
            current_sum -= a[current_right - 1];
            current_right -= 1;
        }
    }

    return current_sum;
}

int32_t main()
{
    fastIO

    int n,m,a,b;

    cin >> n >> m;

    int arr[n];

    rep(i,0,n)
        cin >> arr[i];

    vector<pi> q(m);

    rep(i,0,m) {
        cin >> a >> b;
        q.pub(mkp(a,b));
    }

    cout << query(arr,n,q,m) << endl;

    return 0;
}
