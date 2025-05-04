#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
using db = double;
using ll = long long;
using str = string;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define fi first
#define se second
#define cont continue
#define mp make_pair
#define el '\n'
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s) {
	setIn(s+".inp"); setOut(s+".out");
}
ll n, sum;
ll a[1000005], dp[1000005];
int main(){
    faster
    //setIO("Codeforces");
    cin >> n >> sum;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill (dp, dp + sum + 1, 0);
    for (int i = 0; i < n; i++) dp[a[i]] = 1;
    for (int i = 0; i <= sum; i++){
        for (int j = 0; j < n; j++){
            if (i - a[j] >= 0) (dp[i] += dp[i - a[j]]) %= MOD;
        }
    }
    cout << dp[sum] % MOD << el;
    return 0;
}
