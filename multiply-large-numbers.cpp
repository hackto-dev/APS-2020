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

string multiply(string num1,string num2) {
    int len1 = num1.ln;
    int len2 = num2.ln;

    if(len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1+len2,0);

    int i_n1 = 0;
    int i_n2 = 0;

    for(int i = len1 - 1 ; i >= 0 ; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for(int j = len2 - 1 ; j >= 0 ; j--) {
            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[i_n1+i_n2] + carry;

            carry = sum/10;

            result[i_n1+i_n2] = sum%10;

            i_n2 += 1;
        }

        if(carry > 0)
            result[i_n1+i_n2] += carry;

        i_n1 += 1;
    }

    int i = result.sz - 1;

    while(i >= 0 && result[i] == 0)
        i -= 1;

    if(i == -1)
        return "0";

    string s = "";

    while(i >= 0)
        s += to_string(result[i--]);

    return s;
}

int32_t main()
{
    fastIO

    string s1 = "3141592653589793238462643383279502884197169399375105820974944592";
    string s2 = "2718281828459045235360287471352662497757247093699959574966967627";

    cout << multiply(s1,s2) << endl;

    return 0;
}
