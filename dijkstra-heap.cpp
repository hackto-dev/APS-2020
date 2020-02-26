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

void addEdge(vector<pi> adj[],int u,int v,int wt) {
    adj[u].pub(mkp(v,wt));
    adj[v].pub(mkp(u,wt));
}

void shortestPath(vector<pi> adj[],int V,int src) {
    priority_queue<minpq(pi)> pq;
    vector<int> dist(V,INT_MAX);
    
    pq.push(mkp(0,src));
    dist[src] = 0;
    
    while(!pq.empty()) {
        int u = pq.top().se;
        pq.pop();
        
        for(auto x : adj[u]) {
            int v = x.fi;
            int weight = x.se;
            
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(mkp(dist[v],v));
            }
        }
    }
    
    cout << "Vertex distance from source:\n";
    
    rep(i,0,V)
        cout << i << " " << dist[i];
        
    cout << endl;
}

int32_t main(){
    fastIO
    
    int V,E;
    cin >> V >> E;
    
    vector<pi> adj[V];
    
    int u,v,wt;
    
    rep(i,0,E) {
        cin >> u >> v >> wt;
        
        addEdge(adj,u,v,wt);
    }

    int src;
    cin >> src;

    shortestPath(adj,V,src);

    return 0;
}
