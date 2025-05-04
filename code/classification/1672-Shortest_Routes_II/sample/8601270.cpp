#include<bits/stdc++.h>
using namespace std;
#define int long long int
int roads[505][505];
int a,b,w;
int n,m,q;
int maxdist = ((int)1e9) * 500 + 5;
void printroads(){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << roads[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int32_t main()
{
	cin >> n >> m >> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) roads[i][j] = 0;
			else roads[i][j] = maxdist;
		}
	}
	for(int i=0;i<m;i++)
	{
		cin >> a >> b >> w;
		roads[a-1][b-1] = min(roads[a-1][b-1],w);
		roads[b-1][a-1] = min(roads[b-1][a-1],w);
	}
	//printroads();
	for(int k=0;k<n;k++) //start
	{
		for(int i=0;i<n;i++) //end
		{
			//if(i==j) continue;
			for(int j=0;j<n;j++) //intermediate
			{
				roads[i][j] = min(roads[i][j],roads[i][k]+roads[k][j]);
			}
		}
	}
	//printroads();
	for(int i=0;i<q;i++)
	{
		cin >> a >> b;
		if(roads[a-1][b-1]==maxdist) cout << -1 << '\n';
		else cout << roads[a-1][b-1] << '\n';
	}
}
