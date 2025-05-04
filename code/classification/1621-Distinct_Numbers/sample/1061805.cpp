// Created by ganesh bhandarkar
#include <bits/stdc++.h>
 
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
 
using namespace std;
using ll = long long;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    map<ll, ll> m;
	for(ll i=0;i<n;i++){
		cin>>a[i];	
		m[a[i]]++;
	}	
	ll c =0;
	for(auto i : m){
		if(i.second)c++;
	}	
	cout<<c;
    return 0;
}
