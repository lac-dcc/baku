#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "," << #y << "=" << y << endl
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
 
vector<int> edge[100005];
bool vis[100005];
int parent[100005];
vector<int> ans;
int strt, end1;
bool detectCycle(int v, int par)
{
    vis[v] = true;
    parent[v] = par;
    for (int i = 0; i < edge[v].size(); ++i)
    {
        int child = edge[v][i];
        if (!vis[child])
        {
            if (detectCycle(child, v))
                return true;
        }
        else if (par != child)
        {
            end1 = child;
            strt = v;
            return true;
        }
    }
    return false;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            if (detectCycle(i, -1))
            {
                flag = true;
                break;
            }
        }
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
 
    ans.push_back(end1);
    ans.push_back(strt);
    while (1)
    {
        strt = parent[strt];
        ans.push_back(strt);
        if (strt == end1)
            break;
    }
 
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin>>t;
    // int c = 1;
    // while(t--){
    // cout<<"Case "<<c++<<": ";
    solve();
    //}
    return 0;
}
