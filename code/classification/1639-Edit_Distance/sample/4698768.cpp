#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
int dp[N][N];
string s, t;
int n, m;
 
int solve(int idx1, int idx2){
    if(idx1 < 0){
        return idx2 + 1;
    }
    if(idx2 < 0){
        return idx1 + 1;
    }
    if(dp[idx1][idx2] != -1){
        return dp[idx1][idx2];
    }
 
    int ans = 1e5;
    if(s[idx1] == t[idx2]){
        ans = min(ans, solve(idx1 - 1, idx2 - 1));
    }
    else{
        ans = min(ans, 1 + min({solve(idx1 - 1, idx2), solve(idx1, idx2 - 1), solve(idx1 - 1, idx2 - 1)}));
    }
    return dp[idx1][idx2] = ans;
}
 
 
int main(){
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    cin >> s >> t;
 
    n = (int)s.size(), m = (int)t.size();
    memset(dp, -1, sizeof(dp));
    cout << solve(n - 1, m - 1) << '\n';
 
    return 0;
}