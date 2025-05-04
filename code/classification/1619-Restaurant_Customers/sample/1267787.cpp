#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int s, f;
        cin >> s >> f;
        v.push_back({s, 0});
        v.push_back({f, 1});
    }
    sort(v.begin(), v.end());
    int ct = 0;
    int mx = -1;
    for(int i = 0; i < 2*n; i++) {
        if(v[i].second == 0) {
            ct++;
        } else {
            ct--;
        }
        mx = max(mx, ct);
    }
    cout << mx;
}
