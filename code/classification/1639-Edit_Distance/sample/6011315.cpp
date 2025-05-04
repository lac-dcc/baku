#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[5005][5005];
int rec(string& s1,string& s2,int i,int j,int cost){
	if(i==int(s1.size())){
		return abs(j-int(s2.size()));
	}
	if(dp[i][j]!=-1)return dp[i][j];
	int ans = 1e9;
	if(s1[i]==s2[j])
	ans = rec(s1,s2,i+1,j+1,cost);
	//add:
	if(i<int(s1.size()))
	ans = min(ans,rec(s1,s2,i+1,j,cost+1)+1);
	//remove:
	if(j<int(s2.size()))
	ans = min(ans,rec(s1,s2,i,j+1,cost+1)+1);
	//replace:
	if(j<int(s2.size()) and i<int(s1.size()))
	ans = min(ans,rec(s1,s2,i+1,j+1,cost+1)+1);
	return dp[i][j] = ans;
}
int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);   
    freopen("Error.txt","w",stderr);
#endif
    memset(dp,-1,sizeof(dp));
	string s1,s2;
	cin>>s1>>s2;
	cout<<rec(s1,s2,0,0,0);
}
 
 
 