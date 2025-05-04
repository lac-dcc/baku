#include <bits/stdc++.h>
#define ll long long
const int N=1e6+7;
using namespace std;
 
vector <ll> v[N];
 
ll q, mx=0, s, p, p1, q1;
 
void dfs(ll p1, ll p, ll s=0)
{
	if (s > mx) mx=s, q=p1;
	
	
	for (auto l:v[p1])
	{
		if (p != l)  dfs(l, p1, s+1);
	}
	
}
 
void dfs2(ll p1, ll p, ll s=0)
{
	if (mx < s) mx=s, q1=p1;
	
	
	for (auto l: v[p1])
	{
		if (l != p) dfs2(l, p1, s+1);
	}
}
 
int main()
{
	ll n, m;
	cin >> n;
	
	for (int i=1;i<n;i++) 
	{
		ll x, y;
		
		cin >> x >> y;
		
		v[x].push_back(y);
		v[y].push_back(x);
		
	}
	
	
	dfs(1, 0, 0);
	
	mx=0;
	
	dfs2(q, 0, 0);
	
	cout << mx;
}
