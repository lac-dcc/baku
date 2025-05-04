#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int N = 1e6, M = 1e9+7;
int n, x;
ll dp[N + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> x;
    int coin[n];
    for (int i = 0; i < n; i++) cin >> coin[i];
    
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(j - coin[i] >= 0) 
                dp[j] = (dp[j] + dp[j - coin[i]])%M;
        }
    }
    
    cout << dp[x] << endl;
}
