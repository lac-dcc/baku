#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;
 
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
 
int N, A[200005], B[200005], P[200005];
pii S[200005];
 
struct node {
	ll v; 
	int l, r, lc = -1, rc = -1;
};
 
node newNode(ll v, int l, int r, int lc, int rc) {
	node temp;
	temp.v = v;
	temp.l = l;
	temp.r = r;
	temp.lc = lc;
	temp.rc = rc; 
	return temp;
}
 
vector<node> T;
 
void update(int u, ll v, int n) {
	//cout << n << ": " << T[n].l << ' ' << T[n].r << '\n';;
 
	if (T[n].l == T[n].r) {
		T[n].v = max(T[n].v, v);
		return;
	}
 
	int m = (T[n].l + T[n].r) / 2;
	if (u <= m) {
		if (T[n].lc == -1) {
			T.PB(newNode(0, T[n].l, m, -1, -1));
			T[n].lc = T.size() - 1;
		}
		update(u, v, T[n].lc);
	}
	else {
		if (T[n].rc == -1) {
			T.PB(newNode(0, m + 1, T[n].r, -1, -1));
			T[n].rc = T.size() - 1;
		}
		update(u, v, T[n].rc);
	}
 
	T[n].v = max((T[n].lc == -1 ? 0 : T[T[n].lc].v), (T[n].rc == -1 ? 0 : T[T[n].rc].v));
}
 
void update(int u, ll v) {
	return update(u, v, 0);
}
 
ll query(int l, int r, int n) {
	if (n == -1 || T[n].r < l || T[n].l > r)
		return 0;
 
	if (l <= T[n].l && T[n].r <= r)
		return T[n].v;
 
	return max(query(l, r, T[n].lc), query(l, r, T[n].rc));
}
 
ll query(int l, int r) {
	return query(l, r, 0);
}
 
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(FILE_NAME, "r",stdin);
    // freopen(FILE_NAME, "w",stdout);
 
	T.PB(newNode(0, 0, 1000000000, -1, -1));
 
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> P[i];
		S[i] = MP(A[i], i);
	}
	sort(S, S + N);
 
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll t = query(0, A[S[i].SS] - 1) + P[S[i].SS];
		//cout << S[i].SS << ' ' << t << '\n';
		ans = max(t, ans);
		update(B[S[i].SS], t);
	}
 
	cout << ans << '\n';
}