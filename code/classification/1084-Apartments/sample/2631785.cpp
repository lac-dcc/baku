#include "bits/stdc++.h"
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
int solve(void);
int32_t main(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}
 
int ptr=0;
bool helper(vector<int>&arr,int n,vector<int>&brr,int i,int k){
	int a=brr[i]-k;
	int b=brr[i]+k;
	while(ptr<n && arr[ptr]<=b){
		if(arr[ptr]>=a){
			ptr++;
			return true;
		}
		ptr++;
	}
	return false;
}
int solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>arr(n);
	vector<int>brr(m);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<m;i++) cin>>brr[i];
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());
 
	int ptr=0;
	int count=0;
	for(int i=0;i<m;i++)
		if(helper(arr,n,brr,i,k)) count++;
	cout<<count<<endl;
	return 0;
}