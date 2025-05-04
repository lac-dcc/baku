/*
              __________
             |\         \
             | \         \
             |  \_________\
             |  |         |
   __________|  | (O)     |
  /          \  |         |
  |           \ |         |
   \___________\|_________|
    \                     |
     \                    |
      \                   |
       |                  |
       |__________________|
*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007  
#define pii pair<ll,llt>
#define float long double
#define NMAX 200005
using namespace std;
ll n,a[NMAX],child[NMAX];
vector<ll>adj[NMAX];
void dfs(ll u,ll par) {
    for (ll v:adj[u])
        if (v != par) {
            dfs(v,u);
            child[u]+=child[v]+1;
        }
}
int main() {
    cin>>n;
    for (ll i=2;i<=n;i++) {
        ll par;
        cin>>par;
        adj[par].push_back(i);
    }
    dfs(1,0);
    for (ll i=1;i<=n;i++)
        cout<<child[i]<<" ";
    return 0;
}
