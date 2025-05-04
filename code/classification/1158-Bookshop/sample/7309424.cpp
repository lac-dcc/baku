#include <bits/stdc++.h>
 
using namespace std ;
 
int main(){
    int n, x;
    cin >> n >> x;
    
    vector<int> price(n), page(n);
    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
 
    for (int& h : price) cin >> h;
    for (int& s : page) cin >> s;
 
    for (int i = 0 ; i < n ; ++i){
        int curr = i % 2, prev = (i + 1) % 2;
        for (int y = 0 ; y <= x ; ++y){
            if (price[i] <= y){
                dp[curr][y] = max(dp[prev][y], dp[prev][y - price[i]] + page[i]);
            }
            else dp[curr][y] = dp[prev][y];
        }
    }
 
    cout << dp[(n - 1) % 2][x] << '\n';
    return 0 ;
}
