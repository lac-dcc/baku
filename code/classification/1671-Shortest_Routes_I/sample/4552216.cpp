// Arise! Awake! and stop not until the goal is achieved
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
const ll INF = 1000000007;
const ll MOD = 998244353;
#define f(i,a,b) for(int i = a;i < b;i++)
#define frn(i,n) for(int i=0; i<n; i++)
#define endl            "\n"
#define decimal(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define FAST           ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
void solve(){
    int m, n;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    ll x,y,d;
    for(int i=0; i<m; i++){
        cin>>x>>y>>d;
        adj[x].push_back({y,d});
    }
    
    vector<ll> vis(n+1,1e18);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});
    pair<ll,int> pr;
    while(!pq.empty()){
        pr=pq.top(); pq.pop();
        x=pr.second;
        d=pr.first;
        if(vis[x]<=d) continue;
        vis[x]=d;
        for(pair<int,int> z:adj[x]){
            if(vis[z.first]>(d+z.second)){
                pq.push({d+z.second,z.first});
            }
        }
    }
    
    for(int i=1; i<=n; i++) cout<<vis[i]<<" ";
}
 
 
int main() {
  FAST;
  int t=1;
//   cin>>t;
  for(int i=1; i<=t; i++){
      solve();
  }
  return 0;
}
