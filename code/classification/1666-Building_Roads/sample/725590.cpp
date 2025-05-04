#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <queue>
#include <map>
 
using namespace std;
 
int n, m, now = 0;
vector< vector<int> > g;
vector< vector<int> > mn;
vector<char> used;
 
void dfs(int x) {
	used[x] = true;
	mn[now].push_back(x);
	for (auto& i : g[x]) {
		if (!used[i]) dfs(i);
	}
}
 
int main() {
	cin >> n >> m;
	g.resize(n + 1);
	used.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			mn.push_back(vector<int>());
			dfs(i);
			now++;
		}
	}
	cout << mn.size() - 1 << endl;
	for (int i = 1; i < mn.size(); ++i) {
		cout << mn[i - 1][0] << ' ' << mn[i][0] << endl;
	}
}
