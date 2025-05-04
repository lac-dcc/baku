#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mxN = 1e5, mxX = 1e5, MOD = (int) 1e9+7;
 
 
int main()
{
    // #ifndef Mishra
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,s; cin >> n >> s;
    int a[n];
    map<int,int> mp;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i=0;i<n;i++) {
        auto it = mp.lower_bound(s-a[i]);
        if (it != mp.end()) {
            pair<int,int> tmp = *it;
            if (tmp.first == s-a[i] && tmp.second != i) {
                cout << i+1 << " " << tmp.second+1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
