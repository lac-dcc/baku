#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cin(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define cin2(a,b,n) for(int i=0;i<n;i++) cin>>a[i]>>b[i]
#define float double;
// --------------------------------------------------Make cin faster----------------------------------------------------------------------
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void solve()
{
	int n,x;
	cin>>n>>x;
	vector<pair<int,int>> p(n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first;
		p[i].second=i+1;
	} 
	int z=0;
	sort(p.begin(),p.end());
	int t=0;
	if (n>=4) z=p[n-4].first+p[n-3].first+p[n-2].first+p[n-1].first;
	if (n<4) cout<<"IMPOSSIBLE";
	else if (z<x) cout<<"IMPOSSIBLE";  
	else
	{
		z=0;
		for(int i=n-1;i>=0;i--) if (p[i].first>=x) p.erase(p.begin()+i);
		n=p.size();
		z=p[n-1].first+p[n-2].first+p[n-3].first;
		int index=0;
		for(int i=0;i<n-3;i++) if (z+p[i].first<x) index=i;
		p.erase(p.begin(),p.begin()+index);
		for(int i=0;i<n;i++)
		{
			for(int j=i+3;j<n;j++)
			{
				for(int k=i+1;k<j-1;k++)
				{
					int high=j-1,low=k+1;
					int mid=(high+low)/2;
					while(high>=low)
					{
						int sum=p[i].first+p[j].first+p[k].first+p[mid].first;
						if (sum==x)
						{
							t++;
							cout<<p[i].second<<' '<<p[j].second<<' '<<p[k].second<<' '<<p[mid].second;
							break;
						}
						else if (sum<x) low=mid+1;
						else high=mid-1;
						mid=(high+low)/2;
					}
					if (t) break;
				}
				if (t) break;
			}
			if (t) break;
		}
		if (t==0) cout<<"IMPOSSIBLE";
	}
}
int32_t main()
{
	fast();
	int T=1;
	//cin>>T;
	while(T--) solve();
}
