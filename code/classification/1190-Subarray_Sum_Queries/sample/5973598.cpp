#include <bits/stdc++.h>
 
using namespace std;
 
struct node{
	long long sum = 0, l = 0, r = 0, m = 0; 	
};
 
vector<node> tree;
 
void update(int node, int l, int r, int k, long long x){
	if (l > k || r < k)
		return;
	if (l == r){
		tree[node].sum = x;
		tree[node].m = max(0LL, x);
		tree[node].l = max(0LL, x);
		tree[node].r = max(0LL, x);
		return;
	}
	int mid = (r - l) / 2 + l;
	update(node * 2 + 1, l, mid, k, x);
	update(node * 2 + 2, mid + 1, r, k, x);
	long long ll = tree[node * 2 + 1].l, lr = tree[node * 2 + 1].r;
	long long rl = tree[node * 2 + 2].l, rr = tree[node * 2 + 2].r;
	long long ls = tree[node * 2 + 1].sum, rs = tree[node * 2 + 2].sum;
	long long lm = tree[node * 2 + 1].m, rm = tree[node * 2 + 2].m;
	tree[node].sum = ls + rs;
	tree[node].l = max(ll, ls + rl);
	tree[node].r = max(rr, rs + lr);
	tree[node].m = max(max(lr + rl, lm), rm);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	tree.resize(n << 2);
	for (int i = 0; i < n; i++){
		long long input;
		cin >> input;
		update(0, 0, n - 1, i, input);
	}
	while (q--){
		int k;
		long long x;
		cin >> k >> x;
		k--;
		update(0, 0, n - 1, k, x);
		cout << tree[0].m << "\n";
	}
	return 0;
}
