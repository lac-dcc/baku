#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for(int i=a; i<=b; i++)
#define REPr(i,a,b) for(int i=a; i>=b; i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
const int mod =1e9+7;
const ll inf= 1e17;
const ll ninf= -1e17;
 
 
 
 
int main(){
    fast;
    ll n,m; cin>>n>>m;
    vector<vector<ll>>A;
    REP(i,0,m-1){
        ll a,b,w;
        cin>>a>>b>>w;
        A.pb({a,b,w});
    }
    vector<ll> dis(n+1);
    vector<ll> par(n+1);
    ll x=-1;
    REP(i,1,n){
        x=-1;
        for(auto e: A){
            ll u=e[0];
            ll v=e[1];
            ll w=e[2];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                par[v]=u;
                x=v;
            }
        }
    }
    if(x==-1){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        REP(i,1,n){
            x=par[x];
        }
        vector<ll> ans;
        ans.pb(x);
        ll t=par[x];
        while(t!=x){
            ans.pb(t);
            t=par[t];
        }
        ans.pb(x);
        reverse(ans.begin(),ans.end());
        for(auto x: ans){
            cout<<x<<" ";
        }
 
 
    }
 
 
    
 
 
    
 
}
