# include <bits/stdc++.h>
# define ll  long long
const ll N = 1e6;
using namespace std;
vector<int>depth(N,0);
 
void dfs1(vector<ll>adj[],ll ind,ll par)
{
	for(auto it:adj[ind])
	{
		if(it==par)continue;
		dfs1(adj,it,ind);
		depth[ind]=max(depth[ind],1+depth[it]);
	}		
}
 
void dfs(vector<ll>&ans,vector<ll>adj[],ll ind,ll par,ll par_ans)
{
  vector<ll>prefix,suffix;
  
  for(auto it:adj[ind])
  {
  	  if(it==par)continue;
  	  prefix.push_back(depth[it]);
  	  suffix.push_back(depth[it]);
  }
  
  for(int i=1;i<prefix.size();i++)
  prefix[i]=max(prefix[i],prefix[i-1]);
  
  for(int i=suffix.size()-2;i>=0;i--)
  suffix[i]=max(suffix[i],suffix[i+1]);
  
  ll c_no=0;
  for(auto it:adj[ind])
  {
  	if(it==par)continue;
  	 ll val1=(c_no==0)?(INT_MIN):prefix[c_no-1];
  	 ll val2=(c_no==suffix.size()-1)?(INT_MIN):suffix[c_no+1];
  	 ll anus=1+max(par_ans,max(val1,val2));
  	 dfs(ans,adj,it,ind,anus);
  	 c_no++;
  }
  
  ans[ind]=max((prefix.empty())?-1:1+prefix[prefix.size()-1],1+par_ans);
  
	
}
 
 
 
void solve()
{
   ll n;cin>>n;
   vector<ll>adj[n+1];
   vector<ll>ans(n+1);
   for(ll i=0;i<n-1;i++){
   	ll a,b;cin>>a>>b;
   	adj[a].push_back(b);
   	adj[b].push_back(a);
   }
   
   dfs1(adj,1,-1);
   dfs(ans,adj,1,-1,-1);
   for(ll i=1;i<=n;i++){
   	  cout<<ans[i]<<" ";
   }
   cout<<endl;  
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll t;t=1;
for(ll i=1;i<=t;i++)
{
solve();
}}
