/*
 
This Journey is interesting with obstacles ,and it's been always soothing as a result
 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(),v.end()
#define check(f) cout<<(f ? "Yes\n" : "No\n");
 
int val[200010];
 
int dfs(int node, vector<int> gr[] ){
	for(auto& i: gr[node]){
		val[node] += dfs(i, gr );
	}
	return val[node] + 1;
}
 
void solve(){
	int n; cin>>n;
	vector<int> gr[n+1];
	for(int i=2;i<=n;i++){
		int x; cin>>x;
		gr[x].push_back(i);
	}
	dfs(1, gr);
	for(int i=1;i<=n;i++){
		cout << val[i] << ' ';
	}
	cout << endl;
}
 
 
void io_fast(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}
 
signed main(){
	io_fast();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}
