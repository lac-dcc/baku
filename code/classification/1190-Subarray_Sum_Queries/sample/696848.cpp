#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
const int M = 1000000007, BIG = 0x3f3f3f3f;
 
// Segment Tree for online Maximum Subarray Sum Queries
template <typename T>
class SegTree {
	vi L, R;
	vector<T> sum, px, sx, msas;
	const vector<T>& src_arr;
	void Build(int p, int _L, int _R) {
		L[p] = _L;
		R[p] = _R;
		if (_L == _R) {
			sum[p] = src_arr[_L];
			px[p] = sx[p] = msas[p] = max(0ll, src_arr[_L]);
			return;
		}
		const int l = (p << 1), r = l + 1, mid = _L + (_R - _L) / 2;
		Build(l, _L, mid);
		Build(r, mid + 1, _R);
		sum[p] = sum[l] + sum[r];
		px[p] = max(px[l], sum[l] + px[r]);
		sx[p] = max(sx[r], sum[r] + sx[l]);
		msas[p] = max(max(msas[l], msas[r]), sx[l] + px[r]);
	}
	tuple<T, T, T, T> Q(int p, int i, int j, bool update = 0) {
		if (L[p] > j || R[p] < i)
			return { 0, 0, 0, 0 };
		if (L[p] >= i && R[p] <= j && !update)
			return { sum[p], px[p], sx[p], msas[p] };
		const int l = (p << 1), r = l + 1, mid = L[p] + (R[p] - L[p]) / 2;
		const auto [lsum, lpx, lsx, lmsas] = Q(l, i, mid);
		const auto [rsum, rpx, rsx, rmsas] = Q(r, mid + 1, j);
		const T xsum = lsum + rsum;
		const T xpx = max(lpx, lsum + rpx);
		const T xsx = max(rsx, rsum + lsx);
		const T xmsas = max(max(lmsas, rmsas), lsx + rpx);
		return { xsum, xpx, xsx, xmsas };
	}
public:
	SegTree(const vector<T>& _a) : src_arr(_a) {
		size_t tree_sz = _a.size() << 2;
		sum.resize(tree_sz);
		px.resize(tree_sz);
		sx.resize(tree_sz);
		msas.resize(tree_sz);
		L.resize(tree_sz);
		R.resize(tree_sz);
		Build(1, 1, _a.size() - 1);
	}
	T MSAS(int i, int j) { return get<3>(Q(1, i, j)); }
	void Update(int arr_idx, T value) {
		int p = 1;
		while (L[p] < R[p]) {
			p <<= 1;
			if (arr_idx > R[p])
				p++;
		}
		sum[p] = value;
		px[p] = sx[p] = msas[p] = max(0ll, value);
		p >>= 1;
		while (p) {
			tie(sum[p], px[p], sx[p], msas[p]) = Q(p, L[p], R[p], 1);
			p >>= 1;
		}
	}
};
 
int n, m;
vector<ll> a;
vi k, x;
 
void Process() {
	SegTree<ll> tree(a);
	for (int i = 0; i < m; i++) {
		tree.Update(k[i], x[i]);
		cout << tree.MSAS(1, n) << "\n";
	}
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  while (cin >> n) {
    cin >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    k.resize(m);
    x.resize(m);
    for (int i = 0; i < m; i++)
      cin >> k[i] >> x[i];
 
		Process();
  }
 
  return 0;
}
