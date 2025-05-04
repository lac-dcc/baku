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
const int N   = 500500;
 
map<int, vector<pair<int, int> > > mp;
 
signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n, x;
        cin >> n >> x;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                mp[a[i] + a[j]].push_back({i, j});
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = a[i] + a[j];
                int req = x - sum;
                for (auto z : mp[req]) {
                    if (z.first != i && z.first != j && z.second != i && z.second != j) {
                        cout << i << " " << j << " " << z.first << " " << z.second;
                        return 0;
                    }
                }
            }
        }
        cout << "IMPOSSIBLE";
        return 0;
}