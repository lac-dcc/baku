// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
 
using namespace std  ; 
 
vector<int> bfs(vector<vector<int>> adj,int n){
    vector<int> vis(n+1,0) ; 
    queue<int> q ; 
    vector<int> parent(n+1,-1); 
    bool found = false ; 
    vis[1]=1 ; 
    q.push(1); 
    while(!q.empty()){
     if(found == true ){
            break  ; 
        }
        int node = q.front();
        q.pop(); 
        vis[node]=1 ; 
        for(auto &itr : adj[node]){
            if(vis[itr]!=1){
                parent[itr] = node ; 
                vis[itr] = 1 ;
                q.push(itr); 
                if(itr==n){
                    found = true ; 
                }
            }
        }
        
        
    }
   // cout<<found ; 
    return parent ; 
}
void p(vector<int> parent,int n, int &count, vector<int> &ans){
    count = 1 ; 
    while(n!=1){
        ans.push_back(n); 
        n = parent[n]; 
        count++ ; 
        
    } 
    ans.push_back(1); 
}
int main() {
    // Write C++ code here
    int n, m ; 
    cin>> n>>m ; 
    vector<vector<int>> adj(n+1); 
    adj[0].push_back(0); 
    for(int i = 0; i < m; i++){
        int h, k ; 
        cin>> h >>k ; 
        adj[h].push_back(k); 
        adj[k].push_back(h); 
    }
    
    vector<int> ans = bfs(adj,n);
    //for(int i : ans){
    ///    cout<<i ; 
    //}
    if(ans[n]==-1){
        cout<<"IMPOSSIBLE"<<endl ; 
        
    }
    
    else{
        vector<int> comp; 
    int count = 0 ; 
    p(ans,n,count,comp); 
        cout<< count <<endl ; 
        for(int i=comp.size()-1; i>=0 ; i--){
            cout<< comp[i] << " "; 
        }
    }
 
    return 0;
}
