#include<bits/stdc++.h>
 
using namespace std;
 
//Vtype
using ll = long long;
using ld = long double;
using db = double;
using str = string;
 
//Vpairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
//Vvector
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
#define pb push_back
 
//pairs
#define mp make_pair
#define f first
#define s second
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define cont continue
#define bre break
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s) {
	setIn(s+".inp"); setOut(s+".out");
}
 
const ll MAXN = 1e5 + 9;
const ll INF = 1e18;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    setIO("CodeforcesEasy");
 
    ll n, m;
    cin >> n >> m;
 
    vl adj[n + 1];
 
    F0R(i, m){
        ll u, v;
        cin >> u >> v;
 
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    ll par[n + 1];
 
    queue<ll> qu;
    qu.push(1);
    FOR(i, 1, n + 1) par[i] = 0;
 
    while(!qu.empty()){
        ll u = qu.front(); qu.pop();
 
        if(u == n){
            vl path;
 
            while(u != 0){
                path.pb(u);
                u = par[u];
            }
 
            cout << path.size() << endl;
 
            reverse(path.begin(), path.end());
 
            cout << path[0];
            FOR(i, 1, path.size()) cout << " " << path[i];
 
            return 0;
        }
 
        for(auto v : adj[u]){
            if(par[v] != 0 || par[u] == v) cont;
 
            par[v] = u;
 
            qu.push(v);
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
 
	return 0;
}
 
