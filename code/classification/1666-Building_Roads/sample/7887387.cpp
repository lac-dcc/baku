# include <bits/stdc++.h> 
 
using namespace std;
 
const int maxn = 1e5+6;
vector<int> a[maxn]; 
int mark[maxn];
 
void dfs(int v)
{
	//cout<<v<<" "<<mark[v]<<endl;	
	if (mark[v]) return ; 
	mark[v] = 1; 
	for (int  x : a[v]) dfs(x); 
}
 
int main() 
{
       ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin>>n>>m; 
	for (int i = 0; i<m;i++) 
	{
		int v,u;
		cin>>v>>u; 
		a[u].push_back(v); 
		a[v].push_back(u);
	}
	int c = 0,ans=0;
	vector<int> v;
	for (int i =1;i<=n;i++) 
	{
		if (!mark[i]) 
		{
			ans++; 
			v.push_back(i);
			dfs(i);
		}
	}
	cout<<ans-1<<endl;
	for (int i = 0; i<v.size()-1;i++) cout<<v[i]<<" "<<v[i+1]<<endl; 
	
	
}
 
 
 
