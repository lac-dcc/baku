#include <bits/stdc++.h>
using namespace std;
 
int main(void){
	long long n;
	cin>>n;
	vector<long long> numbers(n);
	for(long long i = 0 ; i < n ; i++)
		cin>>numbers.at(i);
	
	long long maxSum = numbers.at(0);
	long long currentSum = 0;
 
	for(long long i = 0 ; i < n ; i++){
		currentSum += numbers.at(i);
 
		if(currentSum > maxSum)
			maxSum = currentSum;
 
		if(currentSum < 0)
			currentSum = 0;
	}
 
	cout<<maxSum;
 
	return 0;
}	
