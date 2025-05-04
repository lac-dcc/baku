#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int amount;
	cin>>amount;
	int coins[n];
	//inserting to the array of coin denominations
	for(int i=0;i<n;i++)
	 cin>>coins[i];
	
	long long dp[amount+1];
        for(int i=0;i<=amount;i++)
            dp[i]=0;
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++)
                dp[j]=(dp[j]+dp[j-coins[i]])%1000000007;
        }
        cout<< dp[amount];
	
	
	
	return 0;
}