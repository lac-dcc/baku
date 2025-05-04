/**
 *   ^~^  ,
 *  ('Y') )
 *  /   \/ 
 * (\|||/)
**/
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <numeric>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std; 
 
#define ll long long
 
void debug(vector<int> x){
	cout << "\n";
	for (int i = 0; i < x.size(); i++){
		cout << x[i] << " ";
	}
	cout << "\n";
}
 
void debug(vector<vector<ll>> x){
	cout << "\n";
	for (int i = 0; i < x.size(); i++){
		for (int j = 0; j < x[i].size(); j++){
			cout << x[i][j] << " ";
		}
		cout << "\n";
	}
}
 
void debug(set<int> x){
	cout << "\n";
	for (auto s : x){
		cout << s << " ";
	}
	cout << "\n";
}
 
// ios_base::sync_with_stdio(0); 
// cin.tie(0);
 
int n,m; 
vector<int> cit[100001];
bool seen[100001];
 
void dfs(int x){
	if (seen[x]){return;}
	seen[x] = true;
	for (int u : cit[x]){
		dfs(u);
	}
}
 
int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		cit[x].push_back(y);
		cit[y].push_back(x);
	}
 
	vector<int> ans;
	for (int i = 1; i < n+1; i++){
		if (!seen[i]){
			dfs(i); ans.push_back(i);
		}
	}
	
	cout << ans.size()-1 << endl;
	for (int i = 0; i < ans.size()-1; i++){
		cout << ans[i] << " " << ans[i+1] << endl;
	}
}
