#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
 
using namespace std;
 
unordered_map<int, vector<int>> adj_list;
unordered_set<int> visited;
unordered_map<int, int> previous;
int start1, end1;
 
bool dfs(int current_node, int previous_node) {
 
	visited.insert(current_node);
	previous[current_node] = previous_node;
	
	for(auto neighbor : adj_list[current_node]) {
		
		if(neighbor == previous_node) {
			continue;
		}
 
		if(visited.count(neighbor) > 0) {
			start1 = neighbor;
			end1 = current_node;
			return true;	
		}
 
		if(visited.count(neighbor) == 0) { 
			if(dfs(neighbor, current_node)) {
				return true;
			}
		}
 
	}
 
	return false;
 
}
 
bool visit_all(int n) {
	
	for(int i=1; i<=n; i++) {
		if(visited.count(i) == 0) {
			if(dfs(i, -1)) {
				return true;
			}
		}
	}
 
	return false;
 
}
 
int main() {
	
#ifdef OFFLINE
	freopen("../../input", "r", stdin);
	freopen("../../output", "w", stdout);
#endif
 
	int n, m;
	cin>>n>>m;
 
	int a, b;
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
 
	if(false == visit_all(n)) {
		cout<<"IMPOSSIBLE\n";
	}
	else {
		vector<int> ans;
		int end_temp = end1;
		ans.push_back(end1);
 
		while(end_temp != start1) {
			ans.push_back(previous[end_temp]);
			end_temp = previous[end_temp];
		}
 
		ans.push_back(end1);
 
		cout<<ans.size()<<endl;
	
		for(auto i : ans) {
			cout<<i<<" ";
		}
	}
 
	return 0;
}
