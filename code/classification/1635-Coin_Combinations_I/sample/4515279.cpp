#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int dp[N];
int n;
vector<int> arr;
int x;
 
int main() {
    IO;
    cin >> n >> x;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
//    sort(arr.begin(), arr.end());
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > i)continue;
            dp[i] += dp[i - arr[j]];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << endl;
 
}