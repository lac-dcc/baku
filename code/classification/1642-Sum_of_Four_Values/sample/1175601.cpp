/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 00:37:44       
**/
#include "bits/stdc++.h"
using namespace std; 
 
#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
 
const ll mod=1e4;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    map<ll,ll> m;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll index1=i+1,index2=j+1;
            ll num=index1*mod + index2;
            m[a[i]+a[j]]=num;
        }
    }
    ll ans[4]={0};
    bool ok=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            auto it= m.find(x-a[i]-a[j]);
            if(it != m.end()){
                ll x=(it->second);
                ll a,b;
                a=x/mod , b=x%mod;
                if(a!=i+1 && a!=j+1 && b!=i+1 && b!=j+1){
                    ok=1;
                    ans[0]=i+1,ans[1]=j+1,ans[2]=a,ans[3]=b;
                    break;
                }
            }
            if(ok)break;
        }
        if(ok)break;
    }
 
    if(ok){
        sort(ans,ans+4);
        for(ll i=0;i<4;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    else cout<<"IMPOSSIBLE\n";
    return 0;
}
