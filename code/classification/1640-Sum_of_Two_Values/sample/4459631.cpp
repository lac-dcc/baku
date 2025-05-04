#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define int ll
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using str = string;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define read(x, i) for (int (i) = 0; (i) < sz((x)); ++(i))cin >> (x)[(i)]
#define check() cout<<"Non crash\n"; return;
#define F first
#define S second
 
const ll inf = 1e18, mod1 = 1e9+7, mod2 = 998244353;
const ld eps = 1e-9;
 
inline void solve(){
    int n, x; cin>>n>>x;
    vector<pii>a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i].F;
        a[i].S = i;
    }
    sort(all(a));
    for(int i=0; i<n; ++i){
        if(x < a[i].F) continue;
        int k = i+1, num = x - a[i].F;
        for(int b = n/2; b>=1; b/=2){
            while(k+b < n && a[k+b].F <= num) k+=b;
        }
        if(k != n && a[k].F + a[i].F == x){cout<<a[k].S+1<<" "<<a[i].S+1; return;}
    }
    cout<<"IMPOSSIBLE";
}
 
int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    /* int t;
    cin>>t;
    while(t--) */ solve();
    
    return 0;
}
