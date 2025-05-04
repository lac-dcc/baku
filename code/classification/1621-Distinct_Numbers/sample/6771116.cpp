#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)x.size()
#define pb push_back
#define ln cout << '\n'
#define all(x) (x).begin(), (x).end()
 
void solve(){
    int n;
    cin >> n;
    set <int> s; int x;
    for (int i = 0; i < n; i++){
        cin >> x; s.insert(x);
    }
    cout << sz(s);
}
signed main(){
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int zk = 1;
    //cin >> zk;
    while(zk--){
        solve();
    }
    return 0;
}
