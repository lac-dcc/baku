#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <set> 
#include <queue>
#include <iomanip>
#include <limits.h>
#include <iterator>
//#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef vector <bool> vb;
typedef pair <int, int> pii;
typedef pair <long, long> pll;
 
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
 
int sum(int x, int y) {
    int sum = x + y;
    if (sum >= mod)
        sum -= mod;
    return sum;
}
 
void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vi dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; ++ i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) {
                dp[i] = sum(dp[i], dp[i - a[j]]);
            }
        }
    }
    cout << dp[x] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    solve();
    return 0;
}
