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

void initialize(int n) {
    rep(i,0,n) {
        arr[i] = i;
        size[i] = 1;
    }
}

int union(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       
}

bool find(int A,int B)
{
    if( root(A)==root(B) )       
        return true;
    else
        return false;
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
