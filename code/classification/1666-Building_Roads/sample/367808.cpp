#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;
int n,m;
ii operator+(const ii& a, const ii& b){
    return {a.x+b.x,a.y+b.y};
}
ii operator-(const ii& a, const ii& b){
    return {a.x-b.x,a.y-b.y};
}
vvi g;
vb check;
void dfs(int cur){
    if (check[cur]) return ;
    check[cur] = 1;
    for(auto nei:g[cur]) dfs(nei);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    g.resize(n); check.resize(n,0);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    int last = -1;
    vii ans;
    loop(i,0,n){
        if (!check[i]){
            dfs(i);
            if (last!=-1) ans.pb({last, i});
            last =  i;
        }
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.x+1<<" "<<p.y+1<<endl;
    return 0;
}
/*
color a
cls
g++ tmp.cpp -o a & a
4 2
1 2
3 4
 
 
*/
 
 
 
 
