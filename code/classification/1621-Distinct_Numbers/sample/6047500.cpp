#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef priority_queue<pair<ll, ll>> q;
typedef vector<pair<ll, ll>> vp;
typedef map<ll, ll> mp;
typedef set<ll> st;
typedef multiset<ll> mst;
typedef map<ll, vector<ll>> mpx;
#define mod 1000000007 // 1e9+7
const ll mx = 10;
void solve()
{
    ll n; st s;cin >> n;
    for (ll i = 0; i < n; i++){ll x;cin >> x; s.insert(x);}cout<<s.size()<<endl;
}
int main()
{
    // sharowcin();
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}
// main();
