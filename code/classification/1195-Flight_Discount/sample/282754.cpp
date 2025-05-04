#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
vector <pair<int, long long>> adj[100001];
bool visited[100001][2];
long long cost[100001][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const long long INF = 1000000000000000000;
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		visited[i][0] = visited[i][1] = false;
		cost[i][0] =cost[i][1]= INF;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	priority_queue <pair<long long, int>> q;
	cost[1][0] = cost[1][1] = 0;
	q.push({ 0,1 });
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (visited[x][0])continue;
		//
		visited[x][0] = true;
		for (auto ad : adj[x]) {
			int i = ad.first;
			long long w = ad.second;
			if (cost[x][0] + w < cost[i][0]) {
				cost[i][0] = cost[x][0] + w;
				q.push({ -cost[i][0],i });
			}
		}
	}
	q.push({ 0, 1 });
	//for (int i = 1; i <= n; ++i)q.push({ -cost[i][0],i });
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (visited[x][1])continue;
		visited[x][1] = true;
		//cout << x << endl;
		for (auto ad : adj[x]) {
			int i = ad.first;
			long long w = ad.second;
			if (cost[x][0] + w/2 < cost[i][1]) {
				cost[i][1] = cost[x][0] + w/2;
				q.push({ -cost[i][1],i });
			}
			if (cost[x][1] + w < cost[i][1]) {
				cost[i][1] = cost[x][1] + w;
				q.push({ -cost[i][1],i });
			}
		}
	}
	cout << cost[n][1];
	return 0;
}
