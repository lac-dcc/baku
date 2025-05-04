#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
int len=0;
typedef pair<ll,ll>ii;
typedef pair<ii,ll>iii;
int  n;
vector<iii>v;
ll dp[200044];
int bs(int l , int r ,ll x){
    if(l+10>=r){
        for(int i=l;i<=r;i++)if(v[i].first.first>x){return i;}
        return  n;
    }
    int mid=l+(r-l)/2;
    ll u=v[mid].first.first;
    if(u<x) return bs(max(0,mid-1),r,x);
    return bs(l,mid,x);
}
bool  op(iii &a,iii &b){
    if(a.first.first!=b.first.first)return a.first.first<b.first.first;
    else
    return  a.second>b.second;
}
ll cnt(int now){
    if(dp[now]+1)return dp[now];
    if(now==n)return 0;
    int x=bs(now+1,n-1,v[now].first.second);
    ll ans = 0;
    ans=cnt(now+1);
    ans=max(ans,cnt(x)+v[now].second);
    return dp[now]= ans;
}
int main()
{   ios::sync_with_stdio(0);
    cin>>n;
    ms(dp,-1);
    for(int i =0 ;i < n ; i++){
        ll x,y,z;
        cin>> x >> y >> z ;
        v.push_back(make_pair(make_pair(x,y),z));
    }
 
    sort(v.begin(),v.end());
 
    ll ans=0;
    ans=cnt(0);
    cout<<ans;
    return 0;
}
