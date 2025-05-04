/* MGod. */
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
void solve() {
	int n, x; cin >> n >> x;
	vector<int> an;
	for(int i=0;i<n;i++){ int j; cin >> j; an.pb(j); };
	sort(an.begin(),an.end());
	int a[x+1]; for(int i=0;i<=x;i++) a[i] = 0;
	a[0] = 1;
	for(int m : an){
		for(int i=1;i<=x;i++){
			if(i - m >= 0){
				a[i] += a[i-m];
				a[i] %= (int)1e9+7;
			}
		}
	}
	// for(int i=0;i<=x;i++) cout << a[i] << endl;
	cout << a[x] << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t=1;
	for(int i=0;i<t;i++) solve();
}
