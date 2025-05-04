#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r+", stdin);
   freopen("error.txt", "w+", stderr);
   // freopen("output.txt", "w+", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	cin >> a >> b;
	vector<vector<int>> dp((int)a.length()+1,vector<int>((int)b.length()+1,0));
	for(int i=0;i<a.size()+1;i++){
		dp[i][0]=i;
	}
	for(int i=0;i<b.size()+1;i++){
		dp[0][i]=i;
	}
	for(int i=0;i<(int)a.length();i++){
		for(int j=0;j<(int)b.length();j++){
			if(a[i]!=b[j]){
				dp[i+1][j+1]=min(dp[i+1][j],min(dp[i][j],dp[i][j+1]))+1;
				// cout<<i<<j<<dp[i+1][j+1]<<" ";
			}
			else{
				dp[i+1][j+1]=dp[i][j];
			}
		}
	}
	cout<<dp[a.size()][b.size()];
	return 0;
}