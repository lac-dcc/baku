#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/
 
constexpr int MxN = 1e5+5;
vector<int> G[MxN];
int vis[MxN];
int reprezentant[MxN];
int kolor;
 
void dfs(int v) {
	vis[v] = kolor;
	if (!reprezentant[kolor])
		reprezentant[kolor] = v;
	for (auto u : G[v])
		if (!vis[u]) dfs(u);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	for (int i=1; i<=n; i++)
		if (!vis[i]) {
			kolor++;
			dfs(i);
		}
	cout << kolor-1 << "\n";
	for (int i=2; i<=kolor; i++)
		cout << reprezentant[1] << " " << reprezentant[i] << "\n";
 
	return 0;
}
