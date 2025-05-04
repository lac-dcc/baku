#include <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
 
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    int coins[n];
    vector<ll> dp(x + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - coins[j] < 0)
                continue;
            dp[i] += dp[i - coins[j]];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << endl;
    return 0;
 
}
