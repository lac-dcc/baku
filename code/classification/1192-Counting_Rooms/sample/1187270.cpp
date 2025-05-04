#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
 
const int MAX = 1e3;
string s[MAX];
int n, m;
 
void dfs(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '#') return;
	s[i][j] = '#';
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
}
 
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
 
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '.') dfs(i, j), ans++;
		}
	}
	cout << ans << endl;
}
 
int main(){
	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
