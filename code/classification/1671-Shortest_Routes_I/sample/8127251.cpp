#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mod 1000000007
#define MAXN 100005;
#include <iomanip>
#define double long double
int M = 100011;
int N = 100011;
int fib[47];
#define ar array
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const int mxN = 1e5;
vector<ar<int,2>> graph[mxN];
int dist[mxN];
void solve() {
    
    int n,m;
    cin>>n>>m;
 
    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
 
        graph[u].push_back({v,w});
        
    }
    
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    pq.push({0,0});
    memset(dist,0x3f,sizeof(dist));
    dist[0] = 0;
 
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
 
        if(node[0] > dist[node[1]]) continue;
        for(auto child : graph[node[1]]){
            if(dist[child[0]] > node[0]+child[1]){
                dist[child[0]] = node[0]+child[1];
                pq.push({dist[child[0]],child[0]});
            }
        }
    }
 
    
    for(int i = 0;i<n;i++){
        cout<<dist[i]<<" ";
    }  
    cout<<endl;  
    return;
}  
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
 
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    // #endif
 
    int t;
    t=1;
    //cin>>t;
   // precompute();
    while(t--) solve(); 
}
