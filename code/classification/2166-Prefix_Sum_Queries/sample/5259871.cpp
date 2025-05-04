// author:  anil_1
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
/*
In essence, Segment Tree divedes the given interval into some logarithmic number of intervals,
the sizes of which are some powers of two due to which they are easy to build and update
 
for this problem, i have stored and use those intervals later
https://cses.fi/problemset/result/3646550/
*/
 
 
const ll inf = -(1ll << 60);
 
vector<array<ll, 2>> seg;
// {sum, max_prefix}
 
void build(int node, int left, int right, vector<ll>& v) {
	if(left == right) {
		seg[node] = {v[left], v[left]};
		return;
	}
	int mid = (left + right) / 2;
	build(2 * node, left, mid, v);
	build(2 * node + 1, mid + 1, right, v);
	seg[node] = {seg[2 * node][0] + seg[2 * node + 1][0], max(seg[2 * node][1], seg[2 * node][0] + seg[2 * node + 1][1])};
}
 
void query(int node, int node_left, int node_right, int range_left, int range_right, vector<array<ll, 4>>& intervals) {
	if(node_right < range_left or range_right < node_left) {
		//disjoint
		return;
	}
	if(range_left <= node_left and node_right <= range_right) {
		// subset
		intervals.push_back({node_left, node_right, seg[node][0], seg[node][1]});
		return;
	}
	int mid = (node_left + node_right) / 2;
	query(2 * node, node_left, mid, range_left, range_right, intervals);
	query(2 * node + 1, mid + 1, node_right, range_left, range_right, intervals);
}
 
void update(int node, int node_left, int node_right, int index, int value) {
	if(node_left == node_right and node_right == index) {
		// subset
		seg[node] = {value, value};
		return;
	}
	int mid = (node_left + node_right) / 2;
	if(index > mid) {
		// move to right child
		update(2 * node + 1, mid + 1, node_right, index, value);
	} else {
		// move to left child
		update(2 * node, node_left, mid, index, value);
	}
	seg[node] = {seg[2 * node][0] + seg[2 * node + 1][0], max(seg[2 * node][1], seg[2 * node][0] + seg[2 * node + 1][1])};
}
 
void test_case() {
	int n, q;
	cin >> n >> q;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	seg.resize(4 * n + 1);
	build(1, 0, n - 1, v);
	// for(int i = 0; i < 4 * n + 1; i++) cout << seg[i][0] << ' ';
	// cout << '\n';
	while(q--) {
		int type, a, b;
		cin >> type >> a >> b;
		if(type == 1) {
			update(1, 0, n - 1, a - 1, b);
		} else {
			vector<array<ll, 4>> f;
			query(1, 0, n - 1, a - 1, b - 1, f);
			sort(f.begin(), f.end());
			ll ans = 0, s = 0;
			for(array<ll, 4>& x : f) {
				ans = max(ans, s + x[3]);
				// cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << ' ';
				s += x[2];
			}
			cout << ans << '\n';
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        test_case();
    }
    return 0;
}
