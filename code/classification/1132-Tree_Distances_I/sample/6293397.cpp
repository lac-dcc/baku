#include <iostream>
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
 
using namespace std;
 
ll mx=202020;
vector<ll>adj[202020];
ll subtree[202020];
 
void dfs(ll node,ll par,vector<ll>&distX)
{
  // ll cnt=1;
    if(par==-1)
    distX[node]=0;
    else
    distX[node]=distX[par]+1;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
           dfs(it,node,distX);
           //subtree[node]+=subtree[it];
        }
    }
   //  subtree[node]++;
}
void oreo()
{
   ll n;
   cin>>n;
   
   
   for(ll i=1;i<=n-1;i++)
   {
       ll x,y;
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
       
   }
   vector<ll>distX(n+1,0);
   dfs(1,-1,distX);
   
//   for(ll i=0;i<=n;i++)
//   cout<<distX[i]<<" ";
//   cout<<endl;
 
   ll y=0;
   for(ll i=1;i<=n;i++)
   {
      // cout<<distX[i]<<" "<<distX[y]<<" ";
       if(distX[i] > distX[y])
       {
          // cout<<i<<endl;
           y=i;
       
       }
   }
   //cout<<endl;
   //cout<<y<<endl;
   vector<ll>distY(n+1,0);
   dfs(y,-1,distY);
   ll z=0;
   for(ll i=1;i<=n;i++)
   {
       if(distY[i]>distY[z])
       z=i;
   }
   
   
   
   vector<ll>distZ(n+1,0);
   dfs(z,-1,distZ);
   
   for(ll i=1;i<=n;i++)
   cout<<max(distY[i],distZ[i])<<" ";
   cout<<endl;
   
   
   
   
    //   for(ll i=1;i<=n;i++)
    //   cout<<subtree[i]-1<<" ";
}
int main() {
	// your code goes here
		ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--)
	{
	    oreo();
	}
	
	return 0;
}
 
