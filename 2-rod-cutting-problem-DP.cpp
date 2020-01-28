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
#define rep(i,l,r) for(int i = (int)(l) ; i <= (int)(r) ; i++)
#define clr(a,x) memset(a,x,sizeof(a));
#define rr(v) for(auto &val:v)
#define print(v) for(const auto itr:v){ cout << itr << ' ';} cout << endl;
#define init(v,x) for(auto &itr:v){ itr = x; }
#define minpq(x) x,vector<x>,greater<x>
#define ln length()
#define sz size()
#define infinity 1e18;
#define elif else if

int maxPro(int length){
    int arr[length + 1];
    clr(arr,0);
    arr[0] = arr[1] = 0;

    rep(i,2,length){
        rep(j,1,i/2+1){
            arr[i] = max(arr[i],max(j*(i - j),j*arr[i-j]));
        }
    }

    return arr[length];
}

int32_t main(){
    fastIO

    int n;

    cin >> n;

    cout << maxPro(n) << endl;

    return 0;
}