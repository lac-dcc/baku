#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;string s,t;
const int M = 5e3+5;
int dp[M][M];
int solve(int i,int j){
	if(i == n)return m-j;
	if(j == m)return n-i;
	if(dp[i][j] != -1)return dp[i][j];
	if(s[i]==t[j])return dp[i][j] = solve(i+1,j+1);
	return dp[i][j] = min(min(solve(i,j+1),solve(i+1,j+1)),solve(i+1,j))+1;
}
int main(){
	memset(dp,-1,sizeof(dp));
	
	cin>>s>>t;
	n = s.size(),m=t.size();
	cout << solve(0,0)<<'\n';
 
	return 0;
}