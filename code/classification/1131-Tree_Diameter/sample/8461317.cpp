#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fori(m,n) for(int i=m;i<n;i++)
#define forj(m,n) for(int j=m;j<n;j++)
#define forir(m,n) for(int i=n-1;i>=m;i--)
#define inv(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) { return (a.second < b.second); }
ll power(ll n,ll a){ ll res=1; while(a){ if(a%2) res*=n,a--; else   n*=n,a/=2;} return res;}
ll modpower(ll n,ll a,ll p){ ll res=1; while(a){ if(a%2) res= ((res*n)%p) ,a--; else n=((n*n)%p),a/=2;} return res;}
#define forjr(m,n) for(int j=n-1;j>=m;j--)
#define pyes cout<<"Yes\n";
#define pno cout<<"No\n";
 
 
#define maxn 200001
 
 
int ans = 0;
vector<int>arr[maxn];
int dp[maxn];
 
 
int dfs( int u ,int parent)
{
 
	
	vector<int>ve;
	for( int v: arr[u])
	{
	if( v != parent)
	{
		int get = dfs(v , u);
		ve.push_back(get);
	}
	}
	ve.push_back(0);
	ve.push_back(0);
	int maxi = 0;
	
	sort(ve.begin() , ve.end() , greater<int>());
	int first = ve[0];
	int second = ve[1];
	ans = max(ans , first + second);
	return first + 1;	
}
void solve()
{
 
int n;
cin>>n;
 
fori(0 , n-1)
{
	int a,b;
	cin>>a>>b;
	arr[a].push_back(b);
	arr[b].push_back(a);
}
 
if( n == 2)
{
	cout<<1<<endl;
	return;
}
memset(dp , 0 , sizeof(dp));
int y = dfs(1 , -1);
 
 
cout<<ans<<endl;
return;
}
int main()
{
int t;
t = 1;
while(t--)
{
 
solve();
 
}
return 0; 
}
