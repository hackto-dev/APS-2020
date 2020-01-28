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
#define rep(i,l,r) for(int i = (int)(l) ; i <= (int)(r) ; i++)
#define clr(a,x) memset(a,x,sizeof(a));
#define rr(v) for(auto &val:v)
#define print(v) for(const auto itr:v){ cout << itr << ' ';} cout << endl;
#define init(v,x) for(auto &itr:v){ itr = x; }
#define minpq(x) x,vector<x>,greater<x>
#define ln length()
#define sz size()
#define infinity 1e18;
#define elif else if

#define MAX 20

int lookup[MAX][MAX];

string LCS(string X,string Y,int m,int n){
    
    if(m == 0 || n == 0){
        return string("");
    }

    if(X[m - 1] == Y[n -1]){
        return LCS(X,Y,m - 1,n - 1) + X[m - 1];
    }

    if(lookup[m - 1][n] > lookup[m][n - 1]){
        return LCS(X,Y,m - 1,n);
    }

    else{
        return LCS(X,Y,m,n - 1);
    }
}

void LCSLength(string X,string Y,int m,int n){
    
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(X[i - 1] == Y[j - 1]){
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }

            else {
                lookup[i][j] = max(lookup[i - 1][j],lookup[i][j - 1]);
            }
        }
    }
}

int32_t main(){
    fastIO

    string X,Y;

    cin >> X >> Y;

    LCSLength(X,Y,X.sz,Y.sz);

    cout << LCS(X,Y,X.sz,Y.sz) << endl;

    return 0;
}