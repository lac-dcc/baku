#include <bits/stdc++.h>
using namespace std;
 
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define ll long long
#define pii pair<int, int>
#define F(i, n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
#define all(a) a.begin(), a.end()
 
const int INF = 1000000000;
const long long M = 1e9+7;
 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    F(i, n) cin >> a[i];
    int sum = 0, ms = 0;
    F(i, n){
        sum += a[i];
        if (sum < 0) sum = 0;
        ms = max(ms, sum);
    }
    if (ms == 0) ms = *max_element(all(a));
    cout << ms;
}
 
signed main(){
    ios
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
}