#include <bits/stdc++.h>
using namespace std;
#define MAXN 202020
vector<vector<int>> adj(MAXN);
vector<int>subtree_size(MAXN);
int calc (int node) {
if (adj[node].size() == 0) {
return 1;
} else {
for (int i = 0; i < adj[node].size(); i++) {
subtree_size[node] += calc(adj[node][i]);
}
}
return subtree_size[node] + 1;
}
int main() {
int n;
int a1=0;
cin >> n;
for (int i = 2; i <= n; i++) {
int boss;
cin >> boss;
adj[boss].push_back(i);
}
calc(1);
for (int i = 1; i <= n; i++) {
cout << subtree_size[i] << " ";
}
return 0;
}
