#include <bits/stdc++.h>
#define fast_input_output() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define int long long 
ll n, a[3000005],q; 
ll sum [3000005], pref[3000005], suff[3000005], seg[3000005];
ll pw = 0, total = 0;
void build ( int node, int l, int r )
{
      if(l==r-1) { 
        sum[node] = a[l];
        pref[node] = ( suff[node] = ( seg[node] = max(0ll,a[l])) ) ;
        return;
      }
      build(node*2+1, l, (r+l)/2);
      build(node*2+2, (r+l)/2, r);
      sum[node] = sum[node*2+1]+sum[node*2+2];
      pref[node] = max ( pref[node*2+1], sum[node*2+1]+pref[node*2+2] );
      suff[node] = max ( suff[node*2+2], suff[node*2+1]+sum[node*2+2] );
      seg[node] = max ( seg[node*2+1], seg[node*2+2] );
      seg[node] = max ( seg[node], suff[node*2+1]+pref[node*2+2] );
}
void update ( int node )
{
    sum[node] = sum[node*2+1]+sum[node*2+2];
    pref[node] = max ( pref[node*2+1], sum[node*2+1]+pref[node*2+2] );
    suff[node] = max ( suff[node*2+2], suff[node*2+1]+sum[node*2+2] );
    seg[node] = max ( seg[node*2+1], seg[node*2+2] );
    seg[node] = max ( seg[node], suff[node*2+1]+pref[node*2+2] );
    if(node==0) return; 
    if(node&1) update((node-1)/2);
    else update((node-2)/2);
}
signed main() {
 
      fast_input_output();
      cin>>n>>q;
      for(int i=0; i<=20; i++ ) {
        if((1<<i)>=n) { pw = (1<<i); break; }
        total += (1<<i);
      }
     for(int i=0; i<n; i++) 
        cin>>a[i];
      build(0,0,pw);
      while(q--){
        int x,y; cin>>x>>y;
        x--;
        sum[total+x] = y;
        pref[total+x] = ( suff[total+x] = ( seg[total+x] = max(0ll,y)) ) ;
        if(!(total+x)) {
            cout<<seg[0]<<'\n';
            continue;
        } 
        if((total+x)&1) update((total+x-1)/2);
        else update((total+x-2)/2);
        cout<<seg[0]<<'\n';
      }
     return 0;
}
