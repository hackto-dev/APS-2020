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

string LCS(string X,string Y,int m,int n){
    int maxlen = 0;
    int endIndex = m;

    int L[m + 1][n + 1];

    clr(L,0)

    rep(i,1,m){
        rep(j,1,n){

            if(X[i - 1] == Y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;

                if(L[i][j] > maxlen){
                    maxlen = L[i][j];
                    endIndex = i;
                }
            }
        }
    }

    return X.substr(endIndex - maxlen,maxlen);
    
}

int32_t main(){
    fastIO

    string X,Y;

    cin >> X >> Y;

    cout << LCS(X,Y,X.ln,Y.ln) << endl;
    return 0;
}