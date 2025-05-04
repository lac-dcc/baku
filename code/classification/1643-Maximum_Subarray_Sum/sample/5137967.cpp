// Problem: Maximum Subarray Sum
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1643
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
#define  rep(i,x,y)   for(int i=x ; i<y ; i++)
#define  sz(v)    int((v).size())
#define  all(v)  (v).begin(), (v).end()
#define  gcd  __gcd
#define  endl "\n"
#define pb push_back
#define ll long long int
#define Y cout << "YES" << endl;
#define N cout << "NO" << endl;
#define F first 
#define S second
 
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
int main()
{
	ll n;
	cin>>n;
	vll v(n);
	rep(i,0,n)cin>>v[i];
	ll maxi=INT_MIN;
        ll sum=0;
        if(v.size()==1){
        	cout<<v[0];
            return 0;
        }
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            maxi=max(sum,maxi);
            if(sum<0){
           
              sum=0;
              
            }
         
        }
	cout<<maxi;
}