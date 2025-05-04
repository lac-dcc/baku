#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int  long long
#define mod 1000000007
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = a * 1ll * a % mod;
            p /= 2;
        }
        else
        {
            res = res * 1ll * a % mod;
            p--;
        }
    }
    return res;
}
int lcm(int x, int y) {
    return (x * y) / (__gcd(x, y));
}
vector<int>sz;
vector<int>par;
int findPar(int u) {
    return (u == par[u] ? u : par[u] = findPar(par[u]));
}
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1) {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
/*
    vector<vector<int>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
    smallest prime factor
    vector<int>primes;
    vector<int>isprime(N + 1, 1);
    for (int i = 2; i <= N; i++)
    {
        if (isprime[i] == 1) {
            isprime[i] = i;
            for (int j = i * i; j <= N; j += i) {
                if (isprime[j] == 1)isprime[j] = i;
            }
        }
    }
*/
vector<vector<int>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
void dfs(int r, int c, vector<vector<bool>>&vis, vector<string>&v) {
    int n = v.size(), m = v[0].length();
    vis[r][c] = true;
    for (int d = 0; d < dir.size(); d++) {
        int fr =  r + dir[d][0];
        int fc = c + dir[d][1];
        if (fr >= 0 and fc >= 0 and fr < n and fc < m and !vis[fr][fc] and v[fr][fc] == '.') {
            dfs(fr, fc, vis, v);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string>v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v[i].length(); j++) {
                if (v[i][j] == '.' and !vis[i][j]) {
                    count++;
                    dfs(i, j, vis, v);
                }
            }
        }
        cout << count << endl;
    }
 
}
