#include <bits/stdc++.h>
 
using namespace std;
 
int visited[1005][1005];
vector<pair<int,int>>adj[1005][1005];
 
void dfs(int n,int m)
{
    if(visited[n][m] == 1)
        return;
 
    visited[n][m] = 1;
 
    for(auto p:adj[n][m])
        dfs(p.first,p.second);
}
 
int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
 
    char c[n+2][m+2];
    vector<pair<int,int>>v;
 
    for(int j=0;j<m+2;j++)
        c[0][j]='#';
 
    for(int i=1;i<=n;i++){
        c[i][0]='#';
 
        for(int j=1;j<=m;j++)
            cin>>c[i][j];
 
        c[i][m+1]='#';
    }
 
    for(int j=0;j<m+2;j++)
        c[n+1][j]='#';
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j] == '.'){
                if(c[i][j+1]=='#' && c[i][j-1]=='#' && c[i-1][j]=='#' && c[i+1][j]=='#'){
                    cnt++;
                    continue;
                }
 
                v.push_back({i-1,j-1});
 
                if(c[i][j+1] == '.'){
                    adj[i-1][j-1].push_back({i-1,j});
                    adj[i-1][j].push_back({i-1,j-1});
                }
 
                if(c[i+1][j] == '.'){
                    adj[i-1][j-1].push_back({i,j-1});
                    adj[i][j-1].push_back({i-1,j-1});
                }
 
            }
        }
    }
 
    for(auto p:v){
        if(visited[p.first][p.second] == 0){
            cnt++;
            dfs(p.first,p.second);
        }
    }
 
    cout<<cnt<<"\n";
 
    return 0;
}
