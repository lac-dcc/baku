//रख हौसला वो मंजर भी आयेगा; प्यासे के पास चल के समुन्दर भी आयेगा!
// थक कर न बैठ ऐ मंजिल के मुसाफिर; मंजिल भी मिलेगी और मिलने का मज़ा भी आयेगा!
// जो बहाया अपने उस दिन पसीना उसका परिणाम तिंकर तींकर आयेगा ।
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ins insert
#define len(s) s.length()
#define forp(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define ren(i, n) for (int i = n - 1; i >= 0; i--)
#define forn(i, a, b) for (int i = a; i >= b; i--)
#define on cout << endl
#define all(v) v.begin(), v.end()
#define mem(n, m) memset(n, m, sizeof(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sii set<int>
#define us unordered_set<int>
#define um unordered_map<int, int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ret return 0
 
#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999
#define siz 100001
#define SIZ 1000001
#define SIZE 200001
 
typedef long long ll;
typedef long double ldo;
typedef double db;
using namespace std;
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
 
#define setpre fixed << setprecision(10)
//Arise,Awake and stop not till the goal is reached... :)
 
void c_p_c()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<int> adj[200002];
vector<int> vis(200002, false);
vector<bool> coll(200002, false);
 
bool dfs(int curr_node, int col)
{
    vis[curr_node] = true;
    coll[curr_node] = col;
    for (auto x : adj[curr_node])
    {
        if (!vis[x])
        {
            if (!dfs(x, col ^ 1))
                return false;
        }
        else
        {
            if (coll[x] == coll[curr_node])
            {
                return false;
            }
        }
    }
    return true;
}
 
int main()
{
    c_p_c();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    coll.resize(n, false);
    vis.resize(n, false);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false && dfs(i, 0) == false)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    for (int i = 0; i < n; i++)
    {
        cout << coll[i] + 1 << " ";
    }
 
    return 0;
}
// noob hu mae
