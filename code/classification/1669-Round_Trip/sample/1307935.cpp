#include<bits/stdc++.h>
#define lld long long int
#define ulld unsigned long long int
typedef long long ll;
using namespace std;
int dfs(vector<int> arr[],vector<int> &vis,deque<int> &q,int parent,int source)
{
   vis[source]=1;
   q.push_back(source);
   for(auto i:arr[source])
   {
      if(vis[i]==0)
      {
          int f=dfs(arr,vis,q,source,i);
         if(f!=-1)
            return f;
      }
      else if(i!=parent)
      {
         while(!q.empty()&&q.front()!=i)
         {
            q.pop_front();
         }
         while(!q.empty()&&q.back()!=source)
         {
            q.pop_back();
         }
         return i;
      }
   }
   q.pop_back();
   return -1;
}
void solve(){
   lld n,m,ans=0;
   cin>>n>>m;
   vector<int> arr[n+1];
   for(int i=0;i<m;i++)
   {
     int a,b;
     cin>>a>>b;
     arr[a].push_back(b);
     arr[b].push_back(a);
   }
  vector<int> vis(n+1,0);
  for(int i=0;i<=n;i++)
      vis[i]=0;
  int flag=-1;
  deque<int> q;
  for(int i=1;i<=n;i++)
  {
      deque<int> q1;
      if(vis[i]==0)
      {
         flag=dfs(arr,vis,q1,-1,i);
         if(flag!=-1)
         {
            q=q1;
            break;
         }
      }
  }
  if(flag==-1)
  {
      cout<<"IMPOSSIBLE\n";
      return;
  }
  int f=0;
  while(!q.empty())
  {
      if(q.front()==flag&&f==0)
      {
         f=1;
         cout<<q.size()+1<<"\n";
      }
      if(f==1)
      {
         cout<<q.front()<<" ";
      }
      q.pop_front();
  }
  cout<<flag<<"\n";
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   t=1;
   //cin>>t;
   while(t--)
   { 
   solve();
   }
   return 0;
}
