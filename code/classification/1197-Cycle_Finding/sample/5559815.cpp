#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
 
	vector<vector<pair<int,int>>>adj(n+1);
	vector<vector<int>>edges;
 
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		edges.push_back({a,b,c});
 
	}
 
	bool flag;
	vector<int>d(n+1,1e18);
	d[1]=0;
	vector<int>parent(n+1,0);
	int vertex;
 
	for(int i=0;i<n;i++)
	{	
		flag =false;
		for(auto it:edges)
		{
			if(it[0]<1e18)
			{
				if(d[it[1]]>d[it[0]]+it[2])
				{
					flag =true;
					d[it[1]]=d[it[0]]+it[2];
					vertex=it[1];
					parent[it[1]]=it[0];
				}
			}
		}
	}
 
 
	if(!flag)
	{
		cout<<"NO"<<endl;
		return 0;
	}
 
	vector<int>ans;
	cout<<"YES"<<endl;
 
	for(int i=0;i<n;i++)
	{
		vertex=parent[vertex];
	}
 
	int temp=vertex;
 
	do
	{
		ans.push_back(temp);
		temp=parent[temp];
	}
	while(temp!=vertex);
 
	ans.push_back(vertex);
 
	reverse(ans.begin(),ans.end());
 
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
 
 
 
}
