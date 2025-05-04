#define _GLIBCXX_FILESYSTEM
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define db1(x) cout<<#x<<" "<<x<<'\n';
 
const int N = 2e5+7;
const ll inf = 1e15;
const ll mod = 1e9+7;
#define eps 1e-10
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
 
ll n,m,k;
string s;
 
ll get_sum(ll beg,ll en){
    en%=mod;
    beg%=mod;
    ll tot = en*(en+1)%mod*500000004%mod;
    ll sub = (beg-1+mod)%mod*beg%mod*500000004%mod;
    ll ret = (tot-sub+mod)%mod;
    return ret;
}
 
void solve(){
 
    cin>>n;
    ll ans = 0;
    for(ll i=1,last;i<=n;i=last+1){
        last = n/(n/i);
        ll now = (n/i)%mod*get_sum(i,last)%mod;
        ans += now;
        ans %= mod;
    }
    cout<<ans<<'\n';
    return;
}
int32_t main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,cnt=1;
    // cin>>t;
    while(t--){
        // cout<<"Case "<<cnt++<<": ";
        solve();
    }
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}