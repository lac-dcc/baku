#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
int main() {
	int n, k;
 
	cin >> n >> k;
 
	vector<pair<int, int>> pd(n);
 
	for (int i = 0; i < n; i++){
		cin >> pd[i].second >> pd[i].first;
    }
	sort(begin(pd), end(pd));
 
	int max_mov = 0;
	multiset<int> end_times;
	for (int i = 0; i < k; ++i){
        end_times.insert(0);
    }
 
	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(pd[i].second);
		if (it == begin(end_times)) continue;
        
		end_times.erase(--it);
		end_times.insert(pd[i].first);
		++max_mov;
	}
 
	cout << max_mov;
}