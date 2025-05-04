/*  ** IN THE NAME OF ALLAH (SWT) **   */
 
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e5 + 10;
 
vector <int> g[E];
vector <int> depth(E, 0), subs(E, 0);
void dfs(int cur)
{
    subs[cur] = 1;
    for(int v : g[cur]){
        depth[v] = depth[cur] + 1;
        dfs(v);
        subs[cur] += subs[v];
    }
}
int main()
{
    int N; cin>> N;
 
    for(int i = 1;i < N;i++){
        int par; cin>> par; --par;
        g[par].pb(i);
    }
    dfs(0);
    for(int i = 0;i < N;i++) {
        cout<< subs[i] - 1 << ' ';
    }
}
