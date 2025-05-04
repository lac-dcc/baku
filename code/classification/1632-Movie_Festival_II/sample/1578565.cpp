#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define deb(x) cout<<#x<<"="<<x<<endl;
#define test int T;cin>>T;while(T--)
using namespace std;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int N   = 200500;
 
int n, k;
 
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
 
signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> n >> k;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(all(a), comp);
        multiset<int> ms;
        for (int i = 1; i <= k; i++) {
            ms.insert(0);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto it = ms.lower_bound(a[i].first);
            if (it != ms.begin()) {
                it--;
            }
            if (*it < a[i].first) {
                ms.erase(it);
                ms.insert(a[i].second - 1);
                ans++;
            }
        }
        cout << ans;
        return 0;
}