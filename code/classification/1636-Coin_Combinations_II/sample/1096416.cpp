#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	//long long dp[k+1] = {0};
	vector<long long> dp(k + 1, 0);
	int arr[n];
	for(int i = 0;  i < n;  i++)
		cin >> arr[i];
	dp[0] = 1;
	for(int i = 0;  i < n;  i++){
		for(int j = 0;  j <= k;  j++){
			if(j-arr[i] >= 0){
				dp[j] += dp[j-arr[i]];
				dp[j] %= M;
			}
 
		}
	}
	cout << dp[k] << endl;
	return 0;
}
