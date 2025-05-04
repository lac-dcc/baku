#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<pair<int , int>> a;
 
	for(int i = 0; i < n; i++) {
		int x , y;
		cin >> x >> y;
		a.push_back(make_pair(x , 1));
		a.push_back(make_pair(y , -1));
	}
	sort(a.begin() , a.end());
	int cnt = 0 , track = 0;
	for(int i = 0; i < (int)a.size(); i++) {
		track += a[i].second;
		cnt = std::max(cnt , track);
	}
	cout << cnt <<"\n";
}
