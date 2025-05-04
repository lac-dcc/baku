#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define fo(a,b) for(int i=a;i<b;i++)
int32_t main()
{
	int n,x;
	cin>>n>>x;
	vector<pair<int,int>> ar(n);
	fo(0,n)
	{
	cin>>ar[i].first;
	ar[i].second=i+1;
    }
 
	sort(ar.begin(), ar.end());
 
	vector<vector<int>> res;
 
for(int j=0;j<n;j++)
{
	
	 fo(j+1,n)
	 {
			int lo=i+1;
			int hi=n-1;
			int sum=x-ar[i].first-ar[j].first;
			while(lo < hi)
			{
				if(ar[lo].first + ar[hi].first == sum)
				{
					vector<int> temp;
					temp.push_back(ar[j].second);
					temp.push_back(ar[i].second);
					temp.push_back(ar[lo].second);
					temp.push_back(ar[hi].second);
					res.push_back(temp);
 
					while(lo<hi && ar[lo].first == ar[lo+1].first)
						lo++;
					while(lo<hi && ar[hi].first == ar[hi-1].first)
						hi--;
 
					lo++ , hi--;
				}
				else if(ar[lo].first + ar[hi].first < sum)
					lo++;
				else
					hi--;
			}
			while(i+1<n && ar[i] == ar[i+1]) i++;
		}
			while(j+1<n && ar[j] == ar[j+1]) j++;
	 }
	int flag=1;
	for(auto i:res)
	{
		flag=0;
		sort(i.begin(), i.end());
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<i[3]<<endl;
		break;
	}
 
	if(flag)
		cout<<"IMPOSSIBLE"<<endl;
 
}
