#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll
#define uint unsigned ll;
 
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(x) x.begin(),x.end()
#define len(x) ((int) x.size())
 
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
const int N = 2e5+10, INF = 1e18, MOD = 998244353;
typedef bitset<(N+63)/64*64> bits;
 
vector<vi> adj;
bits visited;
pi dfs(int v, int d=0) {
    visited[v]=1;
    pi ans={v,d};
    for(int u:adj[v]) {
        if(!visited[u]) {
            pi p=dfs(u,d+1);
            if(ans.second < p.second) ans=p;
        }
    }
    return ans;
}
 
void solve() {
    int n;
    cin>>n;
    adj.assign(n+1,vi());
    int v=1;
    rep(i,n-1) {
        int x,y;
        cin>>x>>y;
        v=y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pi p=dfs(v);
    visited.reset();
    cout<<dfs(p.first).second<<"\n";
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10);
    //int t; cin>>t; rep(_,t)
    solve();
}
