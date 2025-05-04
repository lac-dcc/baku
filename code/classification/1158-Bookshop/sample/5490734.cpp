#include <bits/stdc++.h>
#define  ll long long 
 
using namespace std;
const int M=1e9+7;
const int Nmx=1e6+1;
const int N=1e3+1;
int dp[Nmx];
int h[N];
int s[N];
int main(){
	
	int n,x;
	cin >>n>>x;
		
for(int i= 0;i<n;++i){
	cin >>h[i];
}
for(int i= 0;i<n;++i){
	cin >>s[i];
}
for(int i=0;i<n;++i)
	for(int j=x;j>=h[i];--j)
		dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
 
cout << dp[x];
 
}
