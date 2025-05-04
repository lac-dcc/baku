#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#define io_o() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fst first
#define scd second
#define endl "\n"
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pii;
 
int main(){
    io_o(); 
    int n, x; cin >> n >> x;
    map<int, int> cur;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if(cur.count(x - t)){
            cout << cur[x - t] << " " << (i + 1) << endl;
            return 0;
        }
        cur[t] = (i + 1);
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
 
