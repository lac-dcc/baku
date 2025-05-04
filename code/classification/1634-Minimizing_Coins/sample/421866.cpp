#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using namespace std::chrono; 
#define fo(i,n,z) for(int i = z;i<n;i++)
#define Fo(i,n,z) for(ll i = z;i<n;i++)
#define INT_BITS 32
#define mod 1000000007
 
// auto start = high_resolution_clock::now(); 
// auto stop = high_resolution_clock::now(); 
// auto duration = duration_cast<microseconds>(stop - start); 
 
// cout << duration.count() << endl; 
 
int main()
{
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
// int t;
// cin >> t;
 
int n;
cin >> n;
 
int sum;
cin >> sum;
ll dp[sum+1];
int arr[n];
fo(i,n,0)cin >> arr[i];
fo(i,sum+1,0) dp[i] = 1000007;
dp[0] = 0;
fo(i,sum+1,1){
	fo(j,n,0){
		if(i-arr[j] >= 0){
			ll sub = dp[i-arr[j]];
			if(sub != 1000007){
				dp[i] = min(sub+1,dp[i]);
			}
	}
	}
		}
if(dp[sum] != 1000007)cout << dp[sum] << endl;
else cout << -1 << endl;
 
return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 