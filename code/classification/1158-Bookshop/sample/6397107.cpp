#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> h(n);
    for(auto &i: h) {
        cin >> i;
    }
 
    vector<int> s(n);
    for(auto &i: s) {
        cin >> i;
    }
 
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
 
    for(int idx = n - 1; idx >= 0; idx--) {
        for(int amt = 0; amt <= x; amt++) {
            int take = 0, not_take = 0;
            if(h[idx] <= amt) {
                take = s[idx] + dp[idx + 1][amt - h[idx]];
            }
            not_take = dp[idx + 1][amt];
            dp[idx][amt] = max(take, not_take);
        }
    }
 
    cout << dp[0][x];
}
 
