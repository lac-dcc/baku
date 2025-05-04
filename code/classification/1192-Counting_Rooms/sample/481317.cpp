#include<bits/stdc++.h>
using namespace std;
char graph[1005][1005];
bool visited[1005][1005];
int n,m;
void dfs(int i,int j){
    visited[i][j]=true;
    //check up,down,left,right
    if(i-1>=0 && graph[i-1][j]=='.' && !visited[i-1][j])
        dfs(i-1,j);
    if(i+1<n && graph[i+1][j]=='.' && !visited[i+1][j])
        dfs(i+1,j);
    if(j-1>=0 && graph[i][j-1]=='.' && !visited[i][j-1])
        dfs(i,j-1);
    if(j+1<m && graph[i][j+1]=='.' && !visited[i][j+1])
        dfs(i,j+1);
 
}
int main() {
    cin>>n>>m;
    cin.get();
    memset(visited,false,sizeof(visited[0][0])*1005*1005);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>graph[i][j];
    }
 
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(graph[i][j]=='.' && !visited[i][j]){
                dfs(i,j);
                ans++;
            }
    }
    cout<<ans<<endl;
}
 
