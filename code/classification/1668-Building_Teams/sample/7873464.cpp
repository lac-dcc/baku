#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> team;
vector<int> par;
bool check = false;
void dfs(int node){
    vis[node] = true;
    for(auto i:adj[node]){
        if(vis[i] == false){
            par[i] = node;
            if(team[node] == 1)
                team[i] = 2;
            else if(team[node] == 2)
                team[i] = 1;
            dfs(i);
        }
        if(vis[i] == true && i != par[node] && team[i] == team[node])
            check = true;
    }
    return ;
}
int main(){
    int n,m;
    cin>>n>>m;
    adj = vector<vector<int>> (n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vis = vector<bool> (n, false);
    team = vector<int> (n, -1);
    par = vector<int> (n, -1);
    for(int i=0;i<n;i++){
        if(vis[i] == false){
            team[i] = 1;
            dfs(i);
        }
    }
    if(check == true)
        cout<<"IMPOSSIBLE"<<endl;
    else{
        for(auto i:team)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
