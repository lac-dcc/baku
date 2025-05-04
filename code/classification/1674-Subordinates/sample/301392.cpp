#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <bitset>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <fstream>
#include <tuple>
#include <stack>
#include <set>
#include <unordered_set>
 
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
 
#define ll long long
 
#define tiii tuple<int, int, int>
#define tlll tuple<long long, long long, long long>
#define tcii tuple<char, int, int>
#define tllll tuple<ll, ll, ll, ll> 
 
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
 
#define INF 1000000000
#define LINF 1000000000000000000
 
using namespace std;
 
 
template<typename T> inline T getint() {
	T val = 0;
	char c;
 
	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}
 
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
 
	return val * (neg ? -1 : 1);
}
 
int n;
vector<int> adj[200000];
int cnt[200000];
 
void dfs(int v)
{
	cnt[v] = 1;
	for (auto& e : adj[v])
	{
		dfs(e);
		cnt[v] += cnt[e];
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	n = getint<int>();
 
	for (int i = 1; i < n; ++i)
		adj[getint<int>() - 1].push_back(i);
	dfs(0);
	for (int i = 0; i < n; ++i)
		cout << cnt[i] - 1 << ' ';
	cout << '\n';
 
	return 0;
}
