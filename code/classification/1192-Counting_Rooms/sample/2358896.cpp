
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ci(a) ll a; cin>>a;
#define fo(i,a,b)  for(ll i=a;i<b;i++)
#define MOD 998244353
 
#define call(type,var) type var; cin>>var; 
#define ci2(type,a,b)  type a,b; cin>>a>>b;
#define ci3(type,a,b,c)  ll a,b,c; cin>>a>>b>>c;
#define pb1(arr,k)  arr.push_back(k);  
#define print(arr) fo(i,0,arr.size()){ cout<<arr[i]<<" ";}cout<<endl;
#define printmap(ok) for(auto it:ok)cout<<it.first<<" "<<it.second<<endl;
#define printArr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" "; cout<<endl;
#define call(type,var) type var; cin>>var;
#define vect(type,arr,n) vector<type>arr; for(int i=0;i<n;i++){type j; cin>>j; arr.push_back(j);} 
#define setprecis(n) std::fixed<<std::setprecision(n)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define all(arr) arr.begin(),arr.end()
#define fi first
#define se second
#define vi vector<int>
#define vvi vector<vector<int>>
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define pb push_back
#define mp make_pair
#define msll multiset<ll>
#define pll pair<ll,ll> 
#define sll set<ll>
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>>
#define umap unordered_map<ll,ll>
#define msll multiset<ll>
#define pll pair<ll,ll> 
#define sll set<ll>
#define idk cout<<endl;
#define condition(ok)  if(ok){cout<<"YES"<<endl; } else cout<<"NO"<<endl;
#define debug(a) cout<<"element is "<<a<<endl;
#define debug2(a,b) cout<<"2 element is "<<a<<" "<<b<<endl;
#define debug3(a,b,c) cout<<"3 element is "<<a<<" "<<b<<" "<<c<<endl;
vector<pair<int,int>>movement={{0,1},{1,0},{0,-1},{-1,0}};
int n, m;
 
bool visited[1005][1005];
vector<string>str;
 
 
void dfs(int i,int j)
{
	visited[i][j]=true;
 
 
	for(auto it:movement)
	{
		if(!visited[it.first+i][it.second+j]&&it.first+i>=0&&it.first+i<n&&it.second+j>=0&&it.second+j<m&&str[it.first+i][it.second+j]!='#')
		{
			dfs(i+it.first,j+it.second);
 
		}
	}
 
 
}
 
 
int main()
{
 
 
	fastio()
cin>>n>>m;
 
	for(int i=0;i<n;i++)
	{
		call(string,temp)
		str.push_back(temp);
		
	}
 
 
 
ll ans=0;
 
 
multiset<pair<int,int>>helper;
 
 
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		if(str[i][j]=='.'&&!visited[i][j])
		{
			ans++;
 
			dfs(i,j);
 
 
		}
	}
}
 
 
 
 
cout<<ans<<endl;
 
 
 
 
 
 
}
