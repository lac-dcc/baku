#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define po pop_back
#define mp make_pair
#define fi first
#define se second
#define ull unsigned long long int
#define ll long long 
#define lli long long int
#define sort(a) sort(a.begin(),a.end())
 
 
//typedef pair<int,int> pii;
 
typedef pair<ll,ll> pll;
typedef vector<vector<int>>   vvi;
typedef vector<int>   vi;
typedef vector<ll>    vl;
//typedef vector<pii>   vpii;
typedef vector<pll>   vpll;
typedef pair<int,string>pi;
 
const int MOD = 1000000007;
 
 
/*ull nCr(ull n, ull r)
{
    if(n<r)return 0;
    if(n-r<r)
        r=n-r;
    vector<ull>arr(r+1,0);
    arr[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=r;j>=1;j--)
            arr[j]=(arr[j]+arr[j-1]);         //since backword going so new need of extra vector temp for last row dp
        
    return arr[r];
    
}*/
 
 
 
 
 
    
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>parent(n);
    vector<bool>visited(n,false);
     f(i,0,m)
     {
        cin>>u>>v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
     }
    queue<int>q;
    q.push(0);
    int dest=n-1;
    visited[0]=true;
    parent[0]=-1;
    visited[0]=true;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
                parent[v]=u;
            }
        }
    }
     
     if(!visited[n-1])
     {
         cout<<"IMPOSSIBLE\n";
         return 0;
     }
     vector<int>path;
     for(int v=dest;v!=-1;v=parent[v])
     {
          path.pb(v);
     }
     cout<<path.size()<<"\n";
     for(int i=path.size()-1;i>=0;i--)
     {
         cout<<path[i]+1<<" ";
     }
     return 0;
     
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*
//cses labyrinth
 void solve(vector<vector<char>>&v,pair<int,int>&s,pair<int,int>&d)
 {
     queue<pair<int,int>>q;
     vector<vector<bool>>visited(R,vector<bool>(C,false));
     vector<vector<int>>dist(R,vector<int>(C,0));
     vector<vector<char>>parent(R,vector<char>(C,'0'));
     visited[s.first][s.second]=true;
     q.push({s.first,s.second});
     while(!q.empty())
     {
         int r=q.front().first;
         int c=q.front().second;
         q.pop();
         for(int k=0;k<4;k++)
         {
             int rr=r+dr[k];
             int cc=c+dc[k];
             if(rr<0 || cc<0 || rr>=R || cc>=C || v[rr][cc]=='#' || visited[rr][cc])
                 continue;
             visited[rr][cc]=true;
             dist[rr][cc]=dist[r][c]+1;
             q.push({rr,cc});
             int x=rr-r;
             int y=cc-c;
             if(x==-1 && y==0)parent[rr][cc]='D';
             else if(x==1 && y==0)parent[rr][cc]='U';
             else if(x==0 && y==1)parent[rr][cc]='L';
             else if(x==0 && y==-1)parent[rr][cc]='R';
         }
     }*/
