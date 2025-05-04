//wtrl,everybody hangbeat me
#include<bits/stdc++.h>
/*#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>*/
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;
/*=====================================================================*/
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(s) (s).begin(),(s).end()
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define forn(i,p,n) for(int i=p;i<=n;i++)
#define ford(i,p,n) for(int i=n;i>=p;i--)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define INF 1e9
#define PI acos(-1)
/*=====================================================================*/
string int_to_string(ll n)
{
	string s="";
	while(n)
	{
		ll now=n%10;
		s+=now+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
ll string_to_int(string s)
{
	ll n=0;
	rep(i,s.size())
	{
		n*=10;
		n+=s[i]-'0';
	}
	return n;
}
/*======================================================================*/
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
const int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
//think twice,code once
//think once,debug forever
int n,m; 
int a[200020]; 
multiset<int> s;
void solve()
{
	cin>>n>>m;
	rep(i,n)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	rep(i,m)
	{
		int x;
		cin>>x;
		multiset<int>::iterator p=s.upper_bound(x);
		if(p==s.begin())
		{
			cout<<-1<<endl;
		}
		else
		{
			p--;
			cout<<*p<<endl;
			s.erase(p);
		}
	}
}
/*======================================================================*/
signed main()
{
    std::ios::sync_with_stdio(false);
  /*
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  */
  /*====================================================================*/
  int t=1;
  //cin>>t;
  while(t--)
  {
  	solve();
  }
  return 0;
}
/*
?????????��vector?????0??????????RE
??????????
???????int*int??ll
?????�Hll
?????string?????????????????????vector<char>
memset??O(n)
*/
