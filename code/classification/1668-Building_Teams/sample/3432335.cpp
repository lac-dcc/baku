//CP TEMPLATE
#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define int long long
#define FOR(i,a,n) for(int(i) = (a); (i) < (n); (i)++)
#define FORI(i,a,n,f) for(int(i) = (a); (i) < (n); (i) += (f))
#define FORD(i,n,a,f) for(int(i) = (n); (i) > (a); (i) -= (f))
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define pln cout << endl 
#define print2(a,b) cout<<(a)<<" "<<(b); pln
#define print(a) cout<<(a); pln
#define printv(v) for(auto n : v) cout << n << " "; pln
#define in(n) int n; cin>>n
#define inarr(n) int n; cin>>n; int arr[n];FOR(i,0,n) cin >> arr[i]
#define ins(s) string s; cin>>s
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define tc  int t; cin >> t;while(t--)
 
using namespace std;
 
 
 
void solve(){   
    in(n);in(m);
    vector<int> g[n+1];
    vector<int> col(n+1,-2);
    FOR(i,0,m){
        in(a);in(b);g[a].pb(b);g[b].pb(a);
    }
    int im = 0;
    function<void(int,int)> dfs = [&](int v, int cc){
        col[v] = cc;
        for(auto c: g[v]){
            if(col[v] == col[c]){
                im = 1;
                return;
            }  
            if(col[c] > -2) continue;
            dfs(c, !cc);
            
        }
    };
    FOR(i,1,n+1){
        if(col[i] == -2)
        dfs(i,0);
    }
    if(im)
        {print("IMPOSSIBLE");}
    else{
        FOR(i,1,n+1) cout << col[i]+1 << " "; pln;
    }
}
 
signed main() {
    IOS;
    // tc
    solve();
}
