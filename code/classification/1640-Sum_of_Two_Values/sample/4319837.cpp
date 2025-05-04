#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("sum.txt", "r", stdin);
 
    int n, x;
    cin >> n >> x;
 
    map<int, vector<int>> m;
 
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
 
        if (!m.count(a)) m[a].push_back(x - a);
        if (m[a].size() < 3) m[a].push_back(i);
    }
 
    for (auto &p : m) {
        if (m.count(p.second[0])) {
                if (p.second[1] != m[p.second[0]][1]) {
                    cout << p.second[1] << ' ' << m[p.second[0]][1];
                    return 0;
                }
                else if (m[p.second[0]].size() >= 3) {
                    cout << p.second[1] << ' ' << m[p.second[0]][2];
                    return 0;
                }
        }
    }
 
    cout << "IMPOSSIBLE";
}
 
