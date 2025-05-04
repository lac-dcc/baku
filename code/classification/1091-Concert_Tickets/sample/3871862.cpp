#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
 
void solve()
{
	int n,m;
	cin >> n >>m;
	
	multiset<int> mp;
	int x;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		mp.insert(x);
	}
	
	for(int i=0;i<m;i++)
	{
		cin >> x;
		auto it = mp.lower_bound(x);
		
		if(mp.size()==0){
			cout << "-1" << endl;
		} else {
			if(it==mp.end()){
				it--;
				if((*it)<=x){
					cout<<(*it)<<endl;
					mp.erase(mp.find(*it));
				} else {
					cout<<"-1"<<endl;
				}
			} else if(it==mp.begin()){
				if((*it)<=x){
					cout << (*it) << endl;
					mp.erase(mp.find(*it));
				} else {
					cout << "-1" << endl;
				}
			} else {
				if((*it)==x){
					cout << x << endl;
					mp.erase(mp.find(*it));
				} else {
					it--;
					cout << (*it) << endl;
					mp.erase(mp.find(*it));
				}
			}
		}
		
	}
	
}
 
int main()
{
	int tt = 1;
//	cin >> tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}
