/* Hardwork beats talent */
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define mpi map<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define en "\n"
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define fe(it, x) for (auto it : x)
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, a, b) for (int i = (a); i >= (b); i--)
const ll mod = 1e9 + 7;
 
int sv, ev;
 
bool dfs(int i, int parent, vi &vis, vi adj[], vi &p)
{
    vis[i] = 1;
    p[i] = parent;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            if (dfs(it, i, vis, adj, p) == true)
            {
                return true;
            }
        }
        else if (it != parent)
        {
            sv = it;
            ev = i;
            return true;
        }
    }
 
    return false;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vi adj[n + 1];
 
    f(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
 
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    vi vis(n + 1, 0), p(n + 1, -1);
    f(i,1,n+1)
    p[i]=i;
 
    bool check = false;
    
    f(i, 1, n + 1)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj, p) == true)
            {
                check = true;
                break;
            }
        }
    }
    // cerr<<sv<<" "<<ev<<en;
 
    if (!check)
        cout << "IMPOSSIBLE" << en;
    else
    {
        int vertex = ev;
        vi ans;
        ans.pb(ev);
        while (vertex != sv)
        {
            ans.pb(p[vertex]);
            vertex = p[vertex];
        }
        ans.pb(ev);
 
        cout << sz(ans) << en;
        for (auto it : ans)
            cout << it << " ";
    }
}
