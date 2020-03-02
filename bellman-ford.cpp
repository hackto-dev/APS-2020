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

const int MAX = 100;
const int INF = 1e9+5;

struct edges {
    int u;
    int v;
    long long w;
    edges(int u, int v, long long w): u(u), v(v), w(w) {}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector<edges> edge;

	for (int i = 0; i < m; i++) {
		int a, b;
		long long w;
		scanf("%d%d%lld", &a, &b, &w);
		edge.push_back(edges(a, b, w));
	}

	int parent[MAX];
	long long dist[MAX];
	for (int i = 0; i < n; i++) {
		parent[i] = 0;
		dist[i] = INF;
	}

	dist[0] = 0; // distance of source node = 0
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int u = edge[j].u;
			int v = edge[j].v;
			long long w = edge[j].w;
			if (dist[u] != INF) {
				if (dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					parent[v] = u;
				}
			}
		}
	}

	bool negCycleExists = false;
	for (int j = 0; j < edge.size(); j++) {
		int u = edge[j].u;
		int v = edge[j].v;
		long long w = edge[j].w;
		if (dist[v] > (dist[u] + w)) {
			negCycleExists = true;
			break;
		}
	}

	if (negCycleExists) {
        cout << "Negative Cycle Exists";
	} else {
        for (int i = 0; i < n; i++) {
            cout << i << "=>" << dist[i] << endl;
        }
	}
	
	return 0;
}
