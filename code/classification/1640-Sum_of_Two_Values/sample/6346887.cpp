#include <bits/stdc++.h>
using namespace std; 
 
using ll = long long; 
 
int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false); 
    ll n, x; cin >> n >> x; 
    ll a[n], b[n]; 
    for(int i = 0; i < n; i++){
        ll x; cin >> x; 
        a[i] = b[i] = x; 
    }
    sort(b, b+n); ll i = 0; 
    bool flag = true; 
    for(; i < n - 1; i++){
        auto it = lower_bound(b + i + 1, b + n, x - b[i]); 
        if(it != b + n and *it == x - b[i]){
            flag = false; 
            break; 
        }
    }
 
    if(flag == true){
        cout << "IMPOSSIBLE\n"; 
        return 0; 
    }
    ll *y = find(a, a + n, b[i]); 
    cout << y - a + 1 << " "; 
    *y = INT_MIN; 
    cout << find(a, a+n, x-b[i]) - a + 1 << "\n"; 
}
