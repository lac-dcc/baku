#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+10;
int n, m, p[mxN], c[mxN];
multiset<int> prices;
 
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        prices.insert(x);
    }
    for(int i = 0 ; i < m ; ++i){
        int t; cin >> t;
        auto it = prices.upper_bound(t);
        if(it == prices.begin()) cout << -1 << '\n';
        else {
            cout << *(--it) << '\n';
            prices.erase(it);
        }
    }
 
}
