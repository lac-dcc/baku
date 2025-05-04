#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
 
 
/****************************** CODE IS HERE ***********************************/
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    vector <ll> A(n);
    for (ll &i: A) cin >> i;
    ll ans = -1e18, curr = 0;
    for (ll i: A) {
        curr += i;
        ans = max(ans, curr);
        if (curr < 0) curr = 0;
    }
 
    cout << ans;
 
 
    return 0;
}
 