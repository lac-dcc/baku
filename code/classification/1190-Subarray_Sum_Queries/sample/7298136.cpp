#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
typedef long long int ll;
#define ld long double
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set;
 
const int MOD = 1e9+7;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll INF = 1e18;
 
void modify(vector<ll> &v, vector<ll> &a, vector<ll> &b){
    v[3] = a[3]+b[3];
    v[2] = max(b[2],a[2]+b[3]);
    v[1] = max(a[1],a[3]+b[1]);
    v[0] = max(a[2]+b[1],max(a[0],b[0]));
}
 
void solve(){
    ll n,k,x,a;
    cin>>n>>k;
    ll t = 1<<(ll)ceil(log2(n));
    vector<vector<ll> > v(2*t,vector<ll> (4,0));
    for(int i=0;i<n;i++){
        cin>>a;
        fill(v[t+i].begin(),v[t+i].end(),a);
    }
    for(int i=t-1;i>0;i--) modify(v[i],v[2*i],v[2*i+1]);
    for(int i=0;i<k;i++){
        cin>>x>>a;
        x+=t-1;
        fill(v[x].begin(),v[x].end(),a);
        x/=2;
        while(x>0){
            modify(v[x],v[2*x],v[2*x+1]);
            x/=2;
        }
        cout<<max((ll)0,v[1][0])<<endl;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin>>t;
    while(t--) solve();
}
