#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lng long long
#define pb push_back
#define rtr return 0
#pragma GCC optimize("Ofast","unroll-loops")
const int SZ=2e5+7,MOD=1e9+7;
int n;
pair<int,int>mx={-1e9,-1e9};
vector<int>adj[SZ];
void dfs(int nd,int d=0,int pr=-1){
    mx=max(mx,{d,nd});
    for(auto i:adj[nd]){
        if(i==pr)continue;
        dfs(i,d+1,nd);
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt=1;
    //cin >> tt;
    while(tt--){
        cin >> n;
        for(lng i=2;i<=n;i++){
            int x,y;cin >> x >> y;
            adj[x].pb(y);adj[y].pb(x);
        }
        dfs(1);
        dfs(mx.second);
        cout << mx.first;
    }
 return 0;
}
