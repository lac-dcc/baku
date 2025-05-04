#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define vi vector<ll>
#define pii pair<ll,ll>
#define piv pair<ll,vi>
#define pb emplace_back
#define range(a,b) substr(a,b-a+1)
#define all(v)  v.begin(),v.end()
#define w(t)   int t; cin>>t; while(t--)
#define ff first
#define sp(x,y)  fixed<<setprecision(y)<<x;
#define ss second
#define inf 9223372036854775807
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
#define trace(x)   cout<<#x<<" = "<<x<<endl;
#define fasttasfuckboii ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
const ll moddd = 1e9 + 7;
 
ll poww(ll x, ll n) {ll res = 1; while (n > 0) {if (n % 2)   res *= x; n = n >> 1; x *= x;} return res;}
 
void solve()
{
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	//kadanes's algo
	ll sum_so_far = 0, max_so_far = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		sum_so_far += a[i];
		max_so_far = max(max_so_far, sum_so_far);
		if (sum_so_far < 0)
			sum_so_far = 0;
	}
 
	cout << max_so_far;
}
 
 
int main()
{
 
 
	fasttasfuckboii;
	//w(t)
	{
		solve();
	}
}