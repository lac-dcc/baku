#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define F first
typedef vector<int> vi;
 
#define S second
#define for_(i, s, e) for (int i = s; i < e; i++)
const int N = 100013, MOD = 1e9 + 7;
 
#define sp " "
#define pi <pair<int,int>
#define endl '\n'
 
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
 
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
int mod(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return (a + b) % b;
    }
}
//------------------------------------------------------------------------------------------------------
vector<int> f[100015];
void factors()
{
    for (int i = 1; i < 100013; i++)
    {
        for (int j = 1; j <= (100013 / i); j++)
        {
            f[j * i].pb(i);
        }
    }
}
//---------------------------------------------------------------------------------------------------------
 
int lcs(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
 
//-----------------------------------------------------------------------------------------------------
vector<int> pvec;
set<int> huha;
void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
        {
            pvec.pb(p);
            huha.insert(p);
        }
}
 
//---------------------------------------------------------------------------------------------------------------
const int MAXN = 2e6 + 1;
 
int spf[MAXN + 10];
 
void sievee()
{
    for_(i, 2, MAXN + 1)
    {
        spf[i] = i;
    }
 
    for (int i = 4; i <= MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i <= MAXN; i++)
    {
        if (spf[i] != i)
            continue;
        for (int j = i * i; j <= MAXN; j += i)
        {
            if (spf[j] == j)
                spf[j] = i;
        }
    }
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (spf[i] == i)
        {
            pvec.pb(i);
        }
    }
}
 
//---------------------------------------------------------------------------------------------------------
template <typename T, typename F>
struct Segtree
{ // zero indexed
    int n;
    vector<T> tree;
    T identity;
    F merge;
 
    Segtree(const vector<T> &arr, T id, F _m) : n(arr.size()), identity(id), merge(_m)
    {
        tree.resize(2 * n);
        for (int i = 0; i < n; i++)
            tree[n + i] = arr[i];
        for (int i = n - 1; i >= 1; i--)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
 
    T query(int l, int r)
    {
        T res = identity;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
        {
            if (l == r)
                return merge(res, tree[l]);
            if (l & 1)
                res = merge(res, tree[l++]);
            if (!(r & 1))
                res = merge(res, tree[r--]);
        }
        return res;
    }
 
    void update(int v, T value)
    {
        for (tree[v += n] = value; v > 1; v >>= 1)
            tree[v >> 1] = merge(tree[v], tree[v ^ 1]);
    }
};
 
//-----------------------------------------------------------------------------------------------------------
 
// int vis[1002][1002];
// char a[1002][1002];
// int num[1002][1002];
// int now;
// // // //------------------------------------------------------------
// void dfs(int i, int j)
// {
//     if (!vis[i][j])
//     {
//         num[i][j] = now;
//         vis[i][j] = 1;
//         // for(auto j:v[u]){
 
//         if (!vis[i + 1][j])
//         {
//             if (a[i + 1][j] == '#')
//             {
 
//                 dfs(i + 1, j);
//             }
//         }
//         if (!vis[i][j + 1])
//         {
//             if (a[i][j + 1] == '#')
//             {
//                 dfs(i, j + 1);
//             }
//         }
//         if (!vis[i - 1][j])
//         {
//             if (a[i - 1][j] == '#')
//             {
//                 dfs(i - 1, j);
//             }
//         }
//         if (!vis[i][j - 1])
//         {
//             if (a[i][j - 1] == '#')
//             {
//                 dfs(i, j - 1);
//             }
//         }
//         // dis[j]=dis[u]+1;
//         // subtree[u]+=subtree[j];
//         // }
//     }
// }
// int himy=0;
vector<int> v[200013];
int vis[200013], subtree[200013], dis[200013], parent[200013];
int ancestor[200013][25];
void dfs(int u)
{
    if (!vis[u])
 
    {
        // ancestor[u][0]=parent[u];
        vis[u] = 1;
        for (auto j : v[u])
        {
            if (!vis[j])
            {
                dis[j] = dis[u] + 1;
                parent[j] = u;
                dfs(j);
                // subtree[u]+=subtree[j];
            }
            // else if(j!=parent[u] && j==my){
            //     himy=u;
            // }
        }
    }
}
// void preproc(){
 
// }
 
int inverse(int a, int p)
{
    return (binpow(a, MOD - 2, MOD) + MOD) % MOD;
}
// int acb(int a,int b){
 
// }
 
  
    int getKthAncestor(int node, int k) {
        for (int i = 24; i >= 0; i--) {
        if (k & (1 << i)) {
            if (ancestor[node][i] == -1)
                return -1;
            node = ancestor[node][i];
        }
    }
    return node;
    }
void preproc(int n){
    for(int j=1;j<25;j++){
        for(int i=1;i<=n;i++){
            if (ancestor[i][j - 1] != -1) 
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
        }
    }
}
 
//----------------------------------------------------------------------------------------------------------
void solve()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
    dis[i]=0;
    vis[i]=0;
    parent[i]=-1;
    // for(int j=0;j<25;j++){
    // ancestor[i][j]=-1;
    // }
   }
   for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
   }
   dis[1]=0;
   dfs(1);
   int maxi=1,dist=0;
   for(int i=1;i<=n;i++){
    // cout<<dis[i]<<sp;
    if(dis[i]>dist){
        dist=dis[i];
        maxi=i;
    }
    vis[i]=0;
    dis[i]=0;
    parent[i]=-1;
   }
//    cout<<maxi<<endl;
   dis[maxi]=0;
   dfs(maxi);
   int dis2[n+1];
   int dist2=dist,maxi2=1;
   for(int i=1;i<=n;i++){
    if(dis[i]>dist2){
    dist2=max(dist2,dis[i]);
    maxi2=i;
    }
vis[i]=0;
dis2[i]=dis[i];
dis[i]=0;
}
   dfs(maxi2);
   for(int i=1;i<=n;i++){
    cout<<max(dis[i],dis2[i])<<sp;
   }
//    cout<<dist2<<endl;
 
}
 
//------------------------------------------------------------------------------------------------------------
int32_t main()
{
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
    //     freopen("inputtt.txt", "r", stdin);   // file input.txt is opened in reading mode i.e "r"
    // freopen("output.txt", "w", stdout); // file output.txt is opened in writing mode i.e "w"
    int T = 1;
    // factoriall();
    // factors();
    //    sieve(100013);
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
