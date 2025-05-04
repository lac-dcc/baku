#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#define int long long
#define mod 1000000007
#define mod2 998244353
#define append push_back
#define pop pop_back
using namespace std;
 
 
 
 
void solve(){
	int n,k;
	cin>>n>>k;
	array<int,3> a[n];
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][0];
		a[i][2]=i;
	}
	sort(a,a+n);
	int ans2=0;
	int ans[n];
	set<array<int,2>> s;
	for(int i=0;i<n;i++){
		auto it=s.lower_bound({a[i][1]+1});
		if(it!=s.begin()){
			it--;
			ans[a[i][2]]=(*it)[1];
			s.erase(it);
		}
		else ans[a[i][2]]=s.size();
		if(s.size()<k){
			s.insert({a[i][0],ans[a[i][2]]});
			ans2++;
		}
	}
	cout<<ans2;
 
 
}
 
int32_t main(){
    // #ifndef IN_OUT
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
    }
 
}       
 
// correct output 100130
