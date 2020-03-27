#include <bits/stdc++.h>
using namespace std;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define mkp make_pair
#define pi pair<int, int>
#define push push
#define all(v) v.begin(), v.end()
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define clr(a, x) memset(a, x, sizeof(a));
#define rr(v) for (auto &val : v)
#define print(v)             \
    for (const auto itr : v) \
    {                        \
        cout << itr << ' ';  \
    }                        \
    cout << endl;
#define init(v, x)      \
    for (auto &itr : v) \
    {                   \
        itr = x;        \
    }
#define minpq(x) x, vector<x>, greater<x>
#define ln length()
#define sz size()
#define infinity 1e18;
#define elif else if
#define mod 1e9;

const int MAX = 1000000;

void floyd_warshall(vector<vector<int>> graph,int V) {
    vector<vector<int>> dist;

    rep(i,0,V) 
        rep(j,0,V)
            dist[i][j] = graph[i][j];

    rep(k,0,V) {
        rep(i,0,V) {
            rep(j,0,V) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    rep(i,0,V) {
        rep(j,0,V) {
            if(dist[i][j] == MAX)
                cout << "MAX" << " ";

            else 
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }
}

int32_t main()
{
    fastIO

    int V;
    cin >> V;

    vector<vector<int>> graph = {{0,5,MAX,10},
                                 {MAX,0,3,MAX},
                                 {MAX,MAX,0,1},
                                 {MAX,MAX,MAX,0}
                                };

    floyd_warshall(graph,V);

    return 0;
}
