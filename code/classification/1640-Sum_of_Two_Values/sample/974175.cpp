#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define ld long double
 
using namespace std;
 
    const ll N = 1e5 + 7;
    const ll mod = 1e9 + 7;
 
 
 
void solve(){
    int n , x;
    cin >> n >> x;
    map < int , int > mp;
    vector < pair < int , int > > a(n);
 
    for(int i = 0; i < n; ++ i){
        cin >> a[i].fr;
        a[i].sc = i + 1;
        mp[a[i].fr] ++;
    }
    sort(a.begin() , a.end());
    int l , ans;
    for(int i = 0; i < n; ++ i){
            if(a[i].fr > x)continue;
            int y = x - a[i].fr;
            mp[a[i].fr] --;
            if(mp[y]){
                l = y;
                ans = a[i].sc;
                break;
            }
            mp[a[i].fr] ++;
    }
    for(int i = n - 1; i >= 0; -- i){
        if(a[i].fr == l){
            cout << ans << " " << a[i].sc << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main(){
    int tt = 1;
    //cin >> tt;
    while(tt --){
        solve();
    }
    return 0;
}
 
/**
 
**/
