// sgn
// os 
 
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define ll long long int
#define pb push_back
#define M 1000000007
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define si(x) (int)x.size()
 
vector<vector<int>>moves = {{-1,0}, {1,0}, {0,1}, {0,-1}};
vector<char> move_char = {'U', 'D', 'R', 'L'};
vector<vector<int>>v(200005);
 
bool isValid(int x, int y, int n, int m) {
	if(x < 0 or x >= n or y < 0 or y >= m) return false;
	return true;
}
 
void dfs2(int x, vector<int>&vis) {
	vis[x] = 1;
	for(auto it : v[x]) {
		if(vis[it] == -1) {
			dfs2(it, vis);
		}
	}
}
 
void dfs(int x, int y, vector<vector<char>>&v, vector<vector<int>>&vis) {
	vis[x][y] = 1;
	int n = v.size(), m = v[0].size();
	for(auto it : moves) {
		int ux = it[0] + x, uy = it[1] + y;
		if(isValid(ux, uy, n, m) && vis[ux][uy] == 0 && v[ux][uy] == '.') {
			dfs(ux, uy, v, vis);
		} 
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test_input.txt","r",stdin);
    // freopen("test_output.txt","w",stdout);
	int t = 1;
	// cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int x, y;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			v[x].pb(y);
			v[y].pb(x);
		}	
		vector<int>vis(n+1, -1);
		vector<int>vv;	
 
		queue<int>q;
		q.push(1);
		vis[1] = 1;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto it : v[u]) {
				if(vis[it] == -1) {
					q.push(it);
					vis[it] = u;
				}
			}
		}
		if(vis[n] == -1) cout << "IMPOSSIBLE";
		else {
			vector<int>v_ans;
			while(n != 1) {
				v_ans.pb(n);
				n = vis[n];
			}
			v_ans.pb(1);
			reverse(all(v_ans));
			cout << v_ans.size() <<  "\n";
			for(auto it : v_ans) cout << it << " ";
		}
		// cout << "\n";
	}
	return 0;
}
