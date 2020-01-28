#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long long int ull;


int main(){
    ll n,sum = 0,count = 0;

    cin >> n;

    ll arr[n][n];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            sum += arr[j][i];
        }

        if(sum == -1*n){
            cout << i + 1 << endl;
        }

        else{
            count += 1;

            if(count >= n)
                cout << "-1" << endl;
        }

        sum = 0;
    }
    return 0;
}