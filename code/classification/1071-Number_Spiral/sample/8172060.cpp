#include <bits/stdc++.h>
 
using namespace std;
 
const double eps = 0.000001;
 
bool equa(double a, double b){
    return (abs(a-b) <= eps);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int x, y;
    long long n;
    for (int i=1; i <= t; i++){
        cin >> x >> y;
        n = max(x, y);
        if (n%2 == 0) cout << 1 + n*(n-1) + (x - y) << '\n';
        else cout << 1 + n*(n-1) + (y - x) << '\n';
    }
    return 0;
}
