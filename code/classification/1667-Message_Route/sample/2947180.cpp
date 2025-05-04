#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);cout.tie(nullptr);
 
        int n, m;
        cin >> n >> m;
        vector<int> adj[100005];
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a>> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // bfs
        queue<pair<int,int>> q;
        q.push({1,0});
        bool yes = false;
        int dp[100005], vis[100005];
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second;
            if(node==n){
                yes = true;
                break;
            }
            q.pop();
            for(int now : adj[node]){
                if(vis[now]==0){    
                    q.push({now,dist+1});
                    vis[now]=1;
                    dp[now]=node;
                }
            }
        }
        if(yes == true){
            cout << q.front().second+1 << "\n";
            vector<int> path;
            int fd=n;
            while(fd!=-1){
                path.push_back(fd);
                fd=dp[fd];
            }
            reverse(begin(path),end(path));
            for(int x : path){
                cout << x << " ";
            }
        }else{
            cout << "IMPOSSIBLE\n";
        }
        return 0;
}
