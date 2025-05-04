//linkedin.com/in/gaurav-golchha-745713206
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long int
#define llu long long unsigned int
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pi pair<int,int>
#define pii pair<int,pair<int,int>>
#define pb push_back
#define popb pop_back
#define cnt continue
#define FOR(n) for(int i=0;i<n;i++)
#define RFOR(n) for(int i=n;i>=0;i--)
#define f(i,a,n) for(int i=a;i<n;i++)
#define rf(i,a,n) for(int i=a;i<=n;i++)
#define all(x)   x.begin(),x.end()
#define allg(x)  x.begin(),x.end(),greater<int>()
using namespace std;
const int N=1e6+10;
bool check = false;
int ct = 0;
void dfs(int ind,int parent,int n,int smallest,vector<vector<int>>&adj,vector<int>&currstack,vector<int>&vis){
 vis[ind] = 1;
 currstack.pb(ind);
 if(ind == n-1){
    //  cout<<currstack.size()<<" "<<smallest<<"\n";
     if(currstack.size() == smallest)
     {
        check = true;
        return;
     }
     vis[ind]=0;
    //  for(auto x:currstack) cout<<x<<" ";
    //  cout<<"\n";
     currstack.pop_back();
     return;   
 }
 for(auto x:adj[ind]){
    if(x == parent) continue;
    if(vis[x]) continue;
    dfs(x,ind,n,smallest,adj,currstack,vis);
    if(check) return;
 }
 vis[ind] = 0;
 currstack.pop_back();
}
void solve(){
     int n,m;
     cin>>n>>m;
     vector<vector<int>>adj(n);
     FOR(m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
     }
     vector<int>dist(n,INT_MAX);
     dist[0] = 1;
     queue<int>q;
     q.push(0);
     vector<int>parent(n,-1);
     while(!q.empty()){
        int ind = q.front();
        int currdist = dist[ind] + 1;
        q.pop();
        for(auto x:adj[ind]){
            if(dist[x]>currdist){
                dist[x] = currdist;
                q.push(x);
                parent[x] = ind;
            }
        }
     }
     if(dist[n-1]==INT_MAX){
        cout<<"IMPOSSIBLE";
        return;
     }
     int smallest = dist[n-1];
     cout<<smallest<<"\n";
     vector<int>path;
     int node = n-1;
     while(parent[node]!=0){
        path.pb(node);
        node = parent[node];
     }
     path.pb(node);
     path.pb(0);
     reverse(all(path));
     for(auto x:path) cout<<x+1<<" ";
}
signed main(){
fast
int t = 1;
// cin>>t;
while(t--){
    solve(); 
}
 return 0;
}
