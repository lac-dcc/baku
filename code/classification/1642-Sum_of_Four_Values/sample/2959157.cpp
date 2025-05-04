#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define pq priority_queue
#define minele min_element
#define maxele max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define cnt_bit __builtin_popcount
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#pragma GCC optimize("Ofast")
//#pragma GCC target("fma")
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
 
int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
 
const ll oo = 1e18;
const ll maxN = 1e6;
 
/* Author : Le Ngoc Bao Anh, 10A5, LQD High School for Gifted Student */
 
void maximize(int &a, int b) {
    a = max(a, b);
}
 
void minimize(int &a, int b) {
    a = min(a, b);
}
 
const int N = 2e5 + 10;
map<int, pii> pos;
int a[N];
 
void solve() {
	int n; int x;
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	for(int i = n; i >= 1; i--) {
		for(int j = i + 1; j <= n; j++) {
			int sum = a[i] + a[j];
			if(!pos[sum].fi) pos[sum] = make_pair(i, j);
		}
	}
 
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int sum = a[i] + a[j];
			if(sum >= x) continue;
			if(pos[x - sum].fi <= j) continue;
			cout << i << " " << j << " " << pos[x - sum].fi << " " << pos[x - sum].se;
			return;
		}
	}
 
	cout << "IMPOSSIBLE";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    //online
    #endif
 
    int tc = 1, ddd = 0;
    // cin >> tc;
    while(tc--) {
        //ddd++;
        //cout << "Case #" << ddd << ": ";
        solve();
    }
}
