#include<bits/stdc++.h>
#define ll long long
#define inpv(x) for(auto &i:x)cin>>i
#define outv(x) for(auto i:x)cout<<i<<" "
#define all(x) x.begin(),x.end()
 
#define ll long long
using namespace std;
const int N = 1e9 +7;
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,x;
	cin>>n>>x;
	vector<int> price(n+1);
	price[0]=0;
	for(int i=1;i<=n;i++)cin>>price[i];
	vector<int> pages(n+1);
	pages[0]=0;
	for(int i=1;i<=n;i++)cin>>pages[i];
	int dp[n+1][x+1];
 
	for(int i=0;i<=n;i++) dp[i][0]=0;
 
	for(int i=0;i<=x;i++) dp[0][i]=0;
 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j>=price[i])
				dp[i][j]= max ( dp[i-1][j], pages[i] + dp[i-1][j-price[i]]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][x];
 
	return 0;
}