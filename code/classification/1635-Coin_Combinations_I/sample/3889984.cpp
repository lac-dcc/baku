#include <bits/stdc++.h>
using namespace std; 
 
#define tc int tt; cin >> tt; while(tt--)
#define gtc int t, tt = 1; cin >> t; for(tt; tt <= t; tt++)
#define gprinttest cout << "Case #" << tt << ": "
 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<int, int>> vii;
typedef vector<pair<int, char>> vic;
typedef vector<pair<char, int>> vci;
typedef vector<pair<char, char>> vcc;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<char>> vvc;
typedef deque<int> dqi;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef set<int> si;
typedef set<char> sc;
typedef multiset<int> msi;
typedef multiset<char> msc;
typedef priority_queue<int> maxhi;
typedef priority_queue<ll> maxhll;
typedef priority_queue<pii> maxhii;
typedef priority_queue <int, vector<int>, greater<int>> minhi;
typedef priority_queue <ll, vector<ll>, greater<ll>> minhll;
typedef priority_queue <pii, vector<pii>, greater<pii>> minhii;
 
const int inf = INT_MAX;
const ll llinf = LLONG_MAX;
const int mod = 1000000007;
// const int mod = 998244353;
const int N = 4e4;
const ld pi = 3.1415926535;
 
#define nline "\n"
#define rep(x) for(int i = 0; i < x; i++)
#define rep_u(i, a, b) for(int i = a; i < b; i++)
#define rep_d(i, a, b) for(int i = a; i >= b; i--)
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pcnt(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)  
#define prec(x) setprecision(x) << fixed  
 
void solve(){  
    int n, x;
    cin >> n >> x;
    vi dp(x + 1, 0), arr(n);
    rep_u(i, 0, n) cin >> arr[i];
    sort(all(arr));
    dp[0] = 1;
    rep_u(i, 1, x + 1){
        for(int j:arr){
            if(j <= i){
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }else break;
        }
    }
    cout << dp[x];
    return;
}
 
 
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
 
    // tc
    {
        solve();
    }
    return 0;
}