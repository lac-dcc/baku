#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define v(a, n) vector <int> a(n + 1, 0)
#define input(a, n) vector <int> a(n + 1, 0); for (int i = 1; i <= n; i++) cin >> a[i]
#define print(a, n) {for (int o = 1; o <= n; o++) cout << a[o] << " "; cout << endl;}
#define oset t <ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> int long long int
#define pr pair <int, int>
#define int long long int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e2 + 10;
const int FAC = 1e5 + 1;
const int N = 2e5 + 10;
vector <int> tpre(4*N, 0), tsuf(4*N, 0), t(4*N, 0), a(N, 0), tmx(4*N, 0);
int n, q;
 
void build(int v, int tl, int tr){
	if (tl == tr){
		int temp = max(a[tl], 0LL);
		tpre[v] = temp; tsuf[v] = temp; tmx[v] = temp;
		t[v] = a[tl];
		return;
	}
 
	int tm = (tl + tr)/2;
	build(2*v, tl, tm);
	build(2*v + 1, tm + 1, tr);
	t[v] = t[2*v] + t[2*v + 1];
	tsuf[v] = max(tsuf[2*v] + t[2*v + 1], tsuf[2*v + 1]);
	tpre[v] = max(t[2*v] + tpre[2*v + 1], tpre[2*v]);
	tmx[v] = max(tsuf[2*v] + tpre[2*v + 1], max(tmx[2*v], tmx[2*v + 1]));
}
 
void update(int v, int tl, int tr, int pos, int val){
	if (tl == tr){
		int temp = max(val, 0LL);
		tpre[v] = temp; tsuf[v] = temp; tmx[v] = temp;
		t[v] = val;
		return;
	}
 
	int tm = (tl + tr)/2;
	if (pos <= tm) update(2*v, tl, tm, pos, val);
	else update(2*v + 1, tm + 1, tr, pos, val);
 
	t[v] = t[2*v] + t[2*v + 1];
	tsuf[v] = max(t[2*v + 1] + tsuf[2*v], tsuf[2*v + 1]);
	tpre[v] = max(t[2*v] + tpre[2*v + 1], tpre[2*v]);
	tmx[v] = max(tsuf[2*v] + tpre[2*v + 1], max(tmx[2*v], tmx[2*v + 1]));
}
 
 
int32_t main(){
	cin >> n >> q;
	for (int i1 = 1; i1 <= n; i1++) cin >> a[i1];
	build(1, 1, n);
 
	int k, x;
	for (int i1 = 1; i1 <= q; i1++){
		cin >> k >> x;
		update(1, 1, n, k, x);
		cout << tmx[1] << endl;
	}
}
