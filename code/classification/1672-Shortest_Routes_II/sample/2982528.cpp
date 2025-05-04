#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <set>
#include <fstream>
#include <bits/stdc++.h>
# define int long long
using namespace std;
long long INF=1e18;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int> > edges(n+1, vector<int>(n+1));
	vector<vector<int> > dist(n+1, vector<int>(n+1));
	for(int i=0; i<m; i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edges[a][b]=w;
		edges[b][a]=w;
		if(!dist[a][b])
		{ 
			dist[a][b]=w;
		}
		else
		{
			dist[a][b]=min(w,dist[a][b]);
		}
		if(!dist[b][a])
		{ 
			dist[b][a]=w;
		}
		else
		{
			dist[b][a]=min(w,dist[b][a]);
		}
	
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i==j)
			{ 
				dist[i][i]=0;
			}
			else if(!dist[i][j])
			{
				dist[i][j]=INF;
			}
		}
	}
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(dist[i][k]==INF || dist[k][j]==INF) continue;
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=0; i<q; i++)
	{
		int a,b;
		cin>>a>>b;
		if(dist[a][b]==INF)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<dist[a][b]<<endl;
		}
	}
	return 0;
}
