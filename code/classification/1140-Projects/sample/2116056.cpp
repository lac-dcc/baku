using namespace std;
#include <bits/stdc++.h>
#include <iostream>
 
 
#define         mod                 1000000007
#define         FastRead             ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define         ll                     long long int
#define         ld                    long double
#define         vi                    vector<ll>
#define            pi                     pair<ll,ll>
#define            vpi                    vector<pi>
#define         mp                    make_pair
#define            pb                  push_back
#define         F                   first
#define         S                     second
#define         f(i,a,b)            for(ll i=a;i<b;i++)
#define         rep(i,n)             f(i,0,n)
#define         fd(i,a,b)            for(ll i=a;i>=b;i--)
#define            get_mod(a)            (mod+(a%mod))%mod
 
bool cmp(pair<pi,ll> a,pair<pi,ll> b){
    if(a.F.S<b.F.S){
        return 1;
    }
    else if(a.F.S==b.F.S){
        if(a.F.F<b.F.F){
            return 1;
        }
        return 0;
    }
    return 0;
}
// bool cmp1(pair<pi,ll> a,pair<pi,ll> b){
//     return a.F.S<b.F.S;
// }
//----Declare---
int t;
ll n;
const ll mxn = 2e5+5;
vector<pair<pi,ll>> pts(mxn);
vi dp(mxn,-1);
vi eps;
//-----------
 
ll calc(ll idx){
    if(idx<0) return 0ll;
    
    if(dp[idx]!=-1)return dp[idx];
 
    ll a1 = calc(idx-1);
    ll pos = lower_bound(eps.begin(),eps.end(),pts[idx].F.F)-eps.begin();
    --pos;
    ll a2 = pts[idx].S + calc(pos);
 
    return dp[idx] = max(a1,a2);
}
 
int main() {
    FastRead;
    t = 1;
    while(t--){
        cin>>n;
        rep(i,n){
            cin>>pts[i].F.F>>pts[i].F.S>>pts[i].S;
            eps.pb(pts[i].F.S);
        }
        sort(pts.begin(),pts.begin()+n,cmp);
        // rep(i,n){
        //     cout<<pts[i].F.F<<" "<<pts[i].F.S<<" "<<pts[i].S<<endl;
        // }
        sort(eps.begin(),eps.end());
        calc(n-1);
        cout<<dp[n-1];
    }
    return 0;
}
 
 
