#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector< vector <int>>;
using vl = vector<ll>;
using vll = vector< vector <ll>>;
using vpi = vector <pair <int, int>>;
using vpl = vector <pair <ll, ll>>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define loop(i,n) for(int i = 0;i<n;i++)
#define loop1(i,n) for(int i = 1;i<n;i++)
#define loopx(i, x, n) for(int i = x; i<n; i++);
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
 
 
 
 
int main() {
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    
    int n, m;
    cin >> n >> m;
    vii adj(n);
    loop(i, m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int a = 0, b = n-1;
    vi seen(n);
 
    vi fromWhere(n, -1);
    queue <pair<int, int>> q;
    q.push({a, a});
    while(q.size()){
        auto p = q.front();
        q.pop();
        if(seen[p.ff]) continue;
        seen[p.ff] = 1;
        fromWhere[p.ff] = p.ss;
        for(auto x : adj[p.ff]){
            q.push({x, p.ff});
        }
    }
 
    if(fromWhere[b]==-1) cout << "IMPOSSIBLE" << endl;
    else{
        vi ans;
        ans.pb(b);
        while(ans.back() != a){
            ans.pb(fromWhere[ans.back()]);
        }
        reverse(all(ans));
        cout << ans.size()<< endl;
        for(auto x : ans) cout << x+1 << " ";
            cout << endl;
    }
 
 
    
 
 
    return 0;
 
}
 
 
 
 
 
