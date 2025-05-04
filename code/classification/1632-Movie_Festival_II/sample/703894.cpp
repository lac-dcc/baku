#include<bits/stdc++.h>
 
using namespace std;
 
bool cmp(pair<int,int>a, pair<int,int>b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
 
int main()
{
	int n,k;
	cin>>n>>k;
 
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}	
 
	sort(v.begin(),v.end(),cmp);
 
	multiset<int>member;
	for(int i=0;i<k;i++){
		member.insert(0);
	}
 
	int ans=0;
	for(auto itr:v){
		auto it = member.upper_bound(itr.first);
		if(it==member.begin()){
			continue;
		}
		it--;
		ans++;
		member.erase(it);
		member.insert(itr.second);
	}
 
	cout<<ans<<endl;
}