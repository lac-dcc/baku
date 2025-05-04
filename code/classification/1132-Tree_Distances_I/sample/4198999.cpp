#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int> >& graph,int node,vector<int>& level){
    int nd=node;
    queue<int> que;
    que.push(node);
    level[node]=0;
    while(!que.empty()){
        int top=que.front();
        que.pop();
        for(int x : graph[top]){
            if(level[x]==-1){
                level[x]=level[top]+1;
                que.push(x);
                nd=x;
            }
        }
    }
    return nd;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,u,v,node1,node2;
    cin>>n;
    vector<vector<int> > graph(n+1);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> level(n+1,-1),level2(n+1,-1),level3(n+1,-1);
    node1=solve(graph,1,level);
    node2=solve(graph,node1,level2);
    solve(graph,node2,level3);
    for(int i=1;i<=n;i++)cout<<max(level2[i],level3[i])<<" ";
    return 0;
}
