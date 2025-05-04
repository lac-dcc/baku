#include<iostream>
#include<algorithm>
using namespace std;
 
 
int main(){
 
    int n, x;
    cin >> n >> x;
    int h[n+1], s[n+1], dp[x+1];
    h[0] = 0, s[0] = 0;
 
    fill(dp, dp + x + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> h[i];
    for(int i = 1; i <= n; ++i) cin >> s[i];
 
    for(int i = 1; i <= n; ++i){
        for(int j = x; j >= 1; --j){
 
            if (j >= h[i])
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
 
    cout << dp[x] << '\n';
 
 
    return 0;
}
