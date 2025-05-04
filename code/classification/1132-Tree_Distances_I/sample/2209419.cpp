#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back     
#define mp make_pair     
#define nline "\n"           
#define debug(x) cerr<<#x<<" = "<<x<<" "       
#define dnl cerr<<"\n"                       
const ll M=1e9+7;  
const ll N=200002;                    
#define f first          
#define s second                 
#define pll pair<ll,ll> 
vector<vector<ll>> adj;
vector<ll> ans(N,0);
vector<ll> lengthdown(N,0),lengthup(N,0);
vector<set<pll>> compare(N);
void dfs1(ll cur,ll par){
    for(ll chld:adj[cur]){
        if(chld==par)
            continue;
        dfs1(chld,cur);
        compare[cur].insert({lengthdown[chld]+1,chld}); 
        lengthdown[cur]=max(lengthdown[cur],lengthdown[chld]+1);
        ans[cur]=lengthdown[cur];
    }
    return;
}
void dfs2(ll cur,ll par){
    for(ll chld:adj[cur]){
        if(chld==par)
            continue;
        lengthup[chld]=lengthup[cur]+1; 
        if(compare[cur].size()>1){
            pll last=*(--compare[cur].end());  
            if(last.second==chld){
                last=*(--(--compare[cur].end())); 
                lengthup[chld]=max(lengthup[chld],1+last.first);
            }
            else
                lengthup[chld]=max(lengthup[chld],1+last.first);
        }
        ans[chld]=max(ans[chld],lengthup[chld]);
        dfs2(chld,cur);
    }
    return;
}
void solve(){          
    ll n; cin>>n;
    adj.resize(n+1);
    for(ll i=1;i<n;i++){
        ll u,v; cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return;
}
int main()                                 
{         
    ios_base::sync_with_stdio(false);                      
    cin.tie(NULL);                     
    #ifndef ONLINE_JUDGE          
    freopen("input.txt", "r", stdin);                                     
    freopen("output.txt", "w", stdout);  
    freopen("error.txt", "w", stderr);                        
    #endif    
    ll t=1;           
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
}                                
