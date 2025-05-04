#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
#define ll long long
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
 
// Declaring ordered_set
template <typename T>
using ordered_set =  tree<T, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;
void solve(string s, int n){
 
    return ;
 
}
bool cont(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) {
        return (a.first < b.first);
    }
    else {
        return (a.second > b.second);
    }
 
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, x;
        cin>>n>>x;
        ll res;
        ll mod = 1e9 + 7;
        vector<unsigned int> dp(x + 1, 0);
        dp[0] = 1;
        vector<int> coins(n);
        for(int i = 0; i < n; i++) {
            cin>>coins[i];
        }
        sort(coins.begin(), coins.end());
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= x; j++) {
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                    dp[j] = dp[j]%mod;
                }
            }
        }
        cout<<dp[x]%mod<<endl;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
}
 
 
 
