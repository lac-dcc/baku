#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll spiral(ll x, ll y){
    if(x > y) return (x%2 == 0) ? (x*x - y + 1) : ((x-1)*(x-1) + y);
    if(y > x) return (y%2 == 0) ? ((y-1)*(y-1) + x) : (y*y - x + 1);
    else return (x*x) - x + 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,x,y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << spiral(x,y) << endl;
    }
}
