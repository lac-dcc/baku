#include<bits/stdc++.h>
 
typedef long long ll;
typedef std::pair<int, int> pii;
 
#define fi first
#define se second
#define pp push_back
#define inarr(n, arr) for(int ax = 0; ax<(n); ax++)cin>>(arr)[ax];
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(),(x).rend()
#define Ones(n) __builtin_popcount(n)
#define endl '\n'
#define PI acos(-1)
#define sin(a) sin((a)*PI/180)
#define cos(a) cos((a)*PI/180)
#define tan(a) tan((a)*PI/180)
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define int long long
using namespace std;
 
void Gamal() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
 
const double EPS = 1e-9;
const ll N = 2e5 + 5, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;
 
void solve() {
    ll n,c;cin >> n >> c;
    vector<int>a((n+1)/2);
    vector<int>b(n/2);
    for (int i = 0; i < (n+1)/2; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n/2; ++i) {
        cin >> b[i];
    }
    vector<ll>subs;
    for (int i = 0; i < 1<<(a.size()); ++i) {
        ll sum = 0;
        for (int j = 0; j < a.size(); ++j) {
            if(i&(1<<j)){
                sum += a[j];
            }
        }
        subs.pp(sum);
    }
    sort(all(subs));
    ll ans = 0;
    for (int i = 0; i < 1<<(b.size()); ++i) {
        ll sum = 0;
        for (int j = 0; j < b.size(); ++j) {
            if(i&(1<<j)){
                sum += b[j];
            }
        }
        ans += upper_bound(all(subs),c-sum) - lower_bound(all(subs),c-sum);
    }
    cout<<ans;
 
}
 
 
signed main() {
    Gamal();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
