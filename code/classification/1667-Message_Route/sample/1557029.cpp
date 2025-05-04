#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
const int mxn = 1e5;
vector<int> adj[mxn],ans;
bool vis[mxn];
int p[mxn];
int main()
{
	memset(vis,false,sizeof(vis));
	cin >> n >> m;
	for(int i = 0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		--a,--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(p,-1,sizeof(p));
	queue<int> q;
	q.push(0);
	p[0] = -2;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : adj[u])
		{
			if(p[v]<0)
			{
				p[v] = u;
				q.push(v);
			}
		}
	}
	
	if(p[n-1]<0)
	   cout << "IMPOSSIBLE" << endl;
	else
	  {
	  	int u = n-1;
	  	while(u)
	  	{
	  		ans.push_back(u);
	  		u = p[u];
	  	}
	  	ans.push_back(0);
	  	reverse(ans.begin(),ans.end());
	  	cout << ans.size()<< endl;
	  	for(auto i : ans)
	  	{
	  		cout << i+1 << " ";
	  	}
	  	cout << endl;
	  }   
}
