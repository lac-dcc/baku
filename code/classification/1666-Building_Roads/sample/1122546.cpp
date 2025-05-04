#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
 
const int INF = 1000000000;
 
#define vi vector<int>
#define ll long long int
#define vvi vector<vi>
#define pi pair<int,int>
#define vp vector<pi>
#define vvp vector<vp>
#define vl vector<ll>
#define vvl vector<vl>
#define pl pair<ll,ll>
#define vpl vector<pl>
 
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define fe first
#define se second
#define all(x) x.begin(),x.end()
 
int n,m;
vector<bool> used(100005,false);
vector<vector<int>> adj(100005,vi(0,0));
 
void dfs(int u){
    used[u] = true;
    for(auto v: adj[u] ){
        if(!used[v])
            dfs(v);
    }
    return;
}
 
int main()
{
    cin >> n >> m;
    int a,b;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi ans;
    for(int i=0;i<n;++i){
        if(!used[i]){
                dfs(i);
                ans.pb(i);
        }
    }
    int tmp = ans.size()-1;
    cout << tmp << endl;
    for(int i=0;i<tmp;++i){
        cout << ans[i]+1 << " " << ans[i+1]+1 << endl;
    }
 
    return 0;
}
