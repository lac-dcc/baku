#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::deque<ll> di;
typedef std::vector<ll> vi;
typedef std::pair<ll,ll> pr;
typedef std::vector<pr> vii;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repn(i, a, n) for (ll i = a; i < n; i++)
#define all(n) n.begin(), n.end()
#define ios ios_base::sync_with_stdio(0), cin.tie(0)
const ll mod = 1e9 + 7;
const ll INF = 2*1e18 + 100;
const int inf = 2*1e9 + 100;
const ll MOD = 998244353;
 
struct dat{
    ll s,e,r;
};
 
void solve(){
    ll n;cin>>n;
    map<ll,ll> comp;
    vector<dat> vec(n);
    rep(i,n) {
        cin>>vec[i].s>>vec[i].e>>vec[i].r;
        comp[vec[i].s]++,comp[vec[i].e]++;
    }
    ll c =0;
    for(auto it=comp.begin();it!=comp.end();it++){
        it->second=++c;
    }
    vector<vii> pro(c+2);
    rep(i,n){
        pro[comp[vec[i].e]+1].push_back({vec[i].s,vec[i].r});
    }
 
 
    vi dp(c+2,0);
    repn(i,1,c+2) {
        dp[i]=dp[i-1];
 
        for(auto p : pro[i]){
            dp[i] = max(dp[i],dp[comp[p.first]]+p.second);
        }
    }
 
    cout<<dp.back()<<endl;
}
 
 
int main()
{
    ios;
    int t=1;//cin>>t;
    while(t--)
    solve();    
}   
 
 
/*
*/