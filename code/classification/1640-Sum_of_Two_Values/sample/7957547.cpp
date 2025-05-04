#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, target;
	cin >> n >> target;
 
	vector<pair<int, int>> values;
	// append the element and its index
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		values.push_back({x, i + 1});
	}
 
	sort(values.begin(), values.end());
	int left = 0;
	int right = n - 1;
	while (left < right) {
		// adjust left and right pointers
		if (values[left].first + values[right].first > target) {
			right--;
		} else if (values[left].first + values[right].first < target) {
			left++;
		} else if (values[left].first + values[right].first == target) {
			cout << values[right].second << " " << values[left].second << endl;
			return 0;
		}
	}
 
	// print IMPOSSIBLE if we haven't found a pair
	cout << "IMPOSSIBLE" << endl;
}
