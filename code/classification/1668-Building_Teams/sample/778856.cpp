#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;
 
const int mxN=1e5;
vector<int> adj[mxN];
int teams[mxN];
bool works=true;
 
void dfs(int a, int t)
{
    if (teams[a])
        return;
    teams[a]=t;
    for (int x: adj[a]) {
        if (teams[x]==t) {
            works=false;
            return;
        }
        dfs(x, (t%2)+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, a, b;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int i=0; i<n; ++i) {
        if (!teams[i])
            dfs(i, 1);
    } 
 
    if (!works)
        cout << "IMPOSSIBLE";
    else {
        for (int i=0; i<n; ++i)
            cout << teams[i] << ' ';
    }   
    return 0;
}
