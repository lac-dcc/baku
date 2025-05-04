//بسم الله الرحمن الرحيم
// i love mancity                                                 ____
/*
 *
 */
 
#include<bits/stdc++.h>
#include <stack>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define             endl "\n"
#define             ll long long
#define             pii pair<int,int>
#define             pll pair<ll,ll>
#define             f(a) for(int i=0;i<a;i++)
#define             rf(a) for(int i=a-1;i>=0;i--)
#define             w  int t;cin>>t;while(t--)
#define             all(v) v.begin(),v.end()
#define             yes cout<<"YES"<<endl;
#define             no cout<<"NO"<<endl;
#define             prev2pn(x) pow(2,floor(log2(x)))
#define             RR iostream::sync_with_stdio(false);cin.tie(nullptr); \
                    cout.tie(nullptr);
#define             arrRange(a , l , r) int _##a[(r-l)+1]; int* a= _##a-l;
#define             ordered_set tree<int, null_type,less<int>, \
                    rb_tree_tag,tree_order_statistics_node_update>
#define             OO 0x3f3f3f3f3f3f3f3f
#define             pr(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define             ld long double
#define             fr first
#define             se second
#define             sz(s) (int)s.size()
const ll MOD=1e9+7;
const int N= 2e5+5;
const int k= 2005;
const double EPS = 1e-6;
const double PI = 3.14159265;
 
using namespace std;
using namespace __gnu_pbds;
using namespace std;
 
 
void solve() {
    ll n,m;
    cin>>n>>m;
    ll arr[n+5];
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    ll dp[m+5];
    memset(dp,0,sizeof dp);
    dp[0]=1;
 
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m; ++j) {
            if(j-arr[i]>=0){
                dp[j]+=dp[j-arr[i]];
                dp[j]%=MOD;
            }
        }
    }
    cout<<dp[m]<<endl;
}
 
 
int main() {
    RR
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q=1;
//    cin>>q;
    while (q--) {
        solve();
    }
    return 0;
}