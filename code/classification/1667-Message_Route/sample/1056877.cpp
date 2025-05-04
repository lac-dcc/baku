#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<bool> visited(n+1,false);
    map<int,int> parent;
    queue<int> q1;
    q1.push(1);
    visited[1]=true;
    while(!q1.empty()){
        int node = q1.front();
        if(node==n)
            break;
        q1.pop();
        // cout<<node<<endl;
        for(int child:graph[node]){
            if(!visited[child]){
                parent[child]=node;
                visited[child]=true;
                q1.push(child);
            }
        }
    }
    if(parent[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        int i=n;
        vector<int> res;
        while(i!=1){
            res.push_back(i);
            i=parent[i];
        }
        res.push_back(1);
        cout<<res.size()<<endl;
        reverse(res.begin(),res.end());
        for(int i:res){
            cout<<i<<" ";
        }
    }
    
}
