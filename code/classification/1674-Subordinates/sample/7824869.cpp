#include <iostream>
#include <vector>
 
using namespace std;
 
const int N = 200005;
 
int n, used[N], cnt[N];
vector <int> g[N];
 
void dfs(int v){
	used[v] = 1;
	int children = 0;
	
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		
		if(used[to] == 1)
			continue;
		children++;
		dfs(to);
		cnt[v] += cnt[to];
	}
	cnt[v] += children;
}
 
int main(){
	cin >> n;
	for(int i = 2; i <= n; i++){
		int v;
		cin >> v;
		g[i].push_back(v);
		g[v].push_back(i);
	}
	dfs(1);
	
	for(int i = 1; i <= n; i++){
		cout << cnt[i] << " "; 
	}
}
