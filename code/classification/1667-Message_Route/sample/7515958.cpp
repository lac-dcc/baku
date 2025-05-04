/*
Bhukya Tharun  |,,|
*/
 
#include<bits/stdc++.h>
 
#define endl "\n"
#define int long long
#define debug(x) cout<<#x<<": "<<x<<endl;
#define google cout<<"Case #" << tc << ": ";
 
using namespace std;
 
void solve(int tc)
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vector<int> visited(n+1,0);
    visited[1]=1;
    vector<int> parent(n+1,-1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:g[x]){
            if(visited[it]==0){
                q.push(it);
                visited[it]=1;
                parent[it]=x;
            }
        }
    }
    if(parent[n]==-1) {cout<<"IMPOSSIBLE"<<endl; return;}
    vector<int> ans;
    int x=n;
    while(x!=-1){
        ans.push_back(x);
        x=parent[x];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; 
    //cin>>t;
    for(int tc=1;tc<=t;tc++) solve(tc);
    return 0;
}
