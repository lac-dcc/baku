#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
 
using namespace std;
 
#define ll long long int
#define oo 1e9
#define pii pair<int, int>
 
const int MAX = 1e6 + 6;
const int MOD = 1e9 + 7;
 
int n, x;
int dp[MAX];
int arr[101];
 
int main(){
    for (int i = 0; i < MAX; i++)
    {
        dp[i] = oo;
    }
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i - arr[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
        
    }
    if(dp[x] > 1e6){
        cout << -1;
        return 0;
    }
    cout << dp[x];
}