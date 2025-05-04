#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 200005
#define int long long
using namespace std;
 
int n;
pair<int, pair<int, int>> r[MAX];
int dp[MAX];
 
int bb(int j) {
    int l = 0, h = j-1;
 
    while(l <= h) {
        int mid = (l+h)/2;
        if(r[mid].first < r[j].second.first){
            if(r[mid+1].first < r[j].second.first) l = mid + 1;
            else return mid;
        }
        else h = mid - 1;
    }
    return -1;
}
int32_t main() {_
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        cin >> r[i].second.first >> r[i].first >> r[i].second.second;
    }
 
    sort(r, r+n);
 
    dp[0] = r[0].second.second;
 
    for(int i = 1; i < n; i++) {
        int pa = r[i].second.second;
 
        int melhor = bb(i);
        if(melhor != -1) pa += dp[melhor];
        dp[i] = max(dp[i-1], pa);
    }
 
    cout << dp[n-1] << endl;
}