#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
long long int sub=INT_MIN;
long long int sum=0;
	for(int i=0;i<n;i++){
		//cout<<i<<" ";
		sum+=a[i];
		//cout<<sum<<" ";
		if(sum<a[i]){
			sub=a[i];
			sum=a[i];
		}
		sub=max(sub,sum);
		if(sum<0) sum=0;
	//	cout<<sub<<" "<<"\n";
	}
	cout<<sub;
}
