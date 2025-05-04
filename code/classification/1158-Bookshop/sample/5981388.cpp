#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
 
 
void solve() {
    int n, x;
    cin >> n >> x;
    //int dp[x + 1] = {};
    vector<int> dp(x + 1, 0);  
    int a[n],b[n];
    f(n) {
        cin >> a[i];
    }
    f(n) {
        cin >> b[i];
    }
    f(n) {
        for (int j = x ; j >= a[i] ; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[x] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
