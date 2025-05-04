#include <bits/stdc++.h>
#define start         ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define int long long 
using namespace std;
 
 
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int n, m;
vector <pair<int, int>> adj[100005];
set <pair<pair<long long, int>, int>> st;
long long dist[100005][2];
bool vis[100005][2];
 
 
void dijkstra() {
    st.insert({{0, 0}, 1});
    vis[1][1] = 1;
    dist[1][1] = dist[1][0] = 0;
    while(!st.empty()) {
        long long dis = st.begin() -> first.first;
        int  left = st.begin() -> first.second, u = st.begin() -> second;
        st.erase(st.begin());
        //cout<<dis <<" "<<left <<" "<<u<<" ";
        if(vis[u][left]) continue;
        else vis[u][left] = 1;
        if(u == n) break;
        for(auto t: adj[u]) {
            int v = t.first, d = t.second;
            if(dist[v][left] > dis + d) {
                st.insert({{dis + d, left}, v});
                dist[v][left] = dis + d;
                //cout<<dis + d<<" "<<left<<" "<<v<<"\n";
            }
            if(left == 0) {
                if(dist[v][left + 1] > dis + d / 2) {
                    st.insert({{dis + d / 2, 1}, v});
                    dist[v][left + 1] = dis + d / 2;
                }
            }
        }
    }
}
 
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = 1e18;
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        //adj[b].push_back({a, c});
    }
    dijkstra();
    cout<<min(dist[n][0], dist[n][1]);
}
 
 
int32_t main()
{
    start
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
