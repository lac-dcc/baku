#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vpp vector<pair<int,int>> 
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define frr(i,a,b) for(int i=(int)a;i>=(int)b;--i)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define ff first
#define ss second
#define in insert
#define dbg(x) cout << #x << " = " << x << endl ;
#define rd(n) int n ; cin >> n ; 
#define nl "\n"
#define bs binary_search
#define setbits(n) __builtin_popcount((int)n)
// #define mod 998244353
#define vti(a,n) vi a(n) ; fr(i,0,n) cin >> a[(int)i] ; 
const int N = 1e9 + 7 ;
 
void rec(int curr, int par, vector<vi> &adj, vi &levels){
    if(par == -1) levels[curr] = 0 ;
    for(auto it : adj[curr]){
        if(it != par){
            levels[it] = levels[curr] + 1 ;
            rec(it,curr,adj,levels) ;
            // dbg(ans[it])
            // sum += ans[it] ;
        }
    }
    // ans[curr] = sum ;
}
 
int32_t main(){
    fast_io ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while(t--){
        rd(n)
        vector<vector<int>> adj(n,vi(0)) ;
        for(int i = 1 ; i < n  ; i++){
            rd(a) ; rd(b)
            adj[b-1].pb(a-1) ;
            adj[a-1].pb(b-1) ;
        }
        vector<int> levels(n) ;
        rec(0,-1,adj,levels) ;
        int maxL = -1 , maxNode ;
        fr(i,0,n){
            if(levels[i] > maxL){
                maxL = levels[i] ;
                maxNode = i ;
            }
        }
        vi level2(n) ;
        rec(maxNode,-1,adj,level2) ;
        cout << mx(level2) ;
    }   
}
