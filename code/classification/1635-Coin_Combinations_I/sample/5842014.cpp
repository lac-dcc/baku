#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int N = 1e6+1;
vector<int> dp(N, 0);
int main() {
 
int n, m;
cin >> n >> m;
vector<int> arr(n);
for(auto &it:arr) cin >> it;
dp[0] = 1;
for(int sum=1; sum<=m; ++sum) {
    int count = 0;
    for(int i=0;i<n;++i) {
      if(sum-arr[i]>=0)  count = (count+ dp[sum-arr[i]])%M;
    }
   
    dp[sum] = count ;
}
cout<<dp[m];
    return 0;
}
