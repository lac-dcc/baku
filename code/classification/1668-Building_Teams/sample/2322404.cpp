/*  
    ENJOY CP !!!!!
    Author :- Malav Gajjar
*/
#include<bits/stdc++.h>
//#include<ext/pd_ds/assoc_container.hpp>
//#include<ext/pd_ds/tree_policy.hpp>
//#include<ext/pd_ds/trie_policy.hpp>
using namespace std;
 
#define fio             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll              long long int 
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              push_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll, ll>
#define ump             unordered_map
#define mp              make_pair
#define pq_max          priority_pueue<ll>
#define pq_min          priority_pueue<ll, vi, greater<ll> >
#define all(v)          v.begin(), v.end()
#define ff              first
#define ss              second
#define rs              resize
#define ub              upper_bound
#define lb              lower_bound
#define mid(l, r)       (l + (r-l)/2)
#define bitc(x)         __builtin_popcount(x)
#define sp(a)           setprecision(a)
#define loop(a, b, c)       for(ll i=(a); i<=(b); i+=c)
#define loop_r(a, b, c) for(ll i=(a); i>=(b); i-=c)
#define itr(c)          for(auto it=c.begin(); it!=c.end(); it++)
#define log(x)          cout << #x << ' ' << x;
#define out(arr, a, b)  for(ll i=(a); i<=(b); i++)  cout << arr[i] << ' ';  cout << '\n';
 
template <typename T> T gcd(T a, T b) { if(a%b) return gcd(b, a%b); return b; }
template <typename T> T lcm(T a, T b) { return (a*b/gcd(a, b)); }
 
void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
map<ll, vi> edges;
vector<bool> visited;
ll n, m;
vi path;
 
void addEdge(ll i, ll j){
    edges[i].pb(j);
    edges[j].pb(i);
}
 
void dfs(ll n){
    for(auto it:edges[n]){
        if(!visited[it]){
            visited[it] = true;
            if(path[n] == 1)
                path[it] = 2;
 
            else
                path[it] = 1;
            dfs(it);
        }
 
        else{
            if(path[it] == path[n]){
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}
 
int main(int argc, char const *argv[])
{
    fio;
    file_i_o();
    /* code */
 
    cin >> n >> m;
    visited = vector<bool>(n+5);
    path = vi(n+5);
 
    for(ll i=0; i<n+6; i++)
        visited[i] = false;
 
    for(ll i=0; i<m; i++){
        ll j, k;
        cin >> j >> k;
        addEdge(j, k);
    }
 
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            path[i] = 1;
            dfs(i);
        }
    }
 
    for(auto it:path)
        if(path[it] != 0)
            cout << it << ' ';
 
    return 0;
}
