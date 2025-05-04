#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<queue>
#include<fstream>
#include<math.h>
#include<iomanip>
#include<set>
#include<map>
 
#define ll long long 
 
void solve()
{	int n;
	cin>>n;
	vector<pair<int,int> >v;
	set<int>s;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	//cout<<endl<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<v[i].first<<" "<<v[i].second<<endl;
	// }
 
	int temp=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{ 
		if(s.size()==0){s.insert(v[i].second);temp++;continue;}
		auto it=s.begin();
		if(v[i].first< *it){s.insert(v[i].second);temp++;}
		else {
			while((!s.empty()) && v[i].first >= *it){s.erase(s.begin());it=s.begin();temp--;}
			s.insert(v[i].second);temp++;
		}
		ans=max(ans,temp);
 
	}
	cout<<ans<<endl;
 
}
 
int  main()
{ 	ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int q;
	q=1;
	//cin>>q;
	for(int i=0;i<q;i++)
	{
		solve();
	}
}
