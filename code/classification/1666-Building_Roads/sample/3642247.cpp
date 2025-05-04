#include <bits/stdc++.h>
#define pb push_back 
using namespace std;
int n, m;
bool used[200001];
vector <int> g[200001];
int ok = 0;
void dfs(int v){
	used[v] = 1;
	ok = v;
	for (auto to : g[v]){
		if(!used[to]){
			dfs(to);
			used[to] = 1;
		}
	}
}
int main(void){
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		int x, y;
		cin >>x >>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	vector <pair<int,int>> v;
	int ans = 0;
	int j = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++){
		if(!used[i]){
			dfs(i);
			j = ok;
			idx = i;
			break;
		}
	}
	for (int i = idx; i <= n; i++){
		if(!used[i]){
			ans++;
			dfs(i);
			v.pb({j , ok});
		}
	}
	cout << ans << endl;
	for (int  i = 0; i < v.size(); i++){
		cout << v[i].first<<" "<<v[i].second << endl;;
	}
	return 0;
}
