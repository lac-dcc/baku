#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
const int N = 5000 + 5;
 
string s, t;
int n, m, dp[N][N];
 
int go(int i, int j){
    if(i == n) return m - j;
    if(j == m) return n - i;
 
    int& ret = dp[i][j];
    if(~ret) return ret;
 
    if(s[i] == t[j]) return go(i + 1, j + 1);
 
    ret = min({go(i + 1, j), go(i, j + 1), go(i + 1, j + 1)}) + 1;
 
    return ret;
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> s >> t;
    n = s.size(), m = t.size();
    clr(dp, -1);
    cout << go(0, 0);
    return 0;
}
