#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
 
 
static bool comp(vector<ll> a, vector<ll> b){
	return a[1] < b[1];
}
 
int main() {
	int n;
	cin>>n;
	
	vector<vector<ll>> projects(n,vector<ll>(3));
	
	for(int i = 0;i<n;i++){
		for(int j = 0; j< 3 ; j++){
			cin>>projects[i][j];
		}
	}
	
	sort(projects.begin(),end(projects),comp);
	
	vector<ll> dp(n+1),lis(n);
	dp[0] = 0;
	
	for(int i = 0;i<n;i++){
		lis[i] = projects[i][1];
	}
	
	for(int i = 1;i<=n;i++){
		int l = -1, r = n;
		
		while(l+1<r){
			int m = (r+l)/2;
			
			if(lis[m] < projects[i-1][0]) l = m;
			else r = m;
		}
		dp[i] = dp[i-1];
		dp[i] = max(dp[i], projects[i-1][2] + dp[r]);
	}
	//for(int i = 0;i<=n;i++) cout<<dp[i]<<" ";
	cout<<dp[n];
	
	return 0;
}