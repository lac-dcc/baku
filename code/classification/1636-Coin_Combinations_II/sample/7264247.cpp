#include <bits/stdc++.h>
 
#define adiyer(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
 
using namespace std;
 
const int N = 2e6 + 245;
const int M = 1e2 + 123;
const int inf = 1e18 + 10;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 9;
const int mod2 = 998244353;
const int P = 31;
const int P1 = 61;
const int P2 = 37;
 
int tt = 1, n, s;
int a[N], dp[N];
 
void output(){
    cin >> n >> s, dp[0] = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % mod;
        }
    }
    cout << dp[s] % mod;
}
 
signed main(){
    adiyer();
//  cin >> tt;
    for(int i = 1; i <= tt; i++){
//      cout << "Case " << i << ":\n";
        output();
    }
}
