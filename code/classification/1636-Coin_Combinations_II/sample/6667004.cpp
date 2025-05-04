#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int x;
	cin>>x;
	vector<int>a;
	for(int i=0;i<n;i++){
	    int ele;
	    cin>>ele;
	    a.push_back(ele);
	}
	int mod = pow(10,9)+7;
	vector<int>dp(x+1,0);
	dp[0]=1;
	for(int i=0;i<n;i++){
	    for(int j=1;j<=x;j++){
	        if(j-a[i]>=0){
	            dp[j]=(dp[j]+dp[j-a[i]])%mod;
	        }
	    }
	}
	
	cout<<dp[x]<<endl;
}