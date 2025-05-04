#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const int MOD = 1e9+7;
const int INF = 1e9;
using namespace std;
 
 
 
ll P(int a,int b){
	if(b == 0){
		return 1;
	}
	ll value = P(a,b/2)%MOD;
	if(b&1){
		return value*value*a;
	}
	return value*value;
}
 
 
string intostr(ll int value){
	return bitset<17>(value).to_string();
}
 
ll fact(int value){
	if(value <= 1){
		return 1;
	}
	return fact(value-1)*value;
}
 
 
 
 
 
 
 
 
int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i=0;i < n;i++){
		cin >> arr[i];
	}
	
	int result[k+1];
	memset(result,0,sizeof(result));
	result[0] = 1;
	
	for(int i=1;i <= k;i++){
		for(int j:arr){
			if(i -j >= 0){
				result[i] = (result[i] + result[i-j]%MOD)%MOD;	
			}
		}
	}
	cout << result[k] <<endl;
	
	
	return 0;
}