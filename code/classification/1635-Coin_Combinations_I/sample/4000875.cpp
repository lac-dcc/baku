#include<bits/stdc++.h>
using namespace std;
#define pqsmall(name) priority_queue<int,vector<int>,greater<int>>name;
#define yes "YES\n"
#define no "NO\n"
#define int long long 
#define mod 1000000007
 
inline void debugMode() {
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif // ONLINE_JUDGE
}
 
int binaryexpo( int a, int b ){
    a%=mod;
    int result = 1;
    while( b > 0 ){
        if( b&1 ) result = result * a %mod;
        a = a * a % mod;
        b>>=1;
    }
    return result;
}
 
/*========================**Shubham Kumar**========================*/
 
void solve(){
    int n, x; cin >> n >> x;
    int arr[n];
    for( int i = 0; i<n; i++ ) cin >> arr[i];
    sort( arr, arr + n );
    int dp[x+1];
    memset( dp, 0, sizeof(dp));
    dp[0] = 1;
 
    for( int i = 1; i<=x; i++ ){
        for( int j = 0; j<n; j++ ){
            if( i >= arr[j] ){
                dp[i] = (dp[ i - arr[j] ]%mod + dp[i]%mod)%mod;
            }else break;
        }
    }
 
    cout << dp[x] << endl;
}
 
signed main(){
    debugMode();
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}