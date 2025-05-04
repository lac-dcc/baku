#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
 
using ll = long long;
 
using namespace std;
 
ostream& operator<<(ostream& os, vector<int>& v) {
    for(int el : v)
        os<<el<<" ";
    os<<endl;
    return os;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
 
    vector<int> dp(x+1);
    dp[0] = 0;
    for(int i=1; i<min(v[0], x+1); i++)
        dp[i] = x+1;
    for(int i=v[0]; i<=x; i++) {
        dp[i] = 1+dp[i-v[0]];
        for(int j=1; j<n; j++) 
            if(i-v[j] >= 0) 
                dp[i] = min(dp[i], 1+dp[i-v[j]]);
    }
 
    cout<<(dp[x] >= x+1 ? -1 : dp[x])<<endl;
 
 
    
    return 0;
}
