//
//  main.cpp
//  buildingteam
//
//  Created by Yiran Hu on 6/26/22.
//
 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
const int SIZE=100001;
vector<int> adj[SIZE];
int color[100001];
int dis[100001];
bool visited[SIZE];
bool bipartite(){
    for(int i=1;i<=n;i++){
        if(color[i]!=0){
            continue;
        }
        color[i]=1;
        int d=1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int curr=q.front();
            q.pop();
            for(auto a:adj[curr]){
                if(color[a]==color[curr]) return false;
                if(color[a]==0){
                    color[a]=3-color[curr];
                    q.push(a);
                }
            }
            d++;
        }
        queue<int> q1;
        q1.push(i);
        while (!q1.empty()) {
            int curr=q1.front();
            q1.pop();
            for(auto a:adj[curr]){
                if(color[a]==color[curr]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(bipartite()){
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    
    return 0;
}
