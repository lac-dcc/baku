#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
struct node{
    ll a,p,s,ts;
};
vector<node>seg;
void build(vector<ll>&v,ll l,ll r,ll idx){
    if(l==r){
        seg[idx].a=v[l];
        seg[idx].p=v[l];
        seg[idx].s=v[l];
        seg[idx].ts=v[l];
        return ;
    }
    ll m=(l+r)/2;
    build(v,l,m,2*idx+1);
    build(v,m+1,r,2*idx+2);
    seg[idx].ts=seg[2*idx+1].ts+seg[2*idx+2].ts;
   seg[idx].a=max({seg[2*idx+1].a,seg[2*idx+2].a,seg[2*idx+1].s+seg[2*idx+2].p});
   seg[idx].p=max({seg[2*idx+1].p,seg[2*idx+1].ts+seg[2*idx+2].p});
   seg[idx].s=max({seg[2*idx+2].s,seg[2*idx+1].s+seg[2*idx+2].ts});
}
 
// ll query(ll ql,ll qr,ll l,ll r,ll idx){
//     if(l>qr||r<ql)return INT_MAX;
//     if(l>=ql&&r<=qr)return seg[idx].second;
//     ll m=(l+r)/2;
//     return min(query(ql,qr,l,m,2*idx+1),query(ql,qr,m+1,r,2*idx+2));
// }
 
 
void update(ll l,ll r,ll idx,ll k,ll val){
     if(l>k||r<k)return;
    if(l==r){
        seg[idx].a=val;
        seg[idx].s=val;
        seg[idx].p=val;
        seg[idx].ts=val;
        return;
    }
    ll m=(l+r)/2;
    update(l,m,2*idx+1,k,val);
    update(m+1,r,2*idx+2,k,val);
    seg[idx].ts=seg[2*idx+1].ts+seg[2*idx+2].ts;
   seg[idx].a=max({seg[2*idx+1].a,seg[2*idx+2].a,seg[2*idx+1].s+seg[2*idx+2].p});
   seg[idx].p=max({seg[2*idx+1].p,seg[2*idx+1].ts+seg[2*idx+2].p});
   seg[idx].s=max({seg[2*idx+2].s,seg[2*idx+1].s+seg[2*idx+2].ts});
}
void solve()
{
       ll n,q;
       cin>>n>>q;
       vector<ll>v(n);
       for(ll i=0;i<n;i++)cin>>v[i];
       seg.clear();
       seg.resize(4*n);
       build(v,0,n-1,0);
       while(q--){
        ll k,val;
        cin>>k>>val;
        update(0,n-1,0,k-1,val);
        if(seg[0].a>0)cout<<seg[0].a<<"\n";
        else cout<<"0\n";
       }
 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tt = 1, n = 1;
     //cin >> tt;
    // n = tt;
    while (tt--)
    {
        // cout<<"Case #"<<n-tt<<": ";
        solve();
    }
 
    // your code goes here
    return 0;
}
