#include<bits/stdc++.h>
using namespace std;
 
#define ll int64_t
#define mod 1000000007
#define MAX 1000000000000000000
 
 
 
 
 
int main(int argc, char const *argv[])
{
 
	int size;
	int targetSum;
 
	cin>>size>>targetSum;
 
	int arr[size];
 
	for(int idx=0;idx<size;idx++){
		cin>>arr[idx];
	}
 
	map<int,int> bag{};
	vector<int> ans{};
	for(int idx=0;idx<size;idx++){
		int expectedNumber = targetSum - arr[idx];
 
		if(bag.find(expectedNumber) == bag.end()){
			//nothing has been found yet
		}else{
			ans.push_back(bag[expectedNumber]+1);
			ans.push_back(idx+1);
			break;
		}
 
		bag[arr[idx]] = idx;
 
	}
 
	if(ans.size() == 0){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
 
	return 0;
}