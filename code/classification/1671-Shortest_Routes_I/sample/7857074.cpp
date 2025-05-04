/************
 *
 * 	Author: Vaishnav Dixit
 * 	Profiles:
 *		->Codeforces: https://codeforces.com/profile/quater_nion
 * 		->CodeChef: https://www.codechef.com/users/vaishnav___
 *
************/
 
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define deb_(x) cerr<< #x << " = " << x << ' '; // display " x= "<x>"  ""   //debugging
#define deb(x) cerr<< fixed<<#x << " = " << x << '\n'; // display " x= "<x>"  ""   //debugging
#define deb2(x, y) cerr<< #x << " = " << x << " , " << #y << " = " << y << '\n';
#define deb2_(x, y) cerr<< #x << " = " << x << " , " << #y << " = " << y << ' ';
#else
#define deb_(x)
#define deb(x)
#define deb2(x, y) 
#define deb2_(x, y)
#endif
 
#define fo(i, n) for (int i = 0; i < n; i++)										// iterate i from i=0 to (n-1)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1) // iterate i from k to (n-1) (in case of increasing)  or (n+1)(in case of decreasing)
#define all(x) x.begin(), x.end()
#define maxall(x) *max_element(x.begin(), x.end())
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))								 // sort a vector....
#define eif else if
 
#define pb push_back
#define F first	 // for pair 
#define S second // for pair 
#define L left	 // for pair 
#define R right  // for pair 
#define ent '\n'
 
#define ll long long int
#define ull unsigned long long int
#define str string
typedef unordered_map<int, int> uomii;
typedef unordered_map<ll, ll> uomll;
typedef unordered_map<char, int> uomci;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvl;
 
const int mod = 1000000007;
const int N = 3e5, M = N;
const long double PI = 4 * atan(1);
const vpii dir = { {0,-1},{0,1},{1,0},{-1,0} };

/*
void vvvv(auto& v) {
	cerr << "[ ";
	for (auto i : v)
		cerr << i << ' ';
	cerr << "]\n";
}
*/

int ansIndex = 1;

/*
inline void print(auto& ans)
{
	cout << fixed << "Case #" << ansIndex++ << ": " << ans << '\n';
}
 
inline void inputVec(auto& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];
}
*/

int power(int x, int y)
{
	ll res = 1;
	while (y > 0) {
		if (y % 2 == 1)
			res = (res * x);
		y = y >> 1;
		x = (x * x);
	}
	return res % mod;
}
 
/*
	# Check var overflows
	# Check overflows for array indices and strings.
	# Dont stick to a single approach. Change. Adapt.
	# If u cant think of a algo, just go for bruteforce.
	# Keep doing something even if it may seem wrong.
	# All input first, then start algov
	# The problem isnt as hard as it seems. Keep in mind.
*/
 
void printop(char c, int freq) {
	for (int i = 0; i < freq; i++) {
		cout << c;
	}
}
 
// bool isLess(int k, int i) {
// 	int x = k ^ i;
// 	int index = 0;
// 	while (k) {
// 		if (((k & 1) == 0) && (x & (1 << index)))
// 			return false;
// 		index++;
// 		k = k / 2;
// 	}
// 	return true;
// }
// vvi dp;
// int solve(vi& a, int i, int j) {
// 	if (i > j) return 0;
// 	if (dp[i][j] !=-1) {
// 		cerr<<"dp found at "<<i<<","<<j<<'\n';
// 		return dp[i][j];
// 	}
// 	if (i == j) {
// 		return a[i];
// 	}
// 		cerr<<"at "<<i<<","<<j<<'\n';
// 	int a1 = ming5(a[i] + solve(a, i + 2, j), a[i] + solve(a, i + 1, j - 1));
// 	int a2 = min(a[j] + solve(a, i + 1, j - 1), a[j] + solve(a, i, j - 2));
// 	return dp[i][j] = max(a1, a2);
// }
 
 
// vector<vector<ll>> dp;
// bool solve(ll& n, ll& k, ll& x, ll sum, ll count, ll index) {
// 	if (index > n || count > k || sum > x) {
// 		return false;
// 	}
// 	if (dp[count][index] != -1) {
// 		return dp[count][index]
// 	}
// }
long long gcd(long long int a, long long int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}
 
bool isVovel(char c) {
	return (c == 'A') ||
		(c == 'E') ||
		(c == 'I') ||
		(c == 'O') ||
		(c == 'U');
}
 
vector<int> parent, sz;
int find(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}
void connect(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return;
	if (sz[pa] >= sz[pb]) {
		parent[pb] = pa;
		sz[pa] += sz[pb];
	}
	else {
		parent[pa] = pb;
		sz[pb] += sz[pa];
	}
}
 
void _(int tc)
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	vector<long long> dist(n, LLONG_MAX);
	dist[0] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a].push_back({ b, c });
	}
	vector<bool> isVis(n, 0);
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
	pq.push({ 0,0 });
	while (pq.size()) {
		auto [d, node] = pq.top();
		pq.pop();
		if (isVis[node]) continue;
		// dist[node] = d;
		isVis[node] = 1;
		for (auto& [child, childDist] : graph[node]) if (!isVis[child]) {
			if (d + childDist < dist[child]) {
				dist[child] = d + childDist;
				pq.push({ dist[child], child });
			}
		}
	}
	for (auto& i : dist)
		cout << i << ' ';
}
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	auto start = std::chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	int t = 1;
	// cin >> t;
	int temp = t;
	while (t--)
		_(temp - t);
	auto stop = std::chrono::high_resolution_clock::now();
	long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
	cerr << "Time taken: " << duration / 1e9 << "s";
	return 0;
}
