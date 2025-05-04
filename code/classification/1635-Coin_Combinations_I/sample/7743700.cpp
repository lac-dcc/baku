#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= arr[j]){
                dp[i] = (dp[i] + dp[i-arr[j]]) % 1000000007;
            }
        }
    }
    cout << dp[x];
    return 0;
}
