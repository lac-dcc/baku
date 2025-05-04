#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSOne(S) ((S) & -(S))
 
vi vis;
int n,m;
vector<vi> AL;
 
void dfs(int u){
    vis[u]=1;
    for(auto v : AL[u]){
        if(!vis[v]) dfs(v);
    }
}
void solve()
{
    cin >> n >> m;
    AL.assign(n, vi());
    vis.assign(n, 0);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        AL[u-1].push_back(v-1);
        AL[v-1].push_back(u-1);
    }
    vi toConnect;
    for(int u=0; u<n; u++){
        if(!vis[u]){
            dfs(u);
            toConnect.push_back(u);
        }
    }
    cout<<toConnect.size()-1<<'\n';
    for(int i=0; i<toConnect.size()-1; i++){
        cout<<toConnect[i]+1<<" "<<toConnect[i+1]+1<<'\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
