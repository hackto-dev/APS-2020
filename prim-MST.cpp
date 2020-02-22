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

const int MAX = 1e4+5;
bool marked[MAX];
vector<pi> adj[MAX];

int prim(int x) {
    priority_queue<pi,vector<pi>,greater<pi>> Q;
    int y;
    int minCost = 0;

    pi p;

    Q.push(mkp(0,x));

    while(!Q.empty()) {
        p = Q.top();
        Q.pop();
        x = p.second;

        if(marked[x] == true)
            continue;

        minCost += p.first;
        marked[x] = true;

        rep(i,0,adj[x].size()) {
            y = adj[x][i].second;

            if(marked[y] == false) {
                Q.push(adj[x][i]);
            }
        }
    }

    return minCost;
}

int32_t main(){
    fastIO

    int nodes,edges,x,y;
    int weight,minCost,start;

    cin >> nodes >> edges;

    rep(i,0,edges) {
        cin >> x >> y >> weight;

        adj[x].pub(mkp(weight,y));
        adj[y].pub(mkp(weight,x));
    }

    cin >> start;

    minCost = prim(start);

    cout << minCost << endl;

    return 0;
}
