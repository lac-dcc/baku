//https://cses.fi/problemset/task/1071
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ll t;
    cin>>t;
    
    while(t--) {
        ll y, x;
        cin>>y>>x;
        
        if(y == 1 && x == 1)
           cout<<1<<"\n";
        else if(y >= x && y % 2 == 0) {
            cout<<y * y - x + 1<<"\n";
        }
        else if(y >= x && y % 2 != 0) {
            cout<<(y - 1) * (y - 1) + x<<"\n";
        }
        else if(x > y && x % 2 == 0) {
            cout<<(x - 1) * (x - 1) + y<<"\n";
        }
        else {
            cout<<x * x - y + 1<<"\n";
        }
    }
}