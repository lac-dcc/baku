#include<bits/stdc++.h>
#define f(i,n) for(long long int i = 0 ; i < n;  i++)
#define F first
#define S second
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define all(s) s.begin(), s.end()
#define u_s unordered_set
#define u_m unordered_map
#define ll long long int
#define pb push_back
#define pll pair<ll,ll>
#define parr(arr) for(auto x: arr)cout<<x+1<<" ";cout<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define testcase ll tt; cin>>tt; while(tt--)
using namespace std;
 
const int maxi = 2500;
 
vll dist(maxi, INT_MAX), par(maxi,-1);
 
void solve(){
    ll n, m; cin>>n>>m;
    vector<array<ll,3>> edges;
    f(i,m){
        ll a, b, c; cin>>a>>b>>c; a--, b--;
        edges.pb({a,b,c});
    }
    dist[0] = 0;
    for(ll i = 0; i <= n; i++){
        bool any = 0;
        for(ll j = 0; j < m; j++){
            if(dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2]){
                par[edges[j][1]] = edges[j][0];
                if(i == n){
                    vll vis(maxi);
                    ll node = edges[j][0];
                    while(!vis[node]){
                        vis[node] = 1;
                        node = par[node];
                    }
                    vll ans; ans.push_back(node);
                    ll p = par[node];
                    while(p^node){
                        ans.push_back(p);
                        p = par[p];
                    }
                    ans.push_back(node);
                    cout<<"YES"<<endl;
                    reverse(all(ans)); parr(ans);
                    return;
                }
                dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                any = 1;
            }
        }
        if(!any) break;
    }
    cout<<"NO";
}
 
int main() {
    fast;
    solve();    
	return 0;
}
