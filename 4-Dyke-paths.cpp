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

int count = 0;

void way1s(int x,int y,int n,string v){
    if(x == n && y == n){
        count += 1;
        cout << v << endl;
        return;
    }

    elif(x < y || x > n || y > n){
        way1s(x+1,y,n,v + "x");
        way1s(x,y+1,n,v + "y");
        return;
    }
}

int32_t main(){
    fastIO

    int n;
    cin >> n;
    string v = " ";
    way1s(0,0,n,v);
    cout << count << endl;
    return 0;
}