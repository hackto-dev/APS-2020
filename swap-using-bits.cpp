#include <bits/stdc++.h>

using namespace std;

int main() {
	int x,y;
	cin >> x >> y;
	
	if(x != y) {
		x ^= y;
		y = x ^ y;
		x ^= y;
	}
	
	cout << x << "\t" << y << endl;
	
	return 0;
}
