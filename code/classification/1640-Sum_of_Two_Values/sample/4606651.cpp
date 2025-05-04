//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;
 
using ll = long long;
 
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
//EndCodeSnip
 
int main(){
    int n, x;
    cin >> n >> x;
    vi a(n);
    map<int, int> vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (vals.count(x - a[i])) {
            cout << vals[x - a[i]] << " " << i+1 << "\n";
            return 0;
        }
        vals[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << '\n';
}
