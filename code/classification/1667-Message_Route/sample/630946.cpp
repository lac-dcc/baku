#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PI 2*acos(0.0)
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pii pair<int, int>
#define mem(x,y) memset(x, y, sizeof(x))
#define ar array
 
const ll INF = 1e5;
const int mod = 1e9 + 7;
const int mxN = 1e5;
using namespace std;
int n, m, p[mxN];
vector<int> adj[mxN], ans;
 
void solve(){
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++){
        cin >> a>> b, --a, --b  ;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    mem(p, -1);
    queue<int>q;
    q.push(0);
    p[0] = -2;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(p[v] < 0){
                p[v] = u;
                q.push(v);
            }
        }
 
    }
    if(p[n-1] < 0){
        cout << "IMPOSSIBLE\n";
    }
    else{
        int u = n-1;
        while(u){
            ans.push_back(u);
            u = p[u];
        }
        ans.push_back(0);
        reverse(all(ans));
 
        cout << ans.size() << "\n";
        for(auto x: ans)
            cout << x+1 << " ";
    }
 
}
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    int t; cin >> t;
    while(t--){
        solve();
}*/
    solve();
}
