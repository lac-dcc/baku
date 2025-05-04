#include <bits/stdc++.h>
using namespace std;
using vl = vector<long long>;
using vvl = vector<vl>;
const long long INF=1e15;
 
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	vvl dist(n+1,vl(n+1,INF));
	for (int i=1; i<=n; i++) dist[i][i]=0;
	for (int i=1; i<=m; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if (c<dist[a][b]) dist[a][b]=c;
		if (c<dist[b][a]) dist[b][a]=c;
	}
	for (int k=1; k<=n; k++)
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if (dist[a][b]==INF) cout<<-1<<endl;
		else cout<<dist[a][b]<<endl;
	}	
}
