#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define el '\n'
#define gcd __gcd
#define lcm(x,y) x * y / gcd(x ,y)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define f first
#define s second
#define F(i,a,b) for(int i = a ; i < b ; i++)
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mii map<int,int>
#define si set<int>
#define all(x) x.begin() , x.end()
#define ordered_set tree<ii, null_type, less<ii>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio() ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
#define ub upper_bound
#define lb lower_bound
using namespace std;
using namespace __gnu_pbds;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 1;
int n , m , a , b , par[maxn] , lap[maxn];
vi adj[maxn] , ans;
inline int readInt()
{
    bool Minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while(true){if (ch == '-') break; if (ch >= '0' && ch <= '9') break; ch = getchar();}
    if (ch == '-') Minus = true; else result = ch- '0';
    while(true){ch = getchar(); if (ch < '0' || ch > '9') break; result = result * 10 + (ch - '0');}
    if (Minus) return -result; else return result;
}
int trace(int u)
{
    return (lap[u] < 0 ? u : lap[u] = trace(lap[u]));
}
bool syncretize(int u , int v)
{
    u = trace(u) , v = trace(v);
    if(u == v) return 0;
    if(lap[u] < lap[v]) swap(u , v);
    lap[v] += lap[u] , lap[u] = v;
    return 1;
}
void dfs(int cur)
{
    for(auto next : adj[cur]) if(next != par[cur]) par[next] = cur , dfs(next);
}
int main()
{
    fastio();
    n = readInt() , m = readInt();
    fill(lap + 1 , lap + n + 1 , -1);
    while(m--)
    {
        a = readInt() , b = readInt();
        if(!syncretize(a , b))
        {
            dfs(a);
            int temp = b;
            while(temp != 0) ans.pb(temp) , temp = par[temp];
            cout << ans.size() + 1 << el;
            for(auto x : ans) cout << x << " ";
            cout << b;
            exit(0);
        }
        adj[a].pb(b) , adj[b].pb(a);
    }
    cout << "IMPOSSIBLE";
    return 0;
}
