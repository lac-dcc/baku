#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
	int n, k;
	cin>>n>>k;
 
	vector<int> v(n);
 
	for(int i=0;i<n;i++)
		cin>>v[i];
 
	int arr[n+1][k+1];
 
	for(int i=0;i<=n;i++){
		for(int sum=0;sum<=k;sum++){
			if(i == 0){
				if(sum == 0) arr[i][sum] = 1;
				else
					arr[i][sum] = 0;  
			}
			else{
				if(sum == 0) arr[i][sum] = 1;
				else{
					if(v[i-1] > sum)
						arr[i][sum] = arr[i-1][sum]%mod;
					else{
						arr[i][sum] = (arr[i-1][sum]%mod) + (arr[i][sum - v[i-1]]%mod);
						arr[i][sum] %= mod;
					}
				}
			}
 
		}
	}
 
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=k;j++)
	// 		cout<<arr[i][j]<<" ";
	// 	cout<<endl;
	// }
 
	cout<<arr[n][k]<<endl;
}
