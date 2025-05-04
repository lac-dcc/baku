#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9+7;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,x;
	cin>>n>>x;
	int values[n];
	vector<int>cost(x+1,0);
	for(int i=0;i<n;i++){
		cin>>values[i];
		if(values[i]<=x){
			cost[values[i]]=1;
		}}
	for(int i=1;i<=x;i++){
		for(int j =0;j<n;j++){
			if(i-values[j]<0)continue;
			cost[i]=(cost[i]+ cost[i-values[j]])%MOD;
		}
		//cout<<cost[i]<<endl;
	}
	cout<<cost[x]<<endl;
	return 0;
}
