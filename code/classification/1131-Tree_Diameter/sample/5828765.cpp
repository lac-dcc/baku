#include <bits/stdc++.h>
using namespace std;
int dfs(int node,int parent,vector<int>adj[],int &ans){
    int mx1=0,mx2=0;
    for(auto x:adj[node]){
        if(x!=parent){
            int temp=dfs(x,node,adj,ans);
            if(temp>mx1){
               mx2=mx1;
               mx1=temp;
            }
            else if(temp>mx2){
                mx2=temp;
            }
        }
    }
    ans=max(ans,mx1+mx2);
    return 1+mx1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
       
    }
    int ans=0;
    dfs(0,-1,adj,ans);
    cout<<ans<<endl;
 
 
 
 
}
