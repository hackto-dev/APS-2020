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

vector<bool> v;
vector<vector<int>> g;

void edge(int a,int b){
    g[a].pub(b);
}

void bfs(int u){
    queue<int> q;

    q.push(u);
    v[u] = true;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        cout << f << " ";

        for(auto i = g[f].begin() ; i != g[f].end() ; i++){
            if(!v[*i]){
                q.push(*i);
                v[*i] = true;
            }
        }
    }

    cout << endl;
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
        edge(a,b);
    }

    rep(i,0,n){
        if(!v[i])
            bfs(i);
    }

    return 0;
}