#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
int main(){
	cin>>n;
	vector <vector<ll> > time;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		vector <ll> x;
		x.push_back(a);
		x.push_back(1);
		vector <ll> y;
		y.push_back(b);
		y.push_back(-1);
		time.push_back(x);
		time.push_back(y);
	}
	sort(time.begin(),time.end());
	int maximum=0;
	int cnt=0;
	for(int i=0;i<time.size();i++){
		cnt+=time[i][1];
		maximum=max(maximum,cnt);
	}
	cout<<maximum<<"\n";
	return 0;
}
