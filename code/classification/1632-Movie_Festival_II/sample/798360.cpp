#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define arr3 array<int, 3>
#define arr2 array<int, 2>
 
const int maxN = 2e5, maxX = 1e9;
int n, k;
 
int main() {
    cin >> n >> k;
    set<arr3 > s;
    set<arr2 > watching;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s.insert({b, a, i});
    }
    int ans = 0;
    for (auto x : s) {
        auto it = watching.upper_bound({x[1]});
        if (it != watching.begin()) {
            --it;
            watching.erase(it);
        }
        if (watching.size() < k) {
            watching.insert({x[0], x[2]});
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
