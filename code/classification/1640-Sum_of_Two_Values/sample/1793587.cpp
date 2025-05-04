/*
	Author: Luis Canuel Díaz Barón (LUISCO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 3e2 + 3;
 
int N;
int x;
vector<int> arr;
 
void solve()
{
	cin >> N >> x;
	map<int, int> mp;
	for(int i = 0; i < N; i++)
	{
		int a = 0;
		cin >> a;
		if(mp.find(x - a) != mp.end())
		{
			cout << mp[x - a] + 1 << " " << i + 1;
			return;
		}
		mp[a] = i;
	}
	cout << "IMPOSSIBLE";
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
 
	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}
