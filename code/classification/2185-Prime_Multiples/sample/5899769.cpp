/*
 _     _                             
| |__ | |__   __ _  __ _ _   _  __ _ 
| '_ \| '_ \ / _` |/ _` | | | |/ _` |
| |_) | | | | (_| | (_| | |_| | (_| |
|_.__/|_| |_|\__,_|\__, |\__, |\__,_|
                   |___/ |___/       
*/
#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define BigInt      __int128
#define endl        '\n'
#define mii         map<ll int,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
 
using namespace std;
 
#define N  100005
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    // cin>>TESTS;
    cerr << "---" << endl;
    while(TESTS--)
    {
        ll int n, k;
        cin >> n >> k;
        vi v(k);
        for(ll int i = 0; i < k; i++) {
            cin >> v[i];
        }
        ll int ans = 0;
        for(ll int mask = 1; mask < (1 << k); mask++ ) {
            ll int nn = n;
            for(ll int i = 0; i < k; i++) {
                if(mask >> i & 1) {
                    nn /= v[i];
                }
            }
            if(__builtin_popcount(mask) % 2 == 1) {
                ans += nn;
            }
            else {
                ans -= nn;
            }
        }
        cout << ans << endl;
    }
    return 0;
}