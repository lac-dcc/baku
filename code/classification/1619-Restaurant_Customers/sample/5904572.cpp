// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
struct node {
	long long v;
	bool out;
};
 
int main() {
	int N; cin >> N;
	node a[N*2];
	for (int i = 0; i < N; i++) {
		cin >> a[i*2].v >> a[i*2+1].v;
		a[i*2].out = false;
		a[i*2+1].out = true;
	}
	sort(a, a+N*2, [](const node& a, const node& b){
		return (a.v < b.v);
	});
	int res = 0;
	int current = 0;
	for (int i = 0; i < N*2; i++) {
		if (a[i].out) {
			current--;
		} else {
			current++;
		}
		if (current > res) res = current;
	}
	cout << res << endl;
}
