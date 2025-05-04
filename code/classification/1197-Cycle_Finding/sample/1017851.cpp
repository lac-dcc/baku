#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long
#define FOR(i,a,b)       for(ll i = a; i < b; ++i)
#define REV(i,a,b)       for(ll i = a; i >= b; i--)
#define F                first
#define S                second
#define pb               push_back
#define all(v)           v.begin(),v.end()
#define mod              1000000007 
 
constexpr ll inf = (1LL << 60); 
 
void solve()
{
    ll n, m;
    cin >> n >> m;
 
    vector<tuple<ll, ll, ll>> edges(m);
 
    ll a, b, wt, x;
    FOR(i, 0, m) {
        cin >> a >> b >> wt;
        a--, b--;
        edges[i] = {a, b, wt};
    }
    
    vector<ll> d(n), pre(n, -1);
    
    FOR(i, 0, n) {
        x = -1;
        for(tuple<ll, ll, ll> e : edges) {
            tie(a, b, wt) = e;
            if(d[b] > d[a] + wt) {
                d[b] = d[a] + wt;
                pre[b] = a;
                x = b;
            }
        }
    }
 
    if(x == -1) { 
        cout << "NO\n"; 
    } else {
 
        FOR(i, 0, n) x = pre[x];
 
        vector<ll> cycle;
        for(ll v = x; ; v = pre[v]) {
            cycle.pb(v);
            if(v == x && cycle.size() > 1) { break; }
        }
 
        reverse(all(cycle));
 
        cout << "YES\n";
        for(auto v : cycle) cout << v+1 << " ";
        cout << "\n";
    }
}  
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);    cout.tie(NULL);
 
    int test_cases = 1;
  //cin >> test_cases;
    while(test_cases--) {  solve();  }
 
  return 0;
}
