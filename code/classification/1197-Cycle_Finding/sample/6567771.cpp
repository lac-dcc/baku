#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using lld = long double;
using ull = unsigned long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x) ((void)0);
#endif
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop(i,k,n) for(ll i = k; i < n;i++)
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define UNIQUE(X) X.erase(unique(all(X)),X.end())
const ll INF = 1e18;
const ll mxINF = 0x3f3f3f3f3f3f3f3f;
 
template<class A> void read(vector<A>& v);
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
 
template<class A> void read(vector<A>& x) {
    for (auto& a: x)
        read(a);
}
template<class A> void read1(vector<A>& x) {
    for(ll i = 1; i <= sz(x) - 1; i++){
        read(x[i]);
    }    
}
 
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void google(int t) {cout << "Case #" << t << ": ";}
 
ll mul(ll a, ll b, ll m) {
        if (a < (1 << 14)) {
            return (a * b) % m;
        }
        ll c = mul(a >> 14, b, m);
        c <<= 14;
        c %= m;
        c = (c + (a % (1 << 14)) * b) % m;
        return c;
}
ll fast_power(ll p, ll e, ll m) {
        if (e == 0) {
            return 1 % m;
        }
        if (e % 2 == 0) {
            return fast_power(mul(p, p, m), e / 2, m);
        }
        else {
            return mul(fast_power(p, e - 1, m), p, m);
        }
}
 
// #define N 200005     // change N here
// vector<vll> adjl(N);
// vll visited(N);
 
// ll n, m;
 
// vector<ll> adj[N];
// void dfs(ll u){
//     visited[u] = 1;
//     for(ll v: adj[u]){
//         if(!visited[v]){
//             dfs(v);
//         }
//     }
// }
 
// vll dist;
 
// void bfs(ll s) {
//     dist.assign(n + 1, -1);  // n must be defined(i.e global)
//     queue<ll> q;
//     dist[s] = 0; q.push(s);
//     while (q.size()) {
//         ll u = q.front(); q.pop();
//         for (ll v : adj[u]) {
//             if (dist[v] == -1) {
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }
 
// const ll maxn = 1000;   // set maxn accordingly
// ll C[maxn + 1][maxn + 1];
// void makenCr(){
//     C[0][0] = 1;
//     for (ll n = 1; n <= maxn; ++n) {
//         C[n][0] = C[n][n] = 1;
//         for (ll k = 1; k < n; ++k)
//             C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
//             // C[n][k] %= MOD;
//     }
// }
 
ll ok;
 
void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adjl(n+1);
 
    loop(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        adjl[a].pb(mp(b, c));
    }
    vll d(n+1, 0);
    vll p(n+1, -1);
 
    ok = true;
 
        loop(_,0,n) {
            loop(i, 1, n+1) {
                if(d[i]!= INF)
                for(auto [u, w]: adjl[i]) {
                    if(d[u] > d[i] + w) {
                        d[u] = d[i] + w;
                        p[u] = i;
                    }   
                }
            }
        }
 
        ll src = -1;
        loop(i, 1, n+1) {
            if(d[i]!= INF)
            for(auto [u, w]: adjl[i]) {
                if(d[u] > d[i] + w) {
                    src = i; // be careful src = u might give you wrong ans
                    break;
                }
            }
        }
        debug(d)
        debug(p)
        debug(adjl)
        if(src != -1) {
            ok = false;
            
            loop(i, 0, n-1) src = p[src];
            
            cout << "YES" << nl;
            vll path;
            path.pb(src); 
            ll dest = src; src = p[src];
            while(src != dest) {
                path.pb(src);
                src = p[src];
            }
            path.pb(dest);
            reverse(all(path));
            for(auto x: path)cout << x << " ";
            cout << nl;
        }
        
    if(ok)
    cout << "NO"<<nl;
}
 
int main(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
 
    int t = 1;
    // cin>>t;
    for(ll i = 1; i <= t; i ++)
    {   
        solve();
    }
}
 
