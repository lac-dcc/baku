#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<ll> l,r,lv,rv;
    ll n,m;
    cin>>n>>m;
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        if(i<n/2)l.push_back(k);
        else r.push_back(k);
    }
    ll sl = l.size(),sr = r.size();
    for(ll i = 0;i<(1LL<<sl);i++){
        ll tmp = 0;
        for(ll j = 0;j<sl;j++){
            if(((1LL<<j)&i) != 0)tmp += l[j];
        }
        lv.push_back(tmp);
    }
    for(ll i = 0;i<(1LL<<sr);i++){
        ll tmp = 0;
        for(ll j = 0;j<sr;j++){
            if(((1LL<<j)&i)!= 0)tmp += r[j];
        }
        rv.push_back(tmp);
    }
    /*
    for(auto i:l)cout<<i<<' ';cout<<endl;
    for(auto i:r)cout<<i<<' ';cout<<endl;
    for(auto i:lv)cout<<i<<' ';cout<<endl;
    for(auto i:rv)cout<<i<<' ';cout<<endl;
    */
    sort(rv.begin(),rv.end());
    sort(lv.begin(),lv.end());
    ll p = rv.size()-1;
    ll ans = 0;
    for(ll i = 0;i<lv.size();i++){
        ans += upper_bound(rv.begin(),rv.end(),m-lv[i])-lower_bound(rv.begin(),rv.end(),m-lv[i]);
    }
    cout<<ans;
}
