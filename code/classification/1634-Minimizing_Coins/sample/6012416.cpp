#include <bits/stdc++.h>
 
using namespace std;
int a[1000000];
int dp[101][1000001] = {0};
 
int main() {
	int n, x;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=x;i++){
		dp[0][i] = 1000002;
	}
	for(int i=1;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			dp[i][j] = dp[i-1][j];
			if (j-a[i-1]>=0 && dp[i][j-a[i-1]]+1 < dp[i-1][j])
				dp[i][j] = dp[i][j-a[i-1]]+1;
		}
	}
	if (dp[n][x]==1000002)
		cout<<-1<<endl;
	else
		cout<<dp[n][x]<<endl;
	return 0;
}
