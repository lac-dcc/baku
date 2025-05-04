///sat
#include <chrono>
using namespace std::chrono;
#define vremestart auto start = high_resolution_clock::now();
#define vremeend auto stop = high_resolution_clock::now();
#define vremeispis auto duration = duration_cast<microseconds>(stop - start); cout << duration.count() << endl;
///sat
#define here cerr<<"here\n";
#define popcount(x) __builtin_popcount(x) ///broji broj bitova
#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned long long
#define llinf 1000000000000000000LL
#define iinf 2000000000
#define pb push_back
#define popb pop_back
#define fi first
#define sc second
#define th third
#define fo fourth
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define rall(a) a.begin(),a.end(),greater<int>()
using namespace std;
void setIO(string inoutname)
{
	freopen((inoutname+".in").c_str(),"r",stdin);
    	freopen((inoutname+".out").c_str(),"w",stdout);
}
#define maxn 200005
ll n;
ll par[maxn];
vector<int> g[maxn];
ll ans[maxn];
ll dfs(ll u,ll p){
    ll sub = 0;
    for(ll s : g[u]){
        if(s!=p){
            sub += dfs(s,u) + 1;
        }
    }
    ans[u] = sub;
    return sub;
}
int main(){
	ios_base::sync_with_stdio(false);cerr.tie(0);cout.tie(0);cin.tie(0);
	//setIO("lol");
	cin >> n;
	for(int i = 2;i<=n;i++){
        ll x; cin >> x;
        par[i] = x;
        g[x].pb(i);
	}
    dfs(1,-1);
    for(int i = 1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
