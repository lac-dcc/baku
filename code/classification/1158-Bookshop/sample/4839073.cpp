# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
const int N = 1e3 + 10;
const int X = 1e5 + 10;
 
int dp[X], h[N], n, s[N], x;
 
int main () {_
    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= h[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - h[i - 1]] + s[i - 1]); 
        }
    }
    
    cout << dp[x] << "\n"; 
}
