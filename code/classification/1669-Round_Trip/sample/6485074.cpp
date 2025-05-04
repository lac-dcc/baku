#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pll pair<ll, ll>
using namespace std;
const ll nmax = 2e5;
const ll mod = 1e9 + 7;
 
ll n, m, tmp1, tmp2;
bool found = 0;
vector<ll> par, res;
vector<bool> vs;
vector<vector<ll>> g;
 
bool dfs(ll u){
    vs[u] = 1;
 
    for(auto v : g[u]){
        if(v == par[u]) continue;
        if(vs[v]){
            tmp1 = u;
            tmp2 = v;
            return 1;
        }
        else{
            par[v] = u;
            if(dfs(v)) return 1;
        }
    }
 
    return 0;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
 
	cin >> n >> m;
	par.resize(n + 5);
	g.resize(n + 5);
	vs.resize(n + 5);
	while(m--){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
	}
 
	for(ll i = 1; i <= n; i++) if(!vs[i]){
        if(dfs(i)){
            found = 1;
            break;
        }
	}
 
	if(!found){
        cout << "IMPOSSIBLE";
        return 0;
	}
 
    res.push_back(tmp2);
    res.push_back(tmp1);
 
    while(tmp1 != tmp2){
        tmp1 = par[tmp1];
        res.push_back(tmp1);
    }
 
    cout << res.size() << endl;
    for(ll i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
 
	return 0;
}