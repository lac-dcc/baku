#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int visited[N];
int n;
int m;
int ciklus=0;
int start=0;
int End=0;
int P[N];
void dfs(int x,int cale){
    if(visited[x])return;
    visited[x]=1;
    P[x]=cale;
    for(auto it:adj[x]){
        if(it==cale)continue;
        if(visited[it]){
            ciklus=1;
            start=x;
            End=it;
            return;
        }
        dfs(it,x);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n&&!start;i++){
        if(!visited[i])dfs(i,0);
    }
    stack<int>s;
    for(int i=End;i!=start;i=P[i]){
        s.push(i);
    }
    s.push(start);
    if(!ciklus){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<s.size()+1<<" ";
    while(s.size()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<start;
}
