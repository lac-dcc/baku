#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define int long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pr pair<int, int>
#define ff first
#define ss second
#define pie 3.1415926535898
#define inf LLONG_MAX
#define co(n) __builtin_popcount(n)
#define cz(n) __builtin_ctz(n)
const int M=1e9+7;
int mult(int a, int b, int p = M)
{
    return ((a % p) * (b % p)) % p;
}
int add(int a, int b, int p = M) { return (a % p + b % p) % p; }
int neg(int a, int p = M) { return (p - (a % p)) % p; }
int sub(int a, int b, int p = M) { return add(a, neg(b)); }
int fpow(int x, int y)
{
    int res = 1;
    x = x % M;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1LL)
            res = (res * x) % M;
        y = y >> 1LL;
        x = (x * x) % M;
    }
    return res;
}
int inv(int a, int p = M) { return fpow(a, p - 2); }
 
class DSU
{
public:
    vector<int> par, size;
    DSU(int n)
    {
        par = vector<int>(n);
        size = vector<int>(n);
 
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }
 
    int find(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
 
    bool is_joined(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
 
        if (pa == pb)
            return 1;
 
        if (size[pa] <= size[pb])
        {
            par[pa] = pb;
            size[pb] += size[pa];
        }
        else
        {
            par[pb] = pa;
            size[pa] += size[pb];
        }
 
        return 0;
    }
};
 
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool valid(int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}
#define maxn 500005
 
vector<bool> isprime(1e9 + 1, true);
void prime()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= 1e9; i++)
    {
        if (isprime[i] && i * i <= 1e9)
        {
            for (int j = i * i; j <= 1e9; j += i)
                isprime[j] = false;
        }
    }
}
 
bool ispalin(string s)
{
    int n = s.length(), l;
    if (n == 1)
        return true;
    if (n % 2 == 0)
        l = n / 2 - 1;
    else
        l = (n - 1) / 2 - 1;
    for (int i = 0; i <= l; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}
 
void printprime(int n)
{
    int c = 1;
    for (int x = 2; c <= n; x++)
    {
        if (isprime[x])
        {
            cout << x << " ";
            c++;
        }
    }
    cout << "\n";
}
 
bool cprime(int x)
{
    if (x == 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(x); i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}
 
map<int,int>m;
int dfs(vector<vector<int>>& t,int node,int parent)
{
    m[node]=0;
    for(int nbr:t[node])
    {
        if(nbr!=parent)
        {
            m[node]+=(1+dfs(t,nbr,node));
        }
    }
    return m[node];
}
void solve()
{
    int n;cin>>n;
    vector<vector<int>>t(n+1);
    m.clear();
    for(int i=2;i<=n;i++)
    {
        int par;cin>>par;
        t[par].push_back(i);
        t[i].push_back(par);
    }
 
    dfs(t,1,0);
    for(auto &x:m)
    cout<<x.ss<<" ";
}
 
signed main()
{
    fio
        // prime();
        int t;
     t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
