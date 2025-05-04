#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_fornt
#define fi first
#define se second
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxN = 1e6 + 68;
ll n,k;
ll a[200001],b[200001];
pair<ll,ll> p[200001];
int main() {
	//freopen("TEST.INP","r",stdin);
	//freopen("TEST.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> p[i].se >> p[i].fi;
    sort(p + 1,p + n + 1);
    for(int i = 1;i <= n;i++) {
    	a[i] = p[i].se;
    	b[i] = p[i].fi;
	}
	multiset<ll,greater<ll>> s;
	ll dem = 0;
	for(int i = 1;i <= n;i++) {
		if(s.empty()) s.insert(b[i]),dem++;
		else {
            auto it = s.lower_bound(a[i]);
            if(it != s.end()) {
                dem++;
                s.erase(it);
                s.insert(b[i]);
            }
            else {
                if(s.size() < k) {
                    s.insert(b[i]);
                    dem++;
                }
            }
		}
	}
	cout << dem;
    return 0;
}
