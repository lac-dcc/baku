//Sublime with mod inv and exp
 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define _mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#define _f first
#define _s second
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p._f); cerr << ","; _print(p._s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define _d(x) _p(x); cout << endl;
void _p(ll t)     {cout << t;}
void _p(int t)    {cout << t;}
void _p(string t) {cout << t;}
void _p(char t)   {cout << t;}
void _p(lld t)    {cout << t;}
void _p(double t) {cout << t;}
void _p(ull t)    {cout << t;}
template <class T, class V> void _p(pair <T, V> p);
template <class T> void _p(vector <T> v);
template <class T> void _p(set <T> v);
template <class T, class V> void _p(map <T, V> v);
template <class T> void _p(multiset <T> v);
template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.ff); cout << ","; _p(p.ss); cout << "}";}
template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}
#define _sz(x) ((int)(x).size())
#define _a(x) (x).begin(), (x).end()
 
#define _pb push_back
#define _pob pop_back
#define int long long int
#define _vvi vector<vector<int>>
#define _vi vector<int>
#define _vvb vector<vector<bool>>
#define _mnh priority_queue<int, vector<int>, greater<int>>
#define _mxh priority_queue<int>
#define _m map<int, int>
#define _um unordered_map<int, int>
#define _vs vector<string>
#define _vvs vector<vector<string>>
#define _vc vector<char>
#define _vvc vector<vector<char>>
#define _vpi vector<pair<int, int>
#define _pi pair<int, int>
/*-------------------------------------------------------------------------------------------------------------------------*/
 
 
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
int modPow(int b, int p) {
    if (p == 0)
        return 1;
 
    int x = modPow(b, p / 2);
 
    return p % 2 == 0 ? mul(x, x) : mul(b, mul(x, x));
}
 
int moduloInverse(int n) {
    //(p / n) % mod  
    return modPow(n, MOD - 2);
}
int mod_exp(int base, int exp, int mod)
{
    int res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)//if exp is odd
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
/*-------------------------------------------------------------------------*/
 
 
int N, M;
vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string dd = "DURL";
bool is_val(int a, int b)
{
    if(a < 0 || b < 0 || a >= N || b >= M)return false;
    return true;
}
void DFS(int i, int j, vector<vector<char>>&v)
{
    v[i][j] = '#';
    for(auto &d : dir)
    {
        int x = i + d[0], y = j + d[1];
        if(is_val(x, y) && v[x][y] == '.')
        {
            DFS(x, y, v);
        }
    }
}
 
 
void DFS(int nn, vector<vector<int>>&g, vector<bool>&vis, int n)
{
    vis[nn] = true;
    for(auto &ch : g[nn])
    {
        if(vis[ch] == false)
        {
            DFS(ch, g, vis, n);
        }
    }
    return;
}
 
 
 
void solve(){
 
    int n, m;
    cin>>n>>m;
    vector<vector<int>>g(n + 1);
    for(int o = 0; o < m; o++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    int comp = 0;
    vector<bool>vis(n + 1, false);
    
    vector<int>ans;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == false)
        {
            ans.push_back(i);
            comp++;
            DFS(i, g, vis, n);
        }
    }
    cout<<comp - 1<<endl;
    for(auto i = 1; i < ans.size(); i++)
    {
        cout<<ans[i - 1]<<" "<<ans[i]<<endl;
    }
 
    return;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);    
#endif
fastio();
 
ll t;
// cin>>t;
t = 1;
while(t--)solve();
return 0;
}
 
