#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
ll sol(vector<int>&A,int x){
	vector<ll>mp(x+1,0);
	mp[0]=1;
	for(auto j:A){
		for(int i=1;i<=x;i++){
			if(i-j>=0){
				mp[i]+=mp[i-j];
				mp[i]%=1000000007;
			}
		}
	}
	return mp[x];
}
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int x;
	cin>>x;
	V<int>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
 
	cout<<sol(A,x);
	
	
}
