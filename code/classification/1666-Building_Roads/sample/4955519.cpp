#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pll pair<long long int, long long int>
#define vll vector<long long int>
#define f first
#define s second
#define mod 1000000007
#define rep(i, a, b) for (long long int i = a; i < b; ++i)
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define pb push_back
 
const ll N = 100005;
ll n, m;
vll A[N];
bool vis[N];
ll Xaxis[4] = {1, -1, 0, 0};
ll Yaxis[4] = {0, 0, 1, -1};
string Dir = "DURL";
 
void DFS(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    for (auto u : A[x])
        DFS(u);
}
 
void connect(vll *A, ll x, ll y)
{
    A[x].pb(y);
    A[y].pb(x);
}
 
void Solve()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    vll Ans;
 
    rep(i, 0, m)
    {
        ll x, y;
        cin >> x >> y;
        connect(A, x, y);
    }
 
    rep(i, 1, n + 1) 
        if (!vis[i])
            {
                Ans.pb(i);
                DFS(i);
            }
 
    cout << Ans.size() - 1 << "\n";
    rep(i, 0, Ans.size() - 1)
        cout << Ans[i] << " " << Ans[i + 1] << "\n";
}
 
int main()
{
    FIO;
    Solve();
 
    return 0;
}
