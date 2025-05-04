#include <bits/stdc++.h>
//#include<random>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("O3")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef map<ll, ll> mll;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int iINF=INT_MAX;
const ll INF=LLONG_MAX;
const ld PI=3.14159265358979323846;
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
ll fpow(ll a,ll b,ll m) {
    if(!b) return 1;
    ll ans=fpow(a*a%m,b/2,m);
    return (b%2?ans*a%m:ans);
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define dbg(n) cerr<<#n<<": "<<n<<"\n";
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define irep(i,m,n) for(ll i=m;i>=n;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pow2(a) (1LL<<a)
#define fixset(ans, n) fixed<<setprecision(n)<<(ld)ans<<endl
const int N=2e5+5;
int n, m;
vector<int> G[N];
vector<int> ans;
bool vis[N];
int grp[N];
bool ok=1;
void dfs(ll st) {
    vis[st]=true;
    for(auto u:G[st]) {
        if(vis[u] && (grp[st]+1)%2!=grp[u]) {
            ok=0;
            //dbg(st); dbg(u);
        }
        if(!vis[u]) {
            grp[u]=(grp[st]+1)%2;
            dfs(u);
        }
    }
}
void check() {
 
}
void solve() {
    memset(vis, false, sizeof(vis));
    cin>>n>>m;
    rep1(i, n) grp[i]=-1;
    rep(i,m) {
        int x, y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    grp[1]=1;
    rep1(i, n) if(!vis[i]) {
        grp[i]=1;
        dfs(i);
    }
    if(!ok) cout<<"IMPOSSIBLE\n";
    else {
        rep1(i, n) cout<<(grp[i]==0?2:1)<<" ";
        cout<<"\n";
    }
}
 
 
signed main() {
    IOS
    int T;
    T=1;
    while(T--) solve();
}
/*
5 3
1 2
1 3
4 5
*/
