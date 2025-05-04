#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<vector>
 
 
 
#define ll long long
// #define mod 1e9 + 7
 
using namespace std;
 
void sahiljit() {
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif 
}
 
 
 
 
int main(){
 
 
	sahiljit();
 
	int n;
	cin>>n;
 
	set<int> s;
 
	int x;
 
	for(int i=0; i<n; i++){
		cin>>x;
 
		s.insert(x);
 
 
	}
 
 
	cout<<s.size()<<endl;
 
 
	
 
 
 
	
 
}
