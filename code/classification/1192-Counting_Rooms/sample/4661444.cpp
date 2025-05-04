/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
void dfs(vector<string> &mp,vector<vector<int>>& vis, int x,int y,int n,int m){
    if(x <0 || y < 0) return;
    if(x>=n || y>=m) return; 
    if(mp[x][y]== '#') return;
    if(vis[x][y]) return;
    
    vis[x][y]=1;
    
    dfs(mp,vis,x+1,y,n,m);
    dfs(mp,vis,x-1,y,n,m);
    dfs(mp,vis,x,y+1,n,m);
    dfs(mp,vis,x,y-1,n,m);
    
}
int main()
{
    int n,m;
    cin >> n >> m;
    
    vector<string> vc(n);
    for(auto &el: vc) cin >> el;
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    
    
    int cnt = 0;
    
    for(int i = 0;i < n;i++){
        for(int j = 0 ;j < m;j++){
            if(!vis[i][j] && vc[i][j]!= '#'){
                cnt++;
                dfs(vc,vis,i,j,n,m);
            }
        }
    }
    cout << cnt <<endl;
 
}
