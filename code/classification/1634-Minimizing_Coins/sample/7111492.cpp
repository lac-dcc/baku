#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
int main(){
	fast
 
	int n,x;cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int> dp(x+1,INT_MAX);
	dp[0]=0;
	for(int i=0;i<=x;i++){
		for(int j=0;j<n;j++){
			if((i-a[j])>=0 and dp[i-a[j]]!=INT_MAX){
				dp[i] =  min(dp[i],dp[i-a[j]]+1);
				//cout<<dp[i]<<endl;
			}
 
		}
			
	}
	
 
	if(dp[x]!=INT_MAX)
	cout<<dp[x]<<endl;
	else cout<<-1<<endl;	
}
