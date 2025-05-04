#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
	ll temp_sum = 0, final_sum=0;
	int n;
	vector<ll> v;
	cin >> n;
	ll a;
	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	if(n==1){
		cout << v[0];
		return 0;
	}
	final_sum = v[0];
	for(int i=0;i<n;i++){
		temp_sum += v[i];
		if(temp_sum < 0){
			if(temp_sum > final_sum){
				final_sum =  temp_sum;
			}
			else{
				temp_sum = 0;
			}
		}
		else if(temp_sum > final_sum){
			final_sum = temp_sum;
		}
	}
		// if(temp_sum>final_sum)
		// 	final_sum = temp_sum;
	cout << final_sum;
	return 0;
}