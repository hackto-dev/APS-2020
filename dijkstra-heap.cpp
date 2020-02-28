#include<bits/stdc++.h> 
using namespace std; 

#define INF 0x3f3f3f3f   
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
  
void addEdge(vector <pair<int, int> > adj[], int u, 
                                     int v, int wt) 
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
   
void shortestPath(vector<pi> adj[], int V, int src) 
{ 
    
    priority_queue< minpq(pi) > pq; 
 
    vector<int> dist(V, INF); 
  
    pq.push(mkp(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    {  
        int u = pq.top().second; 
        pq.pop(); 
    
        for (auto x : adj[u]) 
        { 
            int v = x.first; 
            int weight = x.second; 
  
             
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(mkp(dist[v], v)); 
            } 
        } 
    } 
  
    printf("Vertex Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%lld \t\t %lld\n", i, dist[i]); 
} 
  
int32_t main() 
{ 
    int V,E;
    cin >> V >> E; 
    vector<pi> adj[V]; 
  
    rep(i,0,E) {
        int u,v,w;

        cin >> u >> v >> w;

        addEdge(adj,u,v,w);
    } 
  
    int src;
    cin >> src;
    shortestPath(adj, V, src); 
  
    return 0; 
} 
