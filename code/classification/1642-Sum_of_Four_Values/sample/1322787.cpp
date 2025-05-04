#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <map>
#define for1(x,y) for(long long x = 1; x<ll(y); x++)
#define forn(x,y,z) for(long long x = y; x< ll(z); x++)
#define for0(x,y,z) for(long long x = y; x< ll(z); x++)
#define PII pair<int,int>
#define FF first
#define SS second
#define PB push_back
#define all(x) x.begin(), x.end()
 
#define forn(x,y,z) for(long long x = y; x< ll(z); x++)
#define for0(x,y,z) for(long long x = y; x< ll(z); x++)
using namespace std;
 
//Errichto Orz debug template
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
 
// ends debug
 
// aliases
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;
 
 
#define vi vector<int> 
#define vl vector<ll> 
#define pb(x) push_back(x)
const double EPS = (1e-7), EPSm= (1e7);
const ll linf = (ll)1e17 + 5;
long double PI = 3.14159265359;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
	
const int MAXN = 1e5+10;
const int NINF = -1e5;
const ll INF = 1e10+10;
const int maxn = 300;
const ll MOD = 998244353;
 
	
// Mathematical functions.
 
int GCD(int a, int b)
{
	if (!b)
		return a;
	return GCD(b, a % b);
}
 
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}
 
int modpow(int x, int n, int m = MOD)
{
	if (n == 0) return 1 % m;
	long long u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1)
		u = (u * x) % m;
	return u;	
}
 
/**
 * m should be prime
 */
int modinv(int x, int m = MOD)
{
	return modpow(x, m - 2, m);
}
 
//////////////////// START CODE HERE ///////////////////////////
	
	
void solve()
{
	int n;
	ll x;
	cin>>n>>x;
	vl v(n);
	forn(i,0,n) cin>>v[i];
	if(n<4){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	ll k=n*(n-1)/2;
	pair<ll,pair<ll,ll>> p[k];
	ll y=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			p[y]={v[i]+v[j],{i,j}};
			y++;
		}
	}
	sort(p,p+k);
	auto noIntersection = [&](pair<ll,ll> a,pair<ll,ll> b){
		if(a.FF == b.FF || a.FF == b.SS || a.SS==b.FF || a.SS==b.SS) return false;
		return true;
	};
	ll l=0,r=k-1;
	while(l<=r)
	{
		ll sum=p[l].FF+p[r].FF;
		if(sum==x && noIntersection(p[l].SS,p[r].SS))
		{
			cout<<p[l].SS.FF+1<<" "<<p[l].SS.SS+1<<" "<<p[r].SS.FF+1<<" "<<p[r].SS.SS+1<<endl;
			return;
		}
		else if(sum<x)
		{
			l++;
		}
		else
			r--;
	}
	cout<<"IMPOSSIBLE"<<endl;
	return;
}
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	//cin >> test;
	//while(test--)
		solve();
	return 0;
}