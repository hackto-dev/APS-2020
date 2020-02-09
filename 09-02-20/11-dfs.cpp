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

vector<vector<int>>g;
vector<bool>v;

void addEdge(int a,int b){
    g[a].pub(b);
    g[b].pub(a);
}

void dfsVisit(int u){
    v[u] = true;
    cout << u << " ";

    for(auto i = g[u].begin() ; i != g[u].end() ; i++){
        if(!v[*i])
            dfsVisit(*i);
    }
}

void dfs(int n){
    rep(u,0,n){
        if(!v[u])
            dfsVisit(u);
    }
}

int32_t main(){
    fastIO

    int n,e;
    cin >> n >> e;

    v.assign(n,false);
    g.assign(n,vector<int>());

    int a,b;

    rep(i,0,e){
        cin >> a >> b;
        addEdge(a,b);
    }

    dfs(n);
    cout << endl;

    return 0;
}