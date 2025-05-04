#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdb;
typedef pair<ll,ll> pll;
 
template<class T> using ordset = tree<T,
                        null_type, less<T>,
                        rb_tree_tag, tree_order_statistics_node_update>;
 
#define pb push_back
#define ft first
#define sd second
#define all(x) x.begin(), x.end()
#define lef(x) (x<<1)
#define rig(x) (lef(x)|1)
#define sz(x) (int)(x.size())
 
const int N = 2e5+5;
 
vector<ll> a, b, s1, s2;
 
void test(){
    ll n, x;
    cin >> n >> x;
 
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        if(i&1){
            a.pb(v);
        }
        else{
            b.pb(v);
        }
    }
 
    n = a.size();
    int m = b.size();
 
    for(int i = 0; i < (1<<n); i++){
        ll sum = 0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j))
                sum += a[j];
        }
        s1.pb(sum);
    }
 
    for(int i = 0; i < (1<<m); i++){
        ll sum = 0;
        for(int j = 0; j < m; j++){
            if(i&(1<<j))
                sum += b[j];
        }
        s2.pb(sum);
    }
 
    sort(all(s1));
    sort(all(s2));
 
    ll ans = 0;
 
    for(auto i: s1){
        ll a1, a2;
        if(binary_search(all(s2), x-i)){
            a1 = lower_bound(all(s2), x-i) - s2.begin();
            a2 = upper_bound(all(s2), x-i) - s2.begin();
            ans += (a2-a1);
        }
    }
 
    cout << ans << "\n";
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int teste = 1;
    // cin >> teste
 
    while(teste--){
        test();
    }
    
    return 0;
}
