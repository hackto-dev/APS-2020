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
int L[101][101];

int lcs(string X,string Y,int m,int n){
    //int L[m + 1][n + 1];
    
    for(int i = 0 ; i <= m ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }

            elif(X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            }

            else {
                L[i][j] = max(L[i - 1][j],L[i][j - 1]);
            }
        }
    }

    return L[m][n];
}

void backtrack(string X,string Y,int m,int n){
    
    int i = m;
    int j = n;
    string s;
    while(i > 0 && j > 0){
        if(L[i][j] > L[i - 1][j]){
            i--;
            s += X[i];
        }

        elif(L[i][j] > L[i][j - 1]){
            j--;
            s += Y[j];
        }

        else
        {
            i--;
        }
    }

    cout << s << endl;
}

int32_t main(){
    fastIO

    string X,Y;

    cin >> X >> Y;

    cout << lcs(X,Y,X.sz,Y.sz) << endl;
    backtrack(X,Y,X.sz,Y.sz);

    return 0;
}