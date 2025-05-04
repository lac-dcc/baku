#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = int(2e5 + 5);
int n;
 
int  fin[MAXN];
int fout[MAXN];
vector<int> adj[MAXN];
 
void maximize(int &a, const int &b)
{
    if (a < b) a = b;
}
void enter()
{
    int u, v;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
 
void dfsIn(int par, int u)
{
//    cerr << u << " ";
    fin[u] = 0;
    for (auto v: adj[u])
    {
        if (v == par) continue;
        dfsIn(u, v);
        maximize(fin[u], fin[v] + 1);
    }
}
 
void dfsOut(int par, int u)
{
    int maxVal = -1;
    int secondVal = -1;
    bool isDouble = false;
    for (auto v: adj[u])
    {
        if (v == par) continue;
        if (maxVal < fin[v])
        {
            secondVal = maxVal;
            maxVal = fin[v];
            isDouble = false;
            continue;
        }
        if (maxVal == fin[v])
        {
            isDouble = true;
            continue;
        }
        if (secondVal < fin[v])
        {
            secondVal = fin[v];
            continue;
        }
    }
 
    for (auto v: adj[u])
    {
        if (v == par) continue;
        if (fin[v] == maxVal && isDouble == false)
            if (secondVal <= 0) fout[v] = fout[u] + 1;
        else
            fout[v] = max(fout[u] + 1, secondVal + 2);
        else fout[v] = max(fout[u] + 1, maxVal + 2);
        dfsOut(u, v);
    }
}
 
void solve()
{
    dfsIn (-1, 1);
//    cerr << "\n";
//    for (int i = 1; i <= n; i++) cerr << fin[i] << " ";
//    cerr << "\n";
    dfsOut(-1, 1);
    int maxDis = 0;
    for (int i = 1; i <= n; i++)
        cout << max(fout[i], fin[i]) << " ";
 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    enter();
    solve();
 
}
