#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
//https://leetcode.com/problems/closest-subsequence-sum/description/
//Meet in the middle
//complexity for n<=40
//O(N* 2^N/2) ~ 0.4 * 10^8
 
vector<ll> subsetsum(vector<ll>& a, ll n){
 
	vector<ll> ans;
	for(ll i =0;i<(1<<n);i++){ //all possible binary representation
		ll s = 0;
 
		for(ll j = 0;j<n;j++){
			if(i&(1<<j)){
				s+=a[j];
			}
		}
 
		ans.push_back(s);
	}	
 
	return ans;
 
}
 
 
void solve(){
	ll n,k;
	cin>>n>>k;
 
	vector<ll> a(n);
 
	for(auto &x : a){
		cin>>x;
	}
 
	ll n1 = (n+1)/2;
	ll n2 = n-n1;
 
	vector<ll> left;
	vector<ll> right;
 
	for(ll i =0 ;i<n;i++){
 
		if(i<n1){
			left.push_back(a[i]);
		}else{
			right.push_back(a[i]);
		}
	}
 
	vector<ll> lefts = subsetsum(left,n1);
	vector<ll> rights = subsetsum(right,n2);
 
	sort(rights.begin(),rights.end());
 
	ll ans = 0;
 
 
	for(auto x : lefts){
		ll fnd = k-x;
 
		int lower = lower_bound(rights.begin(),rights.end(), fnd) - rights.begin();
		int upper = upper_bound(rights.begin(),rights.end(),fnd) - rights.begin();	
 
		if(upper!=0){
			ans+=(upper-lower);
		}
	}
	cout<<ans<<endl;
 
 
}   
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t t1=clock();
    int t=1;
    // cin>>t;
 
    while(t--){
        solve();
    }
    cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}
