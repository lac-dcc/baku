#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int OFF = (1 << 20);
 
int n, q, ty, p1, p2;
int val[200005];
ll t[2*OFF+5];
ll p[2*OFF+5];
 
void prop(int x) {
	p[x*2] += p[x];
	p[x*2+1] += p[x];
	
	t[x*2] += p[x];
	t[x*2+1] += p[x];
 
	p[x] = 0;
}
 
ll query(int a, int b, int l, int r, int x) {
	if (r <= a || b <= l) return -INF;
	if (a <= l && r <= b) return t[x];
	
	prop(x);
	
	return max(query(a, b, l, (l+r)/2, x*2), query(a, b, (l+r)/2, r, x*2+1));
}
 
void update(int a, int b, int l, int r, int x, int kol) {
	if (r <= a || b <= l) return;
	if (a <= l && r <= b) {
		t[x] += kol;
		p[x] += kol;
		return;
	}
	
	prop(x);
	
	update(a, b, l, (l+r)/2, x*2, kol);
	update(a, b, (l+r)/2, r, x*2+1, kol);
	t[x] = max(t[x*2], t[x*2+1]);
}
 
int main () {
 
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
		update(i, n, 0, OFF, 1, val[i]);
	}
	
	for (int i = 0; i < q; i++) {
		cin >> ty >> p1 >> p2;
		
		if (ty == 1) {
			p1--;
			update(p1, n, 0, OFF, 1, -val[p1]);
			val[p1] = p2;
			update(p1, n, 0, OFF, 1, val[p1]);
		}
		else {
			p1--;
			ll sol = query(p1, p2, 0, OFF, 1);
			if (p1 > 0) sol -= query(p1-1, p1, 0, OFF, 1);
			sol = max(0LL, sol);
			cout << sol << "\n";
		}
	}
 
	return 0;
}
