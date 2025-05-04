#include <bits/stdc++.h>
using namespace std;
#define rep(a,n) for (int i=a;i<n;i++)
#define per(a,n) for (int i=n-1;i>=a;i--)
#define fro(n) for (int i=0;i<n;i++)
#define rev(n) for (int i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
 
int n, m;
vector<vector<int>> g;
vector<int> color;
vector<bool> vis;
 
bool dfs(int u, int c)
{
	vis[u] = true;
	color[u] = c;
 
	for (auto v : g[u])
	{
		if (color[v] == 0)
			if (!dfs(v, (color[u] ^ 3)))
				return false;
		if (color[v] == color[u])
			return false;
	}
	return true;
}
 
bool color_all()
{
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
			if (!dfs(i, 1))
				return false;
	}
	return true;
}
 
int main() {
 
 
#ifndef ONLINE_JUDGE
	auto start = chrono::high_resolution_clock::now();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long double timestarts = chrono::system_clock::now().time_since_epoch().count() / 1e-6;
#endif
	FIO
 
// Solving Area Starts
 
 
	long long int tc = 1;
 
	while (tc--) {
		cin >> n >> m;
		g.resize(n + 1);
		color.resize(n + 1);
		vis.resize(n + 1);
 
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool ans = color_all();
		if (!ans)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		for (int i = 1; i <= n ; ++i)
		{
			cout << color[i] << " ";
		}
		cout << endl;
	}
 
//Solving Area ends
 
#ifndef ONLINE_JUDGE
	auto end = chrono::high_resolution_clock::now();
	double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-6;
	cout << "Time " << fixed << time_taken << setprecision(6);
	cout << " milsec" << endl;
#endif
 
 
 
}
 
 
