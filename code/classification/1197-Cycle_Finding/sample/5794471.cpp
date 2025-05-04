#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define v(li)  vector<ll>
#define vp(li)  vector<pair<ll, ll>>
#define m(li)  map<ll, ll>
#define s(li)  set<ll>
#define yes    cout<<"YES" <<endl
#define no     cout<<"NO" <<endl
#define ss     second
#define ff     first
#define f(i, n)   for (ll i = 0; i < n; i++)
#define nl        cout <<endl
#define vecsort(v)  sort(v.begin(), v.end())
#define pb          push_back
#define mk          make_pair
void fastio(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<ll> freq(ll a[],ll n){
    ll c=1;
    vector<ll> v;
    for(ll i=0;i<n-1;i++){
        if(a[i]==a[i+1])
        c++;
        else{
            v.push_back(c);
            c=1;
        }
    }
    v.push_back(c);
    return v;
}
vector<pair<ll,ll>> freqp(ll a[],ll n){
    ll c=1;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n-1;i++){
        if(a[i]==a[i+1])
        c++;
        else{
            v.push_back(make_pair(c,a[i]));
            c=1;
        }
    }
    v.push_back(make_pair(c,a[n-1]));
    return v;
}
ll power(ll a,ll b){
    if(b==0)
    return 1;
    ll res=power(a,b/2);
    if(b%2==0)
    return res*res;
    else
    return res*res*a;
}
ll powerm(ll a,ll b,ll M){
    if(b==0)
    return 1;
    ll res=powerm(a,b/2,M);
    if(b%2==0)
    return ((res%M)*(res%M))%M;
    else
    return (((res%M)*(res%M)%M)*(a%M))%M;
    
}
vector<vector<pair<ll,ll>>> v;
vector<ll> vis;
vector<ll> nc;
// bool dfs(ll i,ll par){
//     vis[i]=1;
//     nc.pb(i);
//     for(auto mm: v[i]){
//         if(!vis[mm.ff]){
//             dfs(mm.ff);
//         }
//         else if(par!=mm.ff){
 
//         }
//     }
//     nc.pop_back();
// }
 
int main(){
    fastio();
   ll n,m;
   cin>>n>>m;
   v.resize(n+1);
    vis.resize(n+1,0);
   f(i,m){
    ll x,y,w;
    cin>>x>>y>>w;
    v[x].pb({y,w});
   }
   ll dis[n+1];
  
   f(i,n+1) dis[i]=-1e18;
   dis[1]=0;
   ll par[n+1];
   ll z;
   f(i,n){
    z=-1;
    f(j,v.size()){
        f(k,v[j].size()){
            ll x=j;
            ll y=v[j][k].ff;
            ll w=v[j][k].ss;
            if(dis[y]>dis[x]+w){
                dis[y]=dis[x]+w;
                par[y]=x;
                z=y;
            }
        }
    }
   }
   if(z==-1){ no;
   }
   else{
    yes;
    v(li) ans;
    f(i,n){
        z=par[z];
    }
    ans.pb(z);
    int p=z;
    z=par[z];
    while(z!=p){
        ans.pb(z);
        z=par[z];
    }
    ans.pb(z);
    reverse(ans.begin(),ans.end());
    f(i,ans.size()) cout<<ans[i]<<" ";
    nl;
   }
}
