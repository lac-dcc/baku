#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>edges;
	vector<int>relax(n + 1, 0);
	vector<long long>dist(n + 1, 0);
	vector<long long>fre(n + 1, 0);
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back({ x,y,z });
	}
	int x = -1;
	for (int i = 0; i < n*2; ++i) {
		for (auto comp : edges) {
			int u = comp[0];
			int v = comp[1];
			int weight = comp[2];
			if (i < n-1) {
				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
				}
			}
			else {
				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					relax[v] = u;
					x = v;
				}
			}
		}
	}
	if (x == -1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i <2*n; ++i) {
			x = relax[x];
		}
		vector<int>ans;
		int p = x;
		ans.push_back(x);
		x = relax[x];
		while (p!=x) {
			ans.push_back(x);
			x = relax[x];
		}
		ans.push_back(x);
		reverse(ans.begin(), ans.end());
		for (auto it : ans) cout << it << " ";
	}
}
