#include <bits/stdc++.h>
using namespace std;
 
const int modu = 1e9 + 7;
 
int main(){
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    vector<int> dp(x+1);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    dp[0] = 1;
    for(int i=0; i<=x; ++i){
        for(int j=0; j<n; ++j){
            if(i - a[j] >= 0){
                dp[i] += dp[i - a[j]];
                dp[i] %= modu;
            }
        }
    }
 
    cout << dp[x];
}
