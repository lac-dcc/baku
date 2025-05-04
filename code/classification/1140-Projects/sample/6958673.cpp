#include <bits/stdc++.h>
 
#define long long long
#define mk make_pair
#define fr first
#define sc second
#define sfr second.first
#define ssc second.second
 
using namespace std;
 
const int N = 2e5 + 5;
const int inf = 1e9 + 7;
 
long dp[N];
pair<int,pair<int,int>> a[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fr >> a[i].sfr >> a[i].ssc;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(a + 1, a + n + 1, mk(a[i].sfr, mk(inf, inf))) - a;
        dp[it] = max(dp[it], dp[i] + a[i].ssc);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << dp[n + 1] << endl;
    return 0;
}
