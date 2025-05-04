#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 1e18;
signed main()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector < vector<int> > s(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++)
    {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		if(w < s[u][v]) s[u][v] = s[v][u] = w;
	}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(s[i][k] + s[k][j] < s[i][j])
					s[i][j] = s[j][i] = s[i][k] + s[k][j];
	while (q--)
    {
		int u, v;
		cin >> u >> v, u--, v--;
		if(u == v) s[u][v] = 0;
		if(s[u][v] == INF) s[u][v] = -1;
		cout << s[u][v] << endl;
	}
}
