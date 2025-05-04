#include <bits/stdc++.h>
using namespace std;
int N,x;
int price[1001];
int pages[1001];
int dp[1001][100001];
int main() {
	cin>>N>>x;
	for(int i = 1; i<=N ;i++){
		cin>>price[i];
	}
	for(int i = 1; i<=N;i++){
		cin>>pages[i];
	}
	for(int i = 1; i<=N;i++){
		for(int j = 1; j<=x;j++){
			if(j-price[i] >= 0){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i]]+pages[i]);
			}
			else{
				dp[i][j]=max(dp[i][j], dp[i-1][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i<=x;i++){
		ans = max(ans,dp[N][i]);
	}
	cout<<ans<<endl;
}