/** 
 *    author:  pankaj_m05
 *    created: 28.09.2020 12:57:48
**/ 
#include<bits/stdc++.h>
 
using namespace std;
 
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> team(n, 0);
  while (m--) {
  	int u, v;
  	cin >> u >> v;
  	adj[u - 1].emplace_back(v - 1);
  	adj[v - 1].emplace_back(u - 1);
  }
  bool flag = 0;
  for (int i = 0; i < n; ++i) {
  	if (!team[i]) {
  		team[i] = 1;
  		queue<int> q;
  		q.emplace(i);
  		while (!q.empty()) {
  			int v = q.front();
  			int next = (team[v] % 2) + 1;
  			q.pop();
  			for (int& u : adj[v]) {
  				if (!team[u]) {
  					team[u] = next;
  					q.emplace(u);	
  				} else if (team[u] != next) {
  					flag = 1;
  					break;
  				}
  			}
  		}
  	}
  }
  if (flag) {
  	cout << "IMPOSSIBLE";
  } else {
  	for (int i = 0; i < n; ++i) {
  		cout << team[i] << ' ';
  	}
  }
  return 0;
}
