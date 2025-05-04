#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define er erase
#define MP make_pair
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
typedef long long int ll;
using namespace std;
ll lcm(ll a,ll b){
   return (a*b)/__gcd(a,b);
}
bitset<100001>visited;
 
void dfs(ll n,vector<ll>adj[])
{
    visited[n]=1;
    for(ll child:adj[n])
    {
        if(!visited[child])
        {
            dfs(child,adj);
        }
    }
}
int main()
{
   fastio;
   ll n,m,a,b;
   cin>>n>>m;
   vector<ll>adj[n+1];
   for(ll i=0;i<m;i++)
   {
       cin>>a>>b;
       adj[a].PB(b);
       adj[b].PB(a);
   }
   ll sum=0;
   vector<ll>city;
   for(ll i=1;i<=n;i++)
   {
       if(!visited[i])
       {
           sum+=1;
           dfs(i,adj);
           city.push_back(i);
       }
   }
   cout<<sum-1<<endl;
   for(ll i=0;i<city.size()-1;i++)
   {
       cout<<city[i]<<' '<<city[i+1]<<"\n";
   }
   return 0;
}
