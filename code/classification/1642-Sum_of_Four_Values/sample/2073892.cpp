#include <iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
int main() {
	// your code goes here
	int n,x;cin>>n>>x;
    vector<int>a(n);
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i)
    {
    	ll xx;
    	cin>>xx;
    	a[i]=xx;
    	v[i]={xx,i};
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			int low=j+1,hi=n-1;
			while(low<hi)
			{
				int p=v[i].first,q=v[j].first,r=v[low].first,s=v[hi].first;
				if(p+q+r+s==x)
				{
					cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[low].second+1<<" "<<v[hi].second+1<<endl;return 0;
				}
				else if(p+q+r+s<x)low++;
				else hi--;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}