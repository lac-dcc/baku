#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int Max=1e5+100;
int n;
 
void solve(){
    int x,y;
    cin >> x >> y;
    int dem = max(x,y);
    int coun = dem*dem - (dem-1);
    if(dem%2==0){
        if(x>y){
            cout << coun + (x-y) << '\n';
        }
        else cout << coun - (y-x) << '\n'; 
    }
    else if(dem%2==1){
        if(x>y){
            cout << coun - (x-y) << '\n';
        }
        else cout << coun + (y-x) << '\n'; 
    }
}
 
int32_t main(){
    // freopen("inputf.in","r",stdin);
    // freopen("outputf.in","w",stdout);
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
