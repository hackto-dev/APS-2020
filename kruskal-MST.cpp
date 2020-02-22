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

struct Graph {
    int V,E;

    vector<pair<int,pi>> edges;

    Graph(int V,int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u,int v,int w) {
        edges.push_back({w,{u,v}});
    }

    int kruskalMST();
};

struct DSU {
    int *parent,*rank;
    int n;

    DSU(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        rep(i,0,n+1) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    void merge(int x,int y) {
        x = find(x),y = find(y);

        if(rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }

        if(rank[x] == rank[y]) {
            ++rank[y];
        }
    }
};

int Graph::kruskalMST() {
    int mst_wt = 0;

    sort(edges.begin(),edges.end());

    DSU ds(V);

    vector<pair<int,pi>>::iterator it;

    for(it = edges.begin() ; it != edges.end() ; it++) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v) {
            mst_wt += it->first;
            ds.merge(set_u,set_v);
        }
    }

    return mst_wt;
}

int32_t main(){
    fastIO

    int V,E;

    cin >> V >> E;
    Graph g(V,E);

    rep(i,0,E) {
        int start,end,weight;

        cin >> start >> end >> weight;

        g.addEdge(start,end,weight);
    }

    cout << g.kruskalMST() << endl;

    return 0;
}
