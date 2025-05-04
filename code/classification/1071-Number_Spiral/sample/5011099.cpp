#include <bits/stdc++.h>
using namespace std;
 
long long ans, x, y, n, mx;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--){
        cin >> x >> y;
        mx = max(x, y);
        if(mx % 2 == 0)
            cout << (mx * mx) - (y - 1LL) - (mx - x) << '\n';
        else
            cout << (mx * mx) - (x - 1LL) - (mx - y) << '\n';
    }
}