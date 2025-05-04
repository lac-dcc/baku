/*
China 21:46 ~ China
Submmisions
 
*/
#include "bits/stdc++.h"
using namespace std;
const int maxn = 510;
int n, m, q;
long long dist[maxn][maxn];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dist[i][j] = 1e18;
	for(int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(dist[a][b] > 1e17)
			printf("%d\n", -1);
		else
			printf("%lld\n", dist[a][b]);
	}
	return 0;
}
