#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int x,y;
	vector<pair<int, int>>comings_goings;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		comings_goings.push_back({x,1});
		comings_goings.push_back({y,-1});
	}
 
	int ans=0,s=0;
	sort(comings_goings.begin(),comings_goings.end());
	for(auto x: comings_goings){
		s+=x.second;
		ans=max(s,ans);
	}
	cout << ans << endl;
	return 0;
}
