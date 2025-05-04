#include<bits/stdc++.h>
using namespace std;
 
vector<int> parent;
vector<int> visited;
vector<vector<int> > adj;
 
void bfs()
{
   queue<int> q;    
   q.push(0);
   visited[0]=1;
   while(!q.empty())
   {
     int topo=q.front();
     q.pop();
     for(auto i:adj[topo])
     {
        if(!visited[i])
        {
            parent[i]=topo;
            q.push(i);
            visited[i]=1;
        }
     }
   }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    parent.resize(n,-1);
    visited.resize(n,0);
    adj.resize(n);
 
    //now taking input edges
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bfs();
 
    stack<int> st;
    if(parent[n-1]==-1) 
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    else 
    {
        int cur=n-1;
        while(parent[cur]!=-1)
        {
            st.push(cur);
            cur=parent[cur];
        }
    }
    st.push(0);
    
    cout<<st.size()<<endl;
    while(!st.empty())
    {
        cout<<st.top()+1<<" ";
        st.pop();
    }
    return 0;
      
}
