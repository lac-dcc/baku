#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<ll> day;
 
bool comp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
    return a.first.second<=b.first.second;
}
 
ll bs(ll x){
    ll l=0,r=day.size()-1;
    ll ans=-1;
    
    while(l<=r){
        ll md=(l+r)/2ll;
        if(day[md]<=x){
            ans=md;
            l=md+1;
        }
        else
            r=md-1;
    }
    
    return ans;
}
 
int main(){
    int n;
    cin>>n;
    
    vector<pair<pair<ll,ll>,ll>> v;
    
    for(int i=1;i<=n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        pair<pair<ll,ll>,ll> p={{a,b},c};
        v.push_back(p);
    }
    
    sort(v.begin(),v.end(),comp);
    
    ll dp[n+1];
    
    day.push_back(0ll);
    
    dp[0]=0;
    
    for(int i=0;i<n;i++){
        ll x=bs(v[i].first.first-1);
        dp[i+1]=max(dp[i],v[i].second+dp[x]);
        day.push_back(v[i].first.second);
    }
    
    cout<<dp[n]<<endl;
}
