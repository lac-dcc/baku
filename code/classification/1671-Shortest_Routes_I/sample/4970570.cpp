#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
vector<pair<int,ll>> node[200005];
priority_queue<pair<ll,int>> q;
bool vis[200005];
ll dist[200005];
ll INF = INT64_MAX;
 
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;ll c;cin>>a>>b>>c;
        node[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        int a = q.top().second;q.pop();
        if(vis[a])continue;
        vis[a]=1;
        for(pair<int,ll> neg:node[a]){
            int b=neg.first;ll w=neg.second;
            if(dist[b]>dist[a]+w){
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
}    
