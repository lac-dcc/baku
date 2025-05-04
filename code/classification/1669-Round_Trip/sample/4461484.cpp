#include <bits/stdc++.h>
#define int long long
#define double long double
#define P(x) {if (debug) cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define DR(i,a,b) for (int i=(b); i-->(a);)
#define D(i,n) DR(i,0,n)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)  
#define MA(a,v) a = max(a,v)
#define V vector 
#define pb push_back  
#define mt make_tuple
#define MAX_VALUE 100000
#define MOD 1000000007
 
using namespace std;
template<class T> ostream &operator<<(ostream &os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i];
    return os;
}
 
const bool debug = 1;
const int INF = numeric_limits<int>::max()/2;
 
V<V<int>> adj;
enum state {UNVIS, OPEN, CLOSED};
V<state> st;
 
int starting, ending;
V<int> p;
 
bool dfs(int s, int par){
	st[s] = OPEN;
	for(int u: adj[s]){
		if (st[u] == UNVIS){
			p[u] = s;
			if (dfs(u, s)) return true;
		}
		else if (st[u] == OPEN && u != par){
			starting = u; ending = s;
			return true;
		}
	}
	st[s] = CLOSED;
	return false;
}
 
signed main(){  
    ios::sync_with_stdio(false);    
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    st.resize(n+1, UNVIS);
    p.resize(n+1);
    F(i, m){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FR(i, 1, n+1){
		p[i] = -1;
		if (dfs(i, -1)){
			V<int> ans;
			for(int node = ending; node != starting; node = p[node]) ans.pb(node);
			ans.pb(starting);
			reverse(ALL(ans));
			cout << S(ans) + 1 << endl;
			cout << ans << " " << ans[0] << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}
