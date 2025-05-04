#include<bits/stdc++.h>
 
#define endl "\n"
using ll = long long;
using namespace std;
 
 
int main(){
    ll x, y;
    long long t;
    cin >> t;
    while(t--){
    cin >> y >> x;
 
    if (x > y) {
        if (x % 2 == 1){
            cout << x * x - y + 1 << endl;
        } else {
            cout << (x-1) * (x-1) + y << endl;
        }
    } else {  
        if (y % 2 == 1){
            cout << (y-1) * (y-1) + x << endl;
        } else {
            cout << y * y - x + 1 << endl;
        }
    }
    } 
}