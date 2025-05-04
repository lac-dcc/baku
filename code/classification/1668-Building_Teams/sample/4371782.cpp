#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m;
bool vis[N];
vector<int> g[N];
int color[N];
 
bool dfs(int v,int c,int par)
{
	vis[v]=true;
	color[v]=c;
	for(auto child:g[v])
	{
		if(child==par) continue;
		if(color[child]==0)
		{
			if(!dfs(child,c^3,v)) return false;
		}
		if(color[child]==color[v]) return false;
	}
	return true;
}
 
 
 
bool color_all()// takin care of all connected components
{
	for(int i=1;i<=n;++i)
	{
		if(!vis[i]){
			if(!dfs(i,1,-1))
			{
				return false;
			}
		}
	}
	return true;
}
 
// void bfs(int v)
// {
// 	queue<int> q;
// 	q.push(v);
// 	vis[v]=true;
// 	while(!q.empty())
// 	{
// 		auto node = q.front();
// 		q.pop();
// 		for(auto child:g[node])
// 		{
// 			if(vis[child]) continue;
// 			vis[child]=true;
// 			q.push(child);
// 		} 
// 	}
// }
int main()
{
cin>>n>>m;
// color.resize(n);
for(int i=0;i<m;++i)
{
	int x,y;
	cin>>x>>y;
	g[x].push_back(y);
	g[y].push_back(x);
}
if(!color_all()) cout<<"IMPOSSIBLE"<<endl;
else{
	for(int i=1;i<=n;++i){
		cout<<color[i]<<" ";
	}
}
return 0;
}
