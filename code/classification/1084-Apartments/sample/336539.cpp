#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> d(n),a(m);
	for(int i=0;i<n;i++)
	cin>>d[i];
	for(int i=0;i<m;i++)
	cin>>a[i];
	sort(d.begin(),d.end());
	sort(a.begin(),a.end());
	int i=0,j=0,c=0;
	while(j<m&&i<n)
	{if((d[i]>=a[j]-k)&&(d[i]<=a[j]+k))
	 {i++;
	  j++;
	  c++;
	 }   
	 else if(a[j]+k<d[i])
	 j++;
	 else if(a[j]-k>d[i])
	 i++;
	}
	cout<<c;
	return 0;
}