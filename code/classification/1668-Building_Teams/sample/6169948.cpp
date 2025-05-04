#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=2e5+10;
vector<int>adj[N];
vector<int>ans;
int visited[N],par[N];
int n,m;
 
//cycle odd length hoilw bicolour kra jabena
 
 
 
 /*void dfs(int x,int y)
 {
 
     if(x<0||x>=n)return;
     if(y<0||y>=m)return;
     if(arr[x][y]=='#')return;
     arr[x][y]='#';
     //cout<<x<<" "<<y<<endl;
     int dr[]={0,-1,0,1};
     int dc[]={1,0,-1,0};
     for(int i=0;i<4;i++)
     {
         dfs(x+dr[i],y+dc[i]);
     }
 }*/
//int dist[N];
int x=1;
void dfs(int u)
{
    if(visited[u]>0)return;
 
    visited[u]=x;
    if(x==1)x=2;
    else x=1;
    for(int it:adj[u])
    {
        if(visited[it]==0)
        dfs(it);
    }
}
void bfs(int u)
{
    bool flag=0;
    queue<int>q;
    q.push(u);
    visited[u]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
 
 
        for(auto it:adj[f])
        {
            if(visited[it]>0)continue;
            if(visited[f]==1)x=2;
            else x=1;
            visited[it]=x;
 
            par[it]=f;
            q.push(it);
 
 
        }
    }
}
int main()
{
    /*int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        dfs(i,0);
        memset(visited,0,sizeof(visited));
        int x=*max_element(dist,dist+n);
        mx=max(mx,x);
    }
    cout<<mx<<endl;
    */
 
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    if(visited[i]==0)
    bfs(i);
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        for(auto it:adj[i])
        {
            if(visited[it]==visited[i]){
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    if(flag==1)cout<<"IMPOSSIBLE"<<endl;
    else{
    for(int i=1;i<=n;i++){
        cout<<visited[i]<<" ";
    }
    }
   // cout<<endl;
 
}
/*11
1 2
1 3
3 4
3 5
3 6
5 7
5 8
6 10
10 11
8 9
*/
