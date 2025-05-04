#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(0)
#define unless(x) if (!(x))
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
 
// string(count, char)
// check overflow/underflow
 
using namespace std;
 
void solve() {
    int n, v;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v;
        s.insert(v);
    }
    cout << s.size() << "\n";
}
 
int main() {
    fastIO;
    solve();
    return 0;
}