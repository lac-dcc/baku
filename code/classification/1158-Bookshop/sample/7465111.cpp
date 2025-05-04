#include<iostream>
using namespace std;
const int NMAX=1000,XMAX=1e5;
int n,x,price[NMAX+1],pages[NMAX+1],dp[NMAX+1][XMAX+1];
void read(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>price[i];
	}
	for(int i=1;i<=n;i++){
		cin>>pages[i];
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
	}
	for(int k=1;k<=x;k++){
		dp[0][k]=0;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=x;k++){
			if(price[i]>k){
				dp[i][k]=dp[i-1][k];
				continue;
			}
			dp[i][k]=max(dp[i-1][k],dp[i-1][k-price[i]]+pages[i]);
		}
	}
}
int main(){
	read();
	solve();
	cout<<dp[n][x];
	return 0;
}