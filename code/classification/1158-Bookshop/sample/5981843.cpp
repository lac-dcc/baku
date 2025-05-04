#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
#define ll long long
#define endl "\n"
#define all(x) (x).begin() , (x).end()
#define pl pair<ll,ll>
#define mems(x,d)  memset(x , d , sizeof(x))
#define vl vector<ll>
#define ar array
 
//  template< typename T>  
//  using order_set = tree < T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ; 
 
const int sz= 1e6  + 5;
 
 
ll dp[sz];
ll h[sz] , s[sz];
 
void solve(){   
    
    
 
    int n, x;
    cin>>n>>x;
    for(int i=0; i< n; i++){
        cin>> h[i];
    }
    for(int i=0; i< n;i++) cin>>s[i];
 
    mems(dp, 0);
    for(int i=0; i < n; i++){
        for(int j=x; j>= h[i] ; j--){
            dp[j] = max(dp[j] , dp[j - h[i]] + s[i]);
        }
    }
    cout<<dp[x]<<endl;
 
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    
 
    int tc  = 1;
    //cin>>tc;
    while (tc--)
    {
        solve();
    }
    
    
    return 0;
}