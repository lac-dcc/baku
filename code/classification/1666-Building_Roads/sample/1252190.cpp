#include <bits/stdc++.h>
 
using namespace std;
const int mxN = 1e5;
string room[mxN];
int n, m;
vector<int> adj[mxN],scc;
bool vis[mxN];
 
void printAdj()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int j = 0; i < adj[i].size()-1; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
 
void dfs(int curr ){
    vis[curr]=true;
 
    for(int i :adj[curr]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
 
int main()
{   
  ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        --c1;
        --c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    for(int i =0;i<n;i++){
        if(!vis[i]){
            scc.push_back(i);
            dfs(i);
        }
    }
    cout<<scc.size()-1<<endl;
    for(int i =0;i<scc.size()-1;i++){
        cout<<scc[i]+1<<" "<<scc[i+1]+1<<endl;
    }
   
 
    return 0;
}
