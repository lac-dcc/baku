#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
 
#define ll long long
#define f first
#define s second
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n; ll x; cin >> n >> x;
    vector<pair<int, int>> v;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll s = x - v[i].f - v[j].f;
            int l = j + 1, r = n - 1, pos1 = -1, pos2 = -1;
            while (l < r) {
                if (v[l].f + v[r].f == s) {
                    pos1 = v[l].s;
                    pos2 = v[r].s;
                    break;
                } else if (v[l].f + v[r].f < s) {
                    l++;
                } else {
                    r--;
                }
            }
            if (pos1 == -1) {
                continue;
            }
            cout << v[i].s << " " << v[j].s << " " << pos1 << " " << pos2 << "\n";
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE\n";
 
}
