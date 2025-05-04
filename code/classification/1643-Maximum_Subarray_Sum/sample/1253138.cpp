#include <iostream>
using namespace std;
int arr[100000000];
int main(){
	int n;
	cin>>n;
	for(int i = 0; i< n;i++){
		cin>>arr[i];
	}
	long long total = 0;
	long long maxs = arr[0];
	for(int i = 0; i < n;i++){
		total += arr[i];
		maxs = max(maxs, total);
		if(total < 0){
			total = 0;
		}
	}
	cout<<maxs;
}