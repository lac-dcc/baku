#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
 
        // u trenutku a, dolazi nova musterija
        s.insert({a, 1});
        // u trenutku b, odlazi neka musterija
        s.insert({b, -1});
    }
 
    int ans = 0;    // globalni maksimum
    int cnt = 0;    // broj gostiju u nekom trenutku
    for (auto it : s) {
        cnt += it.second;
        ans = max(ans, cnt); 
    }
 
    cout << ans << "\n";
 
    return 0;
}
