#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define be begin()
#define en end()
#define pb push_back
#define pyes cout<<"Yes\n"
#define pno cout<<"No\n"
#define ce cout<<'\n'
#define endl '\n'
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define all(v)          v.begin(),v.end()
#define mnv(v)          *min_element(v.begin(),v.end())
#define mxv(v)          *max_element(v.begin(),v.end())
#define fi              first
#define se              second
#define vll             vector<ll>
#define vp              vector<pair<long long,long long>>
#define trav(v)         for(auto it =v.begin();it!=v.end();it++)
#define rep(i, b, e) for (__typeof(e) i = (b) - ((b) > (e)); i != (e) - ((b) > (e)); i += 1 - 2 * ((b) > (e)))
 
const ll mod=1e9+7;
 
void vin(vector<ll> &a,int n){
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        a.push_back(x);
    }
}
 
const ll INF = 2 * 1024 * 1024 * 1023;
ll dp[5007][5007];
string s,t;
 
ll func(ll ind1, ll ind2){
    if (ind1 == 0) return dp[0][ind2];
    if (ind2 == 0) return dp[ind1][0];
    if (dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    ll ans = INT_MAX;
    if (s[ind1-1]==t[ind2-1]){
        ans=min(ans,func(ind1-1,ind2-1));
        return dp[ind1][ind2] = ans;
    }
    else{
        ans=min(ans,func(ind1-1,ind2-1)+1);
        ans=min(ans,func(ind1,ind2-1)+1);
        ans=min(ans,func(ind1-1,ind2)+1);
        return dp[ind1][ind2] = ans;
    }
}
 
void solve(){
    cin>>s>>t;
    rep(i,0,s.size()+1){
        dp[i][0]=i;
    }
    rep(i,0,t.size()+1){
        dp[0][i]=i;
    }
    cout<<func(s.size(), t.size());
 
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
