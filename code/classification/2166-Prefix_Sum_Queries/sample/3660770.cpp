// Phoenix 
#include <bits/stdc++.h>
using namespace std;
 
#define PB push_back
#define ALL(i_) i_.begin(), i_.end()
#define LOG2(x) (31 - __builtin_clz(x));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
 
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
 
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
    
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
 
const int mod = (int) 1e9 + 7;
const int oo = (int) 1e9 + 99;
const int maxn = (int) 2e5 + 11;
const int LOG = (int) 17;
 
int n, q;
int a[maxn];
 
struct SegmentTree{
	struct node_{
		ll sum, pre;
	} seg[4 * maxn];
 
	node_ Merge(node_ L, node_ R){
		node_ res;
		res.sum = L.sum + R.sum;
		res.pre = max(L.pre, L.sum + R.pre);
		return res;
	}
 
	void Build(int node = 1, int lf = 1, int rt = n){
		if(lf == rt){
			seg[node] = {a[lf], a[lf]};
			return;
		}
		int mid = (lf + rt) >> 1;
		Build(node << 1, lf, mid);
		Build(node << 1 | 1, mid + 1, rt);
		seg[node] = Merge(seg[node << 1], seg[node << 1 | 1]);
	}
 
	void Update(int u, int w, int node = 1, int lf = 1, int rt = n){
		if(lf == rt){
			seg[node] = {w, w};
			return;
		}
		int mid = (lf + rt) >> 1;
		if(mid >= u) Update(u, w, node << 1, lf, mid);
		else Update(u, w, node << 1 | 1, mid + 1, rt);
		seg[node] = Merge(seg[node << 1], seg[node << 1 | 1]);
	}
 
	node_ Get(int u, int v, int node = 1, int lf = 1, int rt = n){
		if(u > rt || v < lf) return {0, (ll) -1e15};
		if(lf >= u && rt <= v) return seg[node];
		int mid = (lf + rt) >> 1;
		node_ L = Get(u, v, node << 1, lf, mid);
		node_ R = Get(u, v, node << 1 | 1, mid + 1, rt);
		return Merge(L, R);
	}
} mySeg;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    mySeg.Build();
	while(q--){
		int op, u, v; cin >> op >> u >> v;
		if(op == 1) mySeg.Update(u, v);
		else cout << max(0ll, mySeg.Get(u, v).pre) << "\n";
	}
    return 0;
}
