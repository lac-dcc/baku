#include<bits/stdc++.h>
using namespace std;
 
// #define int long long
 
#define mod 1000000007;
 
int32_t main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,sum;
	cin>>n>>sum;
	vector<int> arr(n);
	vector<long long> dp(sum+1,0);
	dp[0]=1;
	for(int i=0;i<n;++i)cin>>arr[i];
	// sort(arr.begin(),arr.end());
	for(int i=1;i<=sum;++i){
		
		for(int j=0;j<n;++j){
			int temp = i-arr[j];
			if(temp>=0)
			dp[i] = (dp[i] + dp[temp])%mod;
			
		}
	}
	cout<<dp[sum];
 
	return 0;
}
