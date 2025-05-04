#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
typedef long long int ll;
typedef double dd;
const ll MOD = 1e9 + 7;
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<int> ans;
bool dfs(vector<pair<int,int>> adj[], int ind, int parent, ll weights, vector<int> &vis, vector<int> &temp){
    vis[ind] = 1;
 
    for(auto it: adj[ind]){
        if(!vis[it.f]){
            vis[it.f] = 1;
            temp.push_back(it.f);
            if(dfs(adj,it.f,ind,weights+it.s,vis,temp)) return 1;
            temp.pop_back();
        }
        else if(it.f!=parent){
            if(weights+it.s<0){
                temp.push_back(it.f);
                ans.push_back(it.f);
                for(int i=0;i<temp.size();i++) ans.push_back(temp[i]);
                return 1;
            }
        }
    }
    return 0;
}
 
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edge;
    for(int i=0;i<m;i++){
        int v,u,w;cin>>v>>u>>w;
        u--,v--;
        edge.push_back({v,u,w});
    }
 
    vector<int> ancestor(n,0);
    vector<ll> dist(n,1e17);
    dist[0] = 0;
    int x;
    for(int i=0;i<n;i++){
        x = -1;
        for(int j=0;j<m;j++){
            if(dist[edge[j][0]]+edge[j][2] < dist[edge[j][1]]){
                dist[edge[j][1]] = dist[edge[j][0]]+edge[j][2];
                ancestor[edge[j][1]] = edge[j][0];
                x = edge[j][1];
            }
        }
    }
 
    if(x==-1){
        cout<<"NO"<<endl;
    }
    else{
        for(int i=0;i<n;i++) x = ancestor[x];
        vector<int> cycle;
        for (int v = x;; v = ancestor[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout<<"YES"<<endl;
        for (int v : cycle)
            cout << v + 1<< ' ';
        cout << endl;
    }
    return 0;
}
