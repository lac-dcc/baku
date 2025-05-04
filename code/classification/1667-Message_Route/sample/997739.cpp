
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(p,n) for(int i=p;i<n;i++)
#define FIO ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define mod 1000000007
 
int main()
{
    FIO
    int n,m;
    cin>>n>>m;
   vector<int> v[n+1];
   fo(0,m)
   {
       int x,y;
       cin>>x>>y;
       v[x].pb(y);
       v[y].pb(x);
   }
   int k=-1;
   queue<int> q;
   q.push(1);
   int from[n+1],dis[n+1];
   from[1]=0;
   dis[1]=1;
   bool vis[n+1];
   for(int i=0;i<=n;i++)
   vis[i]=false;
   vis[1]=true;
   while(!q.empty())
   {
       int node=q.front();
       q.pop();
       if(node==n)
       {
           k=1;
           break;
       }
       for(int i=0;i<v[node].size();i++)
       {
           if(vis[v[node][i]]==false)
           {
               vis[v[node][i]]=true;
               q.push(v[node][i]);
               from[v[node][i]]=node;
               dis[v[node][i]]=dis[node]+1;
           }
       }
   }
   if(k==-1)
   {
       cout<<"IMPOSSIBLE\n";
   }
   else
   {
       cout<<dis[n]<<endl;
       stack<int> s;
       while(n!=0)
       {
           s.push(n);
           n=from[n];
       }
       while(!s.empty())
       {
           cout<<s.top()<<" ";
           s.pop();
       }
       
   }
}
