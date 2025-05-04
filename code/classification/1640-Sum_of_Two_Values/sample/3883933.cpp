#include<bits/stdc++.h>
using namespace std;
 
void init_code(){
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.in", "w", stdout);
	#endif // ONLINE_JUDGE
}
 
int main(){
	int n,t; cin>>n>>t;
	map<int,int>mp;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		int val=t-x;
		if(mp.find(val)!=mp.end()){
			cout<<mp[val]+1<<" "<<i+1;
			return 0;
		}
		mp[x]=i;
	}
	cout<<"IMPOSSIBLE";
	 
}