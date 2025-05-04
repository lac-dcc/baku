#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// #define int long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define allg(x) x.begin(), x.end(), greater<int>()
#define sz(x) (int)x.size()
// #define orderd_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> //find_by_order,find_by_key
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " ";_print(x);cerr << '\n';
#define dbg2(x,y) cerr<<#x<<" ";_print(x);cerr<<"\n"<<#y<<" ";_print(y);cerr<<'\n';
#define dbg3(x,y,z) cerr<<#x<<" ";_print(x);cerr<<"\n"<<#y<<" ";_print(y);cerr<<"\n"<<#z<<" ";_print(z);cerr<<'\n';
#else
#define dbg(x)
#define dbg2(x,y)
#define dbg3(x,y,z)
#endif
template <class T> void _print(T a){cerr << a;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
bool isPowerOfTwo(int n){if (n <= 0){return false;}if (!(n & (n - 1))){return true;}else{return false;}}
bool isPrime(int n){for(int i=2;i*i<=n;i++){if(n%i == 0){return false;}}return true;}
vector<int> sieve(int n){vector<int>ok;vector<int>arr(n+1,0);for(int i=2;i*i<=n;i++){if(arr[i] == 0){ok.push_back(i);for(int j=2*i;j<=n;j+=i){arr[j]=1;}}}return ok;}
int binpow(int a,int b) {a %= mod;int res = 1;while (b > 0){if (b & 1){res = res * a % mod;}a = a * a % mod;b >>= 1;}return res;}
int mod_add(int a,int b){a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a,int b){a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_mul(int a,int b){a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_div(int a,int b){a = a % mod; b = b % mod; return (mod_mul(a,binpow(b,mod-2)) + mod) % mod;}
void solve(){
      int n;
      cin>>n;
      if(n == 1){
            cout<<0<<'\n';return;
      }
      int u,v;
      vector<vector<int>>adj(n+1);
      for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
      }
 
      vector<int>vis(n+1,0);
      int ok=0;
      int node1 = -1;
      function<void(int,int)> dfs1 = [&] (int node,int dist){
            if(dist > ok){
                  ok = dist;
                  node1=node;
            }
            vis[node]=1;
            for(auto it:adj[node]){
                  if(!vis[it]){
                        dfs1(it,dist+1);
                  }
            }
      };
      dfs1(1,0);
      int node2=-1;
      ok=0;
      fill(all(vis),0);
      vector<int>dist1(n+1,0);
      function<void(int,int)> dfs2 = [&](int node,int dist){
            if(dist > ok){
                  ok=dist;
                  node2=node;
            }
            vis[node]=1;
            dist1[node]=dist;
            for(auto it:adj[node]){
                  if(!vis[it]){
                        dfs2(it,dist+1);
                  }
            }
      };
      dfs2(node1,0);
      fill(all(vis),0);
      vector<int>dist2(n+1,0);
      function<void(int,int)> dfs3 = [&](int node,int dist){
            vis[node]=1;
            dist2[node]=dist;
            for(auto it:adj[node]){
                  if(!vis[it]){
                        dfs3(it,dist+1);
                  }
            }
      };
      dfs3(node2,0);
      // cout<<node1<<' '<<node2<<'\n';
      for(int i=1;i<=n;i++){
            cout<<max(dist1[i],dist2[i])<<' ';
      }cout<<'\n';
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
      //https://www.codechef.com/submit/TREECLR
      //https://www.codechef.com/problems-old/QUEENBL
      //https://codeforces.com/contest/161/problem/D
      //https://codeforces.com/contest/1251/problem/C
      //https://codeforces.com/contest/1711/problem/C
}
int32_t main()
{
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      freopen("error.txt", "w", stderr);
      #endif
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
      int t = 1;
      // cin >> t;
      int google=1;
      while (t--)
      {
            // cout<<"Case #"<<google<<": ";
            solve();
            // google++;
      }
      return 0;
}
 
