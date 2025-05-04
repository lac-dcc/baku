#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include <algorithm>
#include<vector>
#include <cmath>
#include<set>
#include<unordered_set>
#include<string.h>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
#include<map>
#include<unordered_map>
#include <stdlib.h>
#include<bitset> //std::cout << static_cast<int>(bs.to_ulong()) << endl;
#define _CRT_SECURE_NO_WARNINGS
#define SA3D ios::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pi 3.14159265359 
using namespace std;
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
#define all(v) v.begin() , v.end()
 
int n, m;
struct edge {
	int from, to, c;
	edge(){}
	edge (int from , int to , int c):from(from),to(to),c(c){
	}
};
vector<int>seq;
vector<edge>g;
vector<ll>bellman,nth,nth_plus;
vector<int>ans;
bool cycle() {
	for (int i = 1; i <= n;++i) {
		if (nth[i] != nth_plus[i])return 1;
	}
	return 0;
}
bool ditict_cycle() {
	unordered_map<int, bool>mp;
	int l=-1, r=-1; stack<int>sk;
	for (int i = 1; i <= n;++i) 
		if (nth[i] != nth_plus[i]) {
			l = r = i;
	}
	if (r == -1)return 0;
	int idx = 0;  sk.push(r); r = seq[r];
	while (r>0 && r<n+1 && idx<n*2) {
		sk.push(r);
		r = seq[r];
		idx++;
	}
	while (!sk.empty()) {
		ans.push_back(sk.top());
		if (mp[sk.top()]) 
			return 1;
		mp[sk.top()] = 1;
		sk.pop();
	}
return 0;
}
int main() {
	SA3D;
	cin >> n >> m;
	int u, v, c;
	g=vector<edge>(m);
	for (int i = 0; i < m;++i) {
		cin >> u >> v >> c;
		g[i] = edge(u, v, c);
	}
	seq = vector<int>(n + 1);
	bellman =nth=nth_plus=vector<ll>(n + 1, 1e17);
	bellman[1] = 0;
	for (int i = 0; i < 2*n; ++i) {
		for (edge &e : g) {
			if (bellman[e.to] > e.c + bellman[e.from]) {
				bellman[e.to] = e.c + bellman[e.from];
				seq[e.to] = e.from;
			}
		}
		if (i == n)nth = bellman;
		else if (i == n + 1) {
			nth_plus = bellman;
			if (!cycle)return cout << "NO", 0;
		}
		else if (i > n + 1)nth_plus = bellman;
	}
	
	if(!ditict_cycle())return cout << "NO", 0;
	cout << "YES\n";
	for (int i = 0;i < ans.size();++i)cout << ans[i] << " ";
} 
