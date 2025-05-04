#include <bits/stdc++.h>
 
using namespace std;
#define int long long
vector <tuple <int, int, int>> v;
vector <long long> dp;
int n;
 
long long solve(int pos){
    if(pos >= n) return 0;
    long long &ans = dp[pos];
    if(~ans) return ans;
 
    int pega, nPega = solve(pos+1);
    int start, end, val;
    tie(start, end, val) = v[pos];
    int next = upper_bound(v.begin(), v.end(), make_tuple(end+1, -1, -1)) - v.begin();
    pega = solve(next) + val;
 
    return ans = max(pega, nPega);
}
 
int32_t main(){
    cin >> n;
    dp.assign(n, -1);
 
    for(int i = 0; i < n; i++){
        int a, b, p;
        cin >> a >> b >> p;
 
        v.emplace_back(a, b, p);
    }
 
    sort(v.begin(), v.end());
 
    cout << solve(0) << "\n";
 
    return 0;
}
