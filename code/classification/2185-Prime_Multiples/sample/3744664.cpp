#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.h"
#endif
 
#define lsb(x) ((x)&(-x))
#define siz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define setprec(n) cout << fixed << showpoint;cout << setprecision(n);
typedef long long ll;
typedef long double ld;
const ld eps = 1e-9;
const ll MOD1 = 1e9+7;//1000000007
const ll MOD2 = 998244353;
const ll LINF = (ll)1e18;
const int IINF = (int)1e9;
#define int ll
 
 
void solve(){
	int n, k;
	cin >> n >> k;
 
	vector<int> arr(k);
	for(int i = 0;i < k;i++)
		cin >> arr[i];
 
	int ans = 0;
	for(int i = 1;i < (1ll<<k);i++){
		int cnt = 1;
		int say = 0;
		for(int j = 0;j < k;j++){
			if(i&(1ll<<j)){
				say++;
 
				if(n/arr[j] < cnt){
					cnt = n+1;
				}
				else if(n/arr[j] == cnt && cnt*arr[j] == n){
					cnt = n;
				}
				else cnt *= arr[j];
			}
		}
		if(say&1ll) ans += n / cnt;
		else ans -= n / cnt;
	}
 
	cout << ans << "\n";
}
 
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
 
    return 0;
}