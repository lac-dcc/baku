#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define int long long
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pi pair<int,int>
 
const int INF = 1e9;
 
void solve(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i = 0; i < n ; i++) cin>>arr[i];
    sort(arr,arr+n);
    vector<int> dp(x+1,INF);
    dp[0] = 0;
 
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0; j < n && arr[j] <= i ; j++){
            dp[i] = min(dp[i],1+dp[i-arr[j]]);
        }
    }
    if(dp[x] == INF) cout<<-1;
    else cout<<dp[x];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1;
    // cin>>t;
    while(t--){;
        solve();
    }
    return 0;
}
