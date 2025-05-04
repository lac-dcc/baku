#include <bits/stdc++.h>
using namespace std;
 
bool dfs(vector<int>adj[],vector<int>&color,int n,int i,int c)
{
    color[i]=c;
    for(auto it:adj[i])
{
    if(color[it]==-1)
    {
        if(dfs(adj,color,n,it,!c)==false)
        {
            return false;
        }
        // else if (color[it] == c) {
        //     return false;
        // }    
    } 
}
 for (auto it : adj[i]) {
        if (color[it] == color[i]) {
            return false;
        }
    }
    return true;
 
}
 
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];               
    //vector<int>adj(n+1);            
    // vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);        
    }
    vector<int> color(n+1,-1);
    int flag=-1;
    for(int i=1;i<=n;i++)
    {
        // cout<<color[i]<<" ";
        if(color[i]==-1)
        {
            //0 hai initial color
            bool k=dfs(adj,color,n,i,0);
            // cout<<k<<endl;
            if(k==false)
            {
                cout<<"IMPOSSIBLE"<<endl;
               
                return 0;
            }
        }
    }
    // cout<<"poss"<<endl;
    for(auto it:color)
    {
        if(it!=-1)
        {cout<<it+1<<" ";}
    }
    cout<<endl;
 
 return 0;
}
