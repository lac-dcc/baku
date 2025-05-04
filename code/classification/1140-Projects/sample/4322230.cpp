#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > v(n, vector<int> (3));
        vector<int> ed(n);
        for(int i = 0; i < n; i++ ){
            cin>>v[i][1]>>v[i][0]>>v[i][2];
            ed[i] = v[i][0];
        }
        sort(v.begin(), v.end());
        sort(ed.begin(), ed.end());
        vector<ll> dp(n+1);
        for(int i = 1; i <= n; i++) {
            int idx = lower_bound(ed.begin(), ed.end(), v[i-1][1]) - ed.begin();
            dp[i] = max(dp[i-1], dp[idx] + v[i-1][2]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
