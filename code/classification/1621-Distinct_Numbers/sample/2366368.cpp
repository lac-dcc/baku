#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int count=1;
	ll n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	sort(arr,arr+n);
	int current=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] != current){
		count++;
		current=arr[i];
		}
	}
	cout<<count<<endl;
	return 0;
}
// 2 2 2 3 3