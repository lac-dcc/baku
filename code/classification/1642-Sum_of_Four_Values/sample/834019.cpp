#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main(){
 
	int i,j,n,x;
	cin >> n >> x;
 
	std::vector<int> v(n,0);
 
	map<ll,pair<ll,ll>>mp;
 
	for(i=0;i<n;i++){
		cin>>v[i];
	}
	
 
	for(i=0;i<n;i++){
		for(j=0;j<i;j++)
			mp[v[i]+v[j]] = {i,j};
	}
 
 
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			int tmp = x - (v[i]+v[j]);
			if(mp.find(tmp)!=mp.end()){
				auto p = mp[tmp];
				if(p.first !=i && p.second !=i && p.first!= j && p.second!=j){
					cout << i+1 <<" "<<j+1 << " " << p.first+1 << " " <<p.second+1;
					return 0;
				}
			}
		}
	}
 
	cout << "IMPOSSIBLE";
 
 
	
}
 
	
