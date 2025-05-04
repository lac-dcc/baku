#include<bits/stdc++.h>
using namespace std;
 
 
int fun(vector<int>adj[],int st,vector<int>&ans)
{
    if(adj[st].size()==0)
    return 1;
 
    for(int i=0;i<adj[st].size();i++)
    {
        ans[st]+=fun(adj,adj[st][i],ans);
    }
    return ans[st]+1;
}
 
int main(){
   int n;
   cin>>n;
   int arr[n-1];
   for (int i = 0; i < n-1; i++)
   {
        cin>>arr[i];
   }
   vector<int>adj[n+1];
   for (int i = 0; i < n-1; i++)
   {
    int u=arr[i];
    adj[u].push_back(i+2);
   }
   vector<int>ans(n+1,0);
   fun(adj,1,ans);
   for(int i=1;i<=n;i++)
   {
    cout<<ans[i]<<" ";
   }
 
   return 0;
}
