#include<bits/stdc++.h>
#define ll int
using namespace std;
 
vector<ll> adj[200001];
map<ll,ll>mp;
vector<ll>depth(200001,0);
void Find_depth(ll src, ll par)
{
     ll ans=0;
     for(auto it : adj[src]) {
        if(it != par) {
            Find_depth(it, src);
            ans=max(ans,depth[it]);
        }
    }
    depth[src]=1+ans;
}
 
 
void solve(ll src, ll par,ll par_ans) {
    // Two possibilities: include root, exclude root
    vector<ll>pref,suff;
    int ans=0;
    for(auto it : adj[src]) {
        if(it != par) {
            pref.push_back(depth[it]);
            suff.push_back(depth[it]);
        }
    }
    ll n=pref.size();
    for(ll i=1;i<n;i++)
    {
        pref[i]=max(pref[i],pref[i-1]);
        
    }
    for(ll i=n-2;i>=0;i--)
    {
        suff[i]=max(suff[i],suff[i+1]);
    }
    ll childcnt=0;
    for(auto it:adj[src])
    {
        if(it!=par)
        {
            ll op1,op2;
            if(childcnt==0)
            {
                op1=0;
            }
            else
            op1=pref[childcnt-1];
            
            if(childcnt==suff.size()-1)
            {
                op2=0;
            }
            else
            op2=suff[childcnt+1];
            
            ll partial_ans = 1 + max(par_ans, max(op1,op2));
            solve(it,src,partial_ans);
            childcnt++;
        }
    }
    
    mp[src]=1+max(par_ans,(pref.size()==0?-1:pref.back()));
    
}
 
int main() {
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        ll n;
        cin >> n;
        for(ll i = 2; i <= n; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //we make root to 1 -> re-rooting 
        Find_depth(1,0);
        solve(1,0,0);
        for(ll i = 1; i <= n; i++)
        cout<<mp[i]-1<<" ";
        cout<<endl;
    }
    return 0;
}
