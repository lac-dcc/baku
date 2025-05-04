#include <iostream>
#include <set>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
 
	set<int> nums;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		nums.emplace(x);
	}
 
	cout << nums.size();
 
	return 0;
}