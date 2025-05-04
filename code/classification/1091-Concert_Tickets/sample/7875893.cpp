#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod=1e9+7;
 
 
void solution() {
    int n, m; cin >> n >> m;
    vector<int> maxPrice(m);
    multiset<int>prices;
    for(int i = 0; i < n; i++) {
        int price; cin >> price;
        prices.insert(price);
    }
    for(int i = 0; i < m; i++) cin >> maxPrice[i];
 
    for(int &curMaxPrice: maxPrice) {
        auto it = prices.upper_bound(curMaxPrice);
        if(it == prices.begin() ) {
            cout << "-1\n";
        } else {
            it--;
            cout << *it << "\n";
            prices.erase(it);
        }
    }
 
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t --){
        solution();
    }
    
    return 0;
}
 
