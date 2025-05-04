#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void debug(){cerr << '\n';}
template<class T, class ...U> void debug(T a, U... b){cerr << a << ' '; debug(b...);}
 
/*
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
 
__int128 n, k, arr[20];
 
signed main(){
    fastio;
    ll x;
    cin >> x; n = x;
    cin >> x; k = x;
    for(int i = 0; i < k; i++) cin >> x, arr[i] = x;
    ll ans = 0;
    for(int i = 1; i < (1 << k); i++){
        __int128 qq = 1, cnt = 0;
        bool flag = true;
        for(int j = 0; j < k; j++){
            if(i & (1 << j)) qq *= arr[j], cnt++;
            if(qq > n){
                flag = false;
                break;
            }
        }
        if(flag){
            if(cnt % 2) ans += n / qq;
            else ans -= n / qq;
        }
    }
    cout << ans << '\n';
}