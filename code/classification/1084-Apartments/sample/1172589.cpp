#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
#define ld long double
#define vi vector<int>
#define vs vector<string> 
#define vll vector<long long>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define piii pair<int,ii>
#define piiii pair<iii,int>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define vv vector
#define endl '\n'
 
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll arr1[n],arr2[m];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr1[i];	// desired sizes
	}	
	sort(arr1,arr1+n);
	FOR(i,m)
	{
		cin>>arr2[i];
	}
	sort(arr2,arr2+m);
	
	ll ans=0;
	for (int i=0,j = 0; i < n; ++i)
	{
		while(j<m && arr2[j]<arr1[i]-k)
		{
			j++;
		}
		if(j<m && arr2[j]<=arr1[i]+k){
			ans++;j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
