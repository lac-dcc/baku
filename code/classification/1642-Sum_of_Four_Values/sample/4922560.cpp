#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
vector<int> arr;
unordered_map<int, pair<int, int>> umap;
 
int solve(int n, int x) {	
	for (int i=n-1; i>=0; i--) {
		for (int j=i-1; j>=0; j--) {
			int target = x - (arr[i] + arr[j]);
			if (umap.count(target)) {
				cout << i+1 << " " << j+1 << " " << umap[target].first+1 << " " << umap[target].second+1 << endl;
				return 0;
			}
		}
		for (int j=i+1; j<n; j++) umap[arr[i]+arr[j]] = {i, j};
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
 
int main() {
    int n, x;
	cin >> n >> x;
	
	for (int i=0; i<n; i++) {
		int y; cin >> y;
		arr.push_back(y);
	}
	solve(n, x);
	
    return 0;
}
