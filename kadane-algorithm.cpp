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

int kadane(int arr[], int n)
{
	int max_so_far = 0;

	int max_ending_here = 0;

	for (int i = 0; i < n; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		max_ending_here = max(max_ending_here, 0);
		max_so_far = max(max_so_far, max_ending_here);
	}

	return max_so_far;
}


int32_t main(){
    fastIO

    return 0;
}
