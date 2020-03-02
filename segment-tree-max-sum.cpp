#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define mkp make_pair
#define pi pair<int,int>
#define push push
#define all(v) v.begin(),v.end()
#define rep(i,l,r) for(int i = (int)(l) ; i < (int)(r) ; i++)
#define clr(a,x) memset(a,x,sizeof(a));
#define rr(v) for(auto &val:v)
#define print(v) for(const auto itr:v){ cout << itr << ' ';} cout << endl;
#define init(v,x) for(auto &itr:v){ itr = x; }
#define minpq(x) x,vector<x>,greater<x>
#define ln length()
#define sz size()
#define infinity 1e18;
#define elif else if
#define mod 1e9;

const int N = 1e5;
int n;
int t[2*N];

void build() {
    for(int i = n - 1 ; i > 0 ; i--)    t[i] = t[i << 1] + t[i << 1 | 1];
}

void update(int p,int value) {
    for(t[p += n] = value ; p > 1 ; p >>= 1)   t[p >> 1] = t[p] + t[p^1];
}

int query(int l,int r) {
    int res = 0;

    for(l += n,r += n ; l < r ; l >>= 1,r >>= 1) {
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }

    return res;
}

int32_t main(){
    fastIO

    cin >> n;

    for(int i = 0 ; i < n ; i++)    scanf("%lld",t+n+i);

    build();

    update(0,1);

    cout << query(3,11) << endl;

    return 0;
}
