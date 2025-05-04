#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define cina(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define couta(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<' ';}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ump unordered_map
#define pb push_back
#define ust unordered_set
#define HOWDY ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define maxa *max_element
#define mina *min_element
#define pct(x) __builtin_popcount(x)
#define ff(i,z,n) for(ll i=z;i<n;i++)
#define bf(i,z,n) for(ll i=z;i>=n;i--)
void kar()
{
ll n;
cin>>n;
ll ans=0;
map<ll,ll> m;
ff(i,0,n){
ll l,r;
cin>>l>>r;
m[l]++;
m[r+1]--;
}
ll tp=0;
for(auto it:m){
tp=it.second+tp;
ans=max(ans,tp);
}
cout<<ans;
}
int main()
{
HOWDY;
int t=1;
while(t--){kar();}
return 0;
}
