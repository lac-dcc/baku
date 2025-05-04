#include <bits/stdc++.h>
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
 
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
typedef long long int ll;
const ll INF = 2e18;
const ll inf = 2e9 + 10;
const ll mod = 1e8;
const ll Mod = 998244353;
#define ll long long int
 
vector<int> adj[200001];
vector<int> downpath(200001);
vector<int> diameter(200001);
 
void eval_path(int src,int par) {
    int bestchilddownpath = 0;
    bool leaf = 1;
    for(int child : adj[src]) {
        if(child != par) {
            leaf = 0;
            eval_path(child,src);
            bestchilddownpath = max(bestchilddownpath,downpath[child]);
        }
    }
    if(leaf) downpath[src] = 0;
    else downpath[src] = 1 + bestchilddownpath;
}
 
void solve(int src, int par) {
    int ans = 0;
    vector<int> childrenpaths;
    for(auto child : adj[src]) {
        if(child != par) {
            solve(child,src);
            childrenpaths.push_back(downpath[child]);
            ans = max(ans,diameter[child]);
        }
    }
    int numofchild = childrenpaths.size();
    sort(all(childrenpaths));
 
    if(numofchild == 0) diameter[src] = 0;
    else if(numofchild == 1) diameter[src] = 1 + childrenpaths[0];
    else diameter[src] = 2 + childrenpaths[numofchild - 1] + childrenpaths[numofchild - 2];
    diameter[src] = max(diameter[src],ans);
}
 
void solve() {
    ll n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    eval_path(1,0);
    solve(1,0);
    cout << diameter[1] << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        solve();
    }   
}        
