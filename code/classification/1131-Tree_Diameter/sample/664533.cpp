#include<bits/stdc++.h>
using namespace std;
int maxhei=0,node=1;
int dp[200005][2]={0};
void dfs(vector<vector<int>>&adj,vector<int>&vis,int i)
{   
    vis[i]=1;
    int m=0;
    vector<int>list;
    for(int u:adj[i])
    {   if(!vis[u])
        {
            dfs(adj,vis,u);
            m=max(m,dp[u][0]+1);
            list.push_back(dp[u][0]);
        }
    }
    dp[i][0]=m;    
    sort(list.begin(),list.end(),greater<int>());
    if(list.size()>1)dp[i][1]=2+list[0]+list[1];
    else if (list.size()==1)dp[i][1]=1+list[0];
}
int main()
{
 
cin.tie(0);
ios::sync_with_stdio(false);
int in,a,n;
cin>>n;
vector<vector<int>>adj(n+1);
vector<int>dist(n+1,0),vis(n+1,0);
for(int i=2;i<=n;i++)
{
    cin>>in>>a;
    adj[in].push_back(a);
    adj[a].push_back(in);
}
dfs(adj,vis,1);
int jp=0;
for(int i=1;i<=n;i++)
{  // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    jp=max(jp,dp[i][1]);
}
cout<<jp;
 
 
}
