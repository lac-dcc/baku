#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[25],b[25];
vector<ll> aa,bb;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    for(int i=0;i<n/2;i++){
        cin>>a[i];
    }
    for(int i=0;i<(n+1)/2;i++){
        cin>>b[i];
    }
    for(ll c=0;c<(1<<(n/2));c++){
        ll ans=0;
        for(int i=0;i<n/2;i++){
            if(c&(1<<i)){
                ans+=a[i];
            }
        }
        aa.push_back(ans);
    }
    for(ll c=0;c<(1<<((n+1)/2));c++){
        ll ans=0;
        for(int i=0;i<(n+1)/2;i++){
            if(c&(1<<i)){
                ans+=b[i];
            }
        }
        bb.push_back(ans);
    }
    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());
    ll ans=0;
    for(auto u:aa){
        ans+=upper_bound(bb.begin(),bb.end(),x-u)-lower_bound(bb.begin(),bb.end(),x-u);
    }
    cout<<ans<<"\n";
    return 0;
}
