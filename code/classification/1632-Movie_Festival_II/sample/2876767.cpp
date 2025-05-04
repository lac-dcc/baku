#include <bits/stdc++.h>
// #define int long long
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ti tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) (((a)+(b)-1)/(b))
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define dbg(msg, var) cerr << msg << " " << var << endl;
 
using namespace std;
 
const int MAX = 2e5+10;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-8;
const ld PI = acos(-1);
 
// End Template //
 
int32_t main()
{sws;
 
    int n, k, l, r;
    cin >> n >> k;
 
    vii swp;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        swp.pb({r, -l});
    }
 
    sort(swp.begin(), swp.end());
 
    multiset<int> pessoas;
    for(int i=0;i<k;i++)
        pessoas.insert(-1);
    int ans = 0;
    for(int i=0;i<n;i++){
        auto [r, l] = swp[i]; l = -l;
        auto it = pessoas.upper_bound(l);
        if(it == pessoas.begin()) continue;
        pessoas.erase(prev(it));
        ans++;
        pessoas.insert(r);
    }
 
    cout << ans << endl;
 
 
 
    return 0;
}
