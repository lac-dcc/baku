#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+5],bef(n+5,-1);
    vector<bool>used(n+5,0);
    for(ll i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<ll>q;
    function <void(ll)> dfs=[&](ll x){
        for(auto y:adj[x]){
            if(!used[y]){
                used[y]=true;
                q.push(y);
                bef[y]=x;
            }
        }
    };
    used[1]=true;
    q.push(1);
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        dfs(x);
    }
    if(bef[n]==-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<ll>v;
    ll cur=n;
    v.pb(cur);
    while(cur!=1){
        v.pb(bef[cur]);
        cur=bef[cur];
    }
    cout<<v.size()<<"\n";
    for(ll i=v.size()-1;i>=0;i--){
        cout<<v[i]<<' ';
    }
}
