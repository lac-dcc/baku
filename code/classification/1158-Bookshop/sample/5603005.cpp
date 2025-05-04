#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int> dp(x + 1);
    for(int j = 0; j < n; j++){
        vector<int> newdp(x + 1);
        for(int i = 0; i <= x; i++){
            if(i >= a[j]){
                int val = max(dp[i],dp[i-a[j]] + b[j]);
                newdp[i] = max(newdp[i],val);
            }
            else{
                newdp[i] = max(newdp[i],dp[i]);
            }
        }
        dp = newdp;
    }
    cout << dp[x] << endl;
}