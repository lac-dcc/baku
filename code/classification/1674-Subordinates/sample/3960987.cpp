#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
#define endl "\n"
#define nl "\n"
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define rev(p) reverse(p.begin(),p.end());
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define lb lower_bound
#define ub upper_bound
void dfs(ll node,ll par,vector<ll> &sz,vector<vector<ll>> &v){
        sz[node]=1;
    for(auto it:v[node]){
        if(it!=par){
            dfs(it,node,sz,v);
            sz[node]+=sz[it];
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    vector<vector<ll>> v(n+1);
    for(int i=2;i<=n;i++){
        ll x;
        cin>>x;
        v[x].pb(i);
    }
    //ll sz[n+1]={0};
    vector<ll> sz(n + 1, 0); 
    dfs(1,0,sz,v);
    for(int i=1;i<=n;i++){
        cout<<sz[i]-1<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<":"<<" ";
        solve();
    }
    return 0;
}
