#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define ff first
#define ss second
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x) fixed << setprecision(10) << x
#define mod 1000000007
#define inf 1e18
#define w(tc) int tc; cin >> tc; for (int i = 1; i <= tc; ++i)
#define PI 3.14159265358979323846264338327950L
#define span(a) begin(a), end(a)
#define ll long long
 
 
/*
int lcm (int a, int b)  {
	return a / __gcd(a, b) * b;
}
 
void EEA(int a, int b, int &x, int &y) {
	if (a == 1) {
		x = 1, y = 0;
		return;
	}
	int x1, y1;
	EEA(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
}
 
int modinverse(int a) {
	if (__gcd(a, mod) != 1)
		return -1;
	int x, y;
	EEA(a, mod, x, y);
	x = (x % mod + mod) % mod;
	return x;
}
 
ll fact(int n) {
	int factorial[n + 1];
	factorial[0] = 1;
	for (int i = 1; i <= n; i++)
		factorial[i] = factorial[i - 1] * i % mod;
	return factorial[n];
}
 
ll ncr(int n, int k) {
	return fact(n) * modinverse(fact(k) * fact(n - k) % mod) % mod;
}
*/
const int N = 100009;
int n, m;
 
bool vis[N];
vector<int> adj[N];
int p[N];
int d[N];
 
void bfs() {
	queue<int> q;
	q.push(1);
	vis[1] = true;
	p[1] = -1;
	while(!q.empty()) {
		int k = q.front();
		q.pop();
		for (int child : adj[k]) {
			if (!vis[child]) {
				vis[child] = true;
				d[child] = d[k] + 1;
				p[child] = k;
				q.push(child);
			}
		}
	}
	if (!vis[n]) {
		cout << "IMPOSSIBLE";
	} else {
		cout << d[n] + 1 << endl;
		vector<int> ans;
		for (int i = n; i != -1; i = p[i]) 
			ans.pb(i);
		reverse(span(ans));
		for (int v : ans)
			cout << v << " ";
	}
 
}
inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bfs();
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//w(tc)
	solve();
	return 0;
}
