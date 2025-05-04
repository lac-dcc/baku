#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
#include<algorithm> 
#include<unordered_set>
using namespace std;
#define ll long long
const int mxn = 2e5+2;
const int mod = 1e9+7;
ll dp[mxn];
ll n;
struct proj{
    ll s,e,p;
    proj(){
        s=0;e=0;p=0;
    }
    proj(ll st,ll en,ll pr){
        s = st;
        e = en;
        p = pr;
    }
};
proj v[mxn];
static bool comp(proj &a,proj &b){
    if(a.e==b.e && a.s == b.s )
        return a.p < b.p;
    else if(a.e==b.e)
        return a.s<b.s;
    return a.e < b.e;
}
ll BS(ll r,ll start){
    ll l = 0;
    ll index = 0;
    while(l<=r){
        ll m = (l+r)>>1;
        if(v[m].e < start){
            index = m;
            l = m+1;}
        else
            r = m-1;
    }
    return dp[index];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int a,b,c;
    v[0].s=v[0].e=v[0].p=0;
    for(ll i=0;i<n;i++){
        cin>>a>>b>>c;
        v[i+1].s = a;
        v[i+1].e = b;
        v[i+1].p = c;
    }
    sort(v,v+n+1,comp);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        ll curS = v[i].s;
        ll prof = v[i].p;
        ll toAdd = BS(i-1,curS);
        dp[i] = max(dp[i],toAdd + prof);
        //cout<<i<<" "<<toAdd<<" "<<dp[i]<<endl;
    }
    cout<<dp[n]<<"\n";
    return 0;
}
