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

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    fastIO;
    
    int n,N;
    pair<int,int> arr[100][100];
    map<int,int> mp[100],wp[100],cpm,cpw,prop;
    
    cin >> n;
    N = n;
    
    rep(i,0,n){
        rep(j,0,n){
            cin >> arr[i][j].fi;
            mp[i + 1][arr[i][j].fi] = j + 1;
        }
    }
    
    rep(i,0,n){
        rep(j,0,n){
            cin >> arr[i][j].se;
            wp[j + 1][i + 1] = arr[i][j].se;
        }
    }
    
    rep(k,0,n){
        rep(i,1,n+1){
            rep(j,1,n + 1){
                if(cpm[i] == 0){
                    prop[mp[i][j]] += 1;
                    
                    if(!cpw[mp[i][j]] || cpw[mp[i][j]] > wp[mp[i][j]][i]){
                        cpm[cpw[mp[i][j]]] = 0;
                        cpw[mp[i][j]] = i;
                        cpm[i] = mp[i][j];
                    }
                }
            }
        }
    }
    
    int q,x;
    
    cin >> q;
    
    rep(i,0,q){
        cin >> x;
        cout << prop[x] << endl;
    }
    
    return 0;
}