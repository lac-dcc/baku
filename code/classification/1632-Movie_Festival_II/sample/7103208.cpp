#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;
 
int n, k;
multiset <int> last;
vector <pair <int,int>> vp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        vp.push_back({b, a});
    }
    sort(vp.begin(), vp.end());
    int mx = 0;
    for (int i=0; i<k; ++i)
        last.insert(0);
    for (int i=0; i<n; ++i) {
        auto it = last.upper_bound(vp[i].se);
        if (it == last.begin())
            continue;
        last.erase(--it);
        last.insert(vp[i].fi);
        ++mx;
    }
    cout << mx;
 
    return 0;
}
