#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pii pair<int,int>
#define mii map<int,int>
#define si set<int>
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define ll long long
#define sortv(a) sort(a.begin(),a.end())
#define revv(a) reverse(a.begin(),a.end())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define sumv(a) accumulate(a.begin(),a.end(),0)
#define fi first
#define se second
const int mod = 1e9 + 7;
const int inf = 2e9;
//.........................................................................................................
 
 
 
 
 
 
 
 
signed main() {
 
 
	string a,b;
	cin>>a>>b;
	// cout<<a<<b;
	int n=a.size();
	int m=b.size();
 
	vector<vi>dp(n+1,vi(m+1,0));
 
	for(int j=0;j<=m;j++)dp[n][j]=m-j;
	for(int i=0;i<=n;i++)dp[i][m]=n-i;
 
 
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(a[i]==b[j]){
				dp[i][j]=dp[i+1][j+1];
			}else{
				dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
			}
		}
	}
 
	cout<<dp[0][0];
 
 
 
 
}