#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define endl        "\n"
#define pi          pair<int,int>
#define ld          long double
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define vvi         vector<vector<int>>
#define vpi         vector<pair<int,int>>
#define rep(i,j,k)  for(int i=j; i<k; i++)
#define showvec(v)  for(auto it : v){cout << it << " ";}cout << endl;
#define IamSpeed    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
const int mod = 1e9+7;
const int INF = LLONG_MAX;
 
 
 
void solve(){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> adj[n+1];
        vector<bool> vis(n+1, false);
        rep(i,0,m){
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].pb({b, c});
        }
 
        //Dijkstra
        // priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //{distance, node}
        vector<int> res(n+1, INF);
        pq.push({0,1});
        // res[1] = 0;
        // vis[1] = true;
        while(pq.size()){
            int dist = pq.top().first;
            int node = pq.top().second;
            // cout << node << " " << dist << " " << endl;
            pq.pop();
            //we found the shortest path for 'node'
            if(vis[node]) continue;
            vis[node] = true;
            // res[node] = dist;
            res[node] = min(dist, res[node]);
            for(pair<int,int> child : adj[node]){
                if(dist + child.second < res[child.first]){
                    if(!vis[child.first]){
                        pq.push({(dist + child.second), child.first});
                        // vis[node] = true;
                    }
                }
            }
        }
 
        rep(i,1,n+1){cout << res[i] << " ";}
        cout << endl;
 
        // cout << INF << endl;
 
 
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    IamSpeed;
    int t = 1;
 
    // cin >> t; 
 
    while(t--){ solve(); }
 
    
    return 0;
}
