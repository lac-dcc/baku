#include <bits/stdc++.h>
using namespace std;
 
int findDia(int i,vector<vector<int>> &adj,int &maxVal,vector<int> &visited){
    int m1=0,m2=0;
    visited[i]=1;
    for(int nbr:adj[i]){
        if(!visited[nbr]){
            int val=findDia(nbr,adj,maxVal,visited);
            if(val>=m1){
                m2=m1;
                m1=val;
            }
            else if(val>m2){
                m2=val;
            }
        }
    }
 
    int dia=1+m1+m2;
    if(dia>maxVal)
        maxVal=dia;
    return 1+m1;
 
}
 
int main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
 
    int u,v;
    vector<int> indeg(n+1,0),visited(n+1,0);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }
 
    int root=1;
    for(int i=1;i<=n;i++){
        if(indeg[i]==1){
            root=i;
            break;
        }
    }
    // for(int x: indeg)
    //     cout<<x<<" ";
    // cout<<endl;
 
    int maxVal=0;
    findDia(root,adj,maxVal,visited);
    cout<<maxVal-1;
 
}
