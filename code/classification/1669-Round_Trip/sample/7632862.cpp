#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(100000);
vector<int> ran(1000000,-1),p(1000000);
 
void dfs(int vert)
{
	for(auto child:v[vert])
	{
		if(child!=p[vert])
		{
			p[child]=vert;dfs(child);
		}
	}
}
 
int find(int u)
{
    if(ran[u]<0)return u;
    ran[u]=find(ran[u]);
    return ran[u];
}
bool merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)return false;
    if(ran[a]<ran[b])
    	swap(a,b);
    ran[b]+=ran[a];
    ran[a]=b;
    return true;
}
 
int main()
{
	int n,m;cin>>n>>m;
	vector<int> ans;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        if(merge(a,b))
        {
        	v[a].push_back(b);
        	v[b].push_back(a);
        }
        else
        {
        	dfs(a);
        	int u=b;
        	while(u!=0)
        	{
        		ans.push_back(u);
        		u=p[u];
        	}
        	int k=ans.size();
        	cout<<k+1<<endl;
        	for(int i=0;i<k;i++)
        	{
        		cout<<ans[i]<<" ";
        	}cout<<b;return 0;
        }
    }cout<<"IMPOSSIBLE";
	return 0;
}
