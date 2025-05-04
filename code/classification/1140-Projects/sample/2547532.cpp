#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define mod 1000000007
#define int long long
#define ordered_set tree<Pair, null_type,less<Pair>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef pair<int,int> Pair;
 
void test()
{
	int n;
	cin>>n;
	pair<Pair,int> arr[n];
	for (int i = 0; i < n; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		arr[i] = {{a,b},c};
	}
	sort(arr,arr+n);
	map<int,int> m;
	for (int i = n-1; i >= 0; i--)
	{
		int p = arr[i].second;
		auto j = m.upper_bound(arr[i].first.second);
		if(j != m.end()) p += j->second;
		j = m.lower_bound(arr[i].first.first);
		if(j!=m.end()) p = max(p,j->second);
		m[arr[i].first.first] = p;
		// cout<<i<<" "<<p<<"\n";
	}
	cout<<m[arr[0].first.first]<<"\n";
}
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while(t--)
	{
		test();
	}
	return 0;
}
