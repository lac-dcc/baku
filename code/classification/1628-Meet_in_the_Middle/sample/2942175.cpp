#include <bits/stdc++.h>
 
#define FOR(i,x,n) 	for(int i=x; i<n; i++)
#define F0R(i,n) 	FOR(i,0,n)
#define ROF(i,x,n) 	for(int i=n-1; i>=x; i--)
#define R0F(i,n) 	ROF(i,0,n)
 
#define WTF 		cout << "WTF" << endl
 
#define IOS 		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define F 			first
#define S	 		second
#define pb 			push_back
 
#define ALL(x) 		x.begin(), x.end()
#define RALL(x) 	x.rbegin(), x.rend()
 
using namespace std;
typedef double 			DB;
typedef long long 		LL;
typedef string 			STR;
 
typedef pair<int, int> 	PII;
typedef pair<LL, LL> 	PLL;
 
typedef vector<int> 	VI;
typedef vector<LL> 		VLL;
typedef vector<bool> 	VB;
typedef vector<char> 	VC;
typedef vector<PII> 	VPII;
typedef vector<PLL> 	VPLL;
typedef vector<string> 	VSTR;
 
typedef set<int> 		SI;
typedef set<PII> 		SPII;
typedef set<PLL> 		SPLL;
 
const int MAXN = 2e5 + 7;
const int ALPHA = 40;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
const int BASE[2] = {313, 239};
 
LL n, x;
LL ns[45];
VLL left_made, right_made;
 
void in_middle(int now_on, int endpoint, LL sum, char part) {
    if (now_on == endpoint) {
        if (part == 'L') left_made.pb(sum);
        else right_made.pb(sum);
        return;
    }
 
    in_middle(now_on - 1, endpoint, sum + ns[now_on], part);
    in_middle(now_on - 1, endpoint, sum, part);
 
    return;
}
 
void solve() {
    cin >> n >> x;
    int mid = (n >> 1);
    F0R(i, n) cin >> ns[i];
 
    in_middle(mid, -1, 0, 'L');
    in_middle(n - 1, mid, 0, 'R');
 
    sort(ALL(left_made));
    sort(ALL(right_made));
    
    LL ans = 0;
    for(LL on : left_made) {
        if (!binary_search(ALL(right_made), x - on)) continue;
        ans += upper_bound(ALL(right_made), x - on) - lower_bound(ALL(right_made), x - on);
    }
 
    cout << ans << endl;
}
 
int main() {
    IOS;
    solve();
}       
