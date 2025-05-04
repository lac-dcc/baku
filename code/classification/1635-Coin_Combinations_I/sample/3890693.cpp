#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MOD = 1e9 + 7;
int dp[1000001];
 
 
int main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n, m; cin >> n>> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < v.size(); j++)
            if (i - v[j] >= 0)
                dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
    }
    cout << dp[m];
return 0;
}