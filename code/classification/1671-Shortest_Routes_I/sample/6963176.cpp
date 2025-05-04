#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first 
#define S second
#define ll long long
#define int ll
 
vector<vector<pair<int,int>>> arr;
vector<int> dist;
int n,m;
 
void solve(){
    cin>>n>>m;
 
    arr.clear();
    arr.resize(n+1);
    vector<bool> vis(n+1,false);
 
    dist.clear();
    dist.assign(n+1,1e18);
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({c,b});
    }
 
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    dist[1] = 0;
 
    while(!pq.empty()){
        pair<int,int> a = pq.top();
        pq.pop();
        if(vis[a.second]) continue;
        vis[a.second] = true;
        for(auto& it : arr[a.second]){
            if(dist[it.second] > it.first + dist[a.second]){
                dist[it.second] = it.first + dist[a.second];
                pq.push({dist[it.second],it.second});
            }
        }
    }
 
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
return 0;
}
