// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
long long n;
 
int main() {
	cin.tie(0)->sync_with_stdio(false);
 
	cin >> n;
	vector<long long> prefix {0};
	long long x;
	for (long long i = 0; i < n; i++) {
		cin >> x;
		prefix.push_back(x + prefix[i]);
	}
	
	long long maxpfx = prefix[1];
	long long minpfx = 0;
	for (long long i = 1; i <= n; i++) {
		maxpfx = max(maxpfx, prefix[i] - minpfx);
		minpfx = min(minpfx, prefix[i]);
	}
 
	cout << maxpfx;
 
	return 0;
}
