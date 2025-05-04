/*Arpit Blagan*/
#include<bits/stdc++.h>
using namespace std;
#define all(arr) arr.begin(),arr.end()
#define lli long long int
#define ll long long
const ll INF=1e18;
const ll NN=1e6+5,mod=1e9+7;
 
int main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;vector<pair<int,int>>arr;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;arr.push_back({a,b});
	}
	sort(all(arr),[](pair<int,int>a,pair<int,int>b){
		return a.second<b.second;
	});
	multiset<int>mul;int ans=0;
	for(int i=0;i<n;i++){
		if(!mul.size()){mul.insert(-1*arr[i].second);ans++;}
		else{
			auto it=mul.lower_bound(-1*arr[i].first);
			if(it==mul.end()){
				if((int)mul.size()<k){
					ans++;mul.insert(-1*arr[i].second);
				}
			}else{
				mul.erase(it);ans++;mul.insert(-1*arr[i].second);
			}
		}
	}cout<<ans;
return 0;	
}