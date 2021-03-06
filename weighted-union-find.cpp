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

int arr[100000];
int size[100000];

void addEdge(vector<pi> adj[],int u,int v,int wt) {
    adj[u].pub(mkp(v,wt));
    adj[v].pub(mkp(u,wt));
}

int root(int i) {
    while(arr[i] != i) {
        i = arr[i];
    }
    
    return i;
}

bool find(int u,int v) {
    if(root(u) == root(v)) {
        return true;
    }
    
    else {
        return false;
    }
}

void initialize(int n) {
    rep(i,0,n) {
        arr[i] = i;
        size[i] = 1;
    }
}

void weighted_union(int u,int v) {
    int root_u = root(arr,u);
    int root_v = root(arr,v);
    
    if(size[root_u] < size[root_v]) {
        arr[root_u] = arr[root_v];
        size[root_v] += size[root_u];
    } else {
        arr[root_v] = arr[root_u];
        size[root_u] += size[root_v];
    }
    
    rep(i,0,n)
        cout << arr[i] << " ";
        
    cout << endl;
}

int32_t main(){
    fastIO
    
    int n;
    cin >> n;
    
    initialize(n);
    
    int u,v;
    cin >> u >> v;
    
    weighted_union(u,v);

    return 0;
}
