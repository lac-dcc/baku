#include<bits/stdc++.h>
using namespace std;
    
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    
#define fix(n,f) std::fixed<<std::setprecision(f)<<n
#define ll long long 
#define all(v) v.begin(),v.end()
#define nl "\n"
#define M 998244353 //1000000007 //
#define sum(a,b) ((a%M)+(b%M))%M
#define pro(a,b) ((a%M)*(b%M))%M
#define diff(a,b) ((a%M)-(b%M))%M
 
/*=================================== Bow to Lord Shiva  =================================*/
 
bool dfs(ll v,ll color,vector<vector<ll>> &g,vector<ll> &res){
    bool z=true;
    for(auto &child:g[v]){
        if(res[child]==-1){
            res[child]=3-color;
            z&=dfs(child,res[child],g,res);
        }
        else if(res[child]==color){
            return false;
        }
    }
    return z;
}
void solve() {
    ll n,m;cin>>n>>m;
    vector<vector<ll>> g(n+1);
    while(m--){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> res(n+1,-1);
    bool bl=true;
    for(ll i=1;i<=n;i++){
        if(res[i]==-1){
            res[i]=1;
            bl&=dfs(i,res[i],g,res);
        }
    }
    if(!bl){
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }
    for(ll i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<nl;
}
int main(){
    fastio();
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);
    int t=1;
    //cin>>t;
    for(int t1=1;t1<=t;t1++){
        solve();
    }
}
