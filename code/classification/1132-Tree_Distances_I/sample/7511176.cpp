#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(),x.end()
 
vector<vector<int>> tree;
vector<int> d1,d2;
 
void dfs(int u,vector<int>& d,int p){
	for(int v : tree[u]){
		if(v != p){
			d[v] = d[u] + 1;
			dfs(v,d,u);
		}
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	tree.resize(n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	d1.resize(n);
	d2.resize(n);
	dfs(0,d1,0);
	int x = max_element(all(d1)) - d1.begin();
	dfs(x,d2,x);
	int y = max_element(all(d2)) - d2.begin();
	vector<int> d3(n);
	dfs(y,d3,y);
	for(int i = 0; i < n; i++){
		cout << max(d3[i],d2[i]) << ' ';
	}
}
