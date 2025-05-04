#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
const char dc[4]={'U','L','D','R'};
string s[1000];
bool valid(int i,int j){
    return i>=0&&j>=0&&i<n&&j<m&&s[i][j]=='.';
}
void dfs(int i,vector<int> adj[],vector<int>&vis){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
int main(){
    
   ll n,m;
   cin>>n>>m;
   vector<int>adj[n];
   for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      x--;y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   vector<int>vis(n,0);
   vector<int>ans;
   for(int i=0;i<n;i++){
    if(!vis[i]){
        ans.push_back(i);
        dfs(i,adj,vis);
    }
   }
   cout<<ans.size()-1<<endl;
   for(int i=1;i<ans.size();i++){
    cout<<ans[0]+1<<" "<<ans[i]+1<<endl;
   }
}
