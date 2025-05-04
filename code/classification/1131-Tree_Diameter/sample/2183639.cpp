#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
#define pb push_back
#define f first
#define s second
 
void fastIO () {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}
 
const int MAXN = 2e5;
 
vector<int> adj[MAXN];
int best = -1, furthestNode;
 
void DFS(int node, int father, int length) {
	length++;
	if(length > best) {
		best = length;
		furthestNode = node;
	}
	for(auto x: adj[node]) {
		if(x != father) {
			DFS(x,node,length);
		}
	}
}
 
int main() {
	fastIO();
 
	int n;
	cin >> n;
 
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	DFS(0,-1,-1);
	DFS(furthestNode,-1,-1);
 
	cout << best << endl;
	return 0;
}
