#include<iostream>
 
using namespace std;
 
void solve() {
    long long y, x;
    cin >> x >> y;
    long long ans = 0;
    y--;
    x--;
 
    long long flag = 1;
    if(y > x) {
        if(y%2 == 0) {
            flag = -1;
            y = (y+1) * (y + 1);
        } else {
            y = y * y + 1;
        }
        cout << y + x*flag << "\n";
    } else {
 
        if(x%2) {
            
            x = (x+1) * (x+1);
            flag = -1;
        } else {
            x = x * x + 1;
        }
 
        cout << x + y*flag << "\n";
    }
}
 
 
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
