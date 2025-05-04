#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define N 10000000
#define mod 1000000009
#define pii pair<ll,ll>
#define ll long long int
 
 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x);cerr<<endl;
#else 
#define debug(x)
#endif
 
 
#define pv(v){for(auto i:v)cout<<i<<" ";cout<<endl;}
#define fbo find_by_order
#define ook order_of_key
#define read(v){for(auto &i:v)cin>>i;}
using namespace std;
using namespace __gnu_pbds;
typedef tree <pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag ,  tree_order_statistics_node_update>pbds;
 
void _print(int x){cerr<<x;}
void _print(bool x){cerr<<x;}
void _print(char x){cerr<<x;}
void _print(ll x){cerr<<x;}
void _print(double x){cerr<<x;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
bool sieve[N+1];
 
void createSieve()
{
	for(int i=2;i<=N;i++)sieve[i] = true;
	for(int i=2;i*i<=N;i++)
	{
		if(sieve[i])
		{
			for(int j=i*i;j<=N;j+=i)
			{
				sieve[j] = false;
			}
		}
	}
}
vector<ll>primes;
void createPrimes()
{
	for(int i=2;i<=N;i++)
	{
		if(sieve[i])primes.push_back(i);
	}
	return;
}
ll power(ll a,ll b)
{
 
	ll res = 1;
	while(b)
	{
		if(b&1)
		{
			res = (res*a)%mod;
			b--;
		}
		else
		{
			a = (a*a)%mod;
			b>>=1;
		}
	}
	return res%mod;
}
int fns(int x)
{
	int start = 0;
	int end = 1e4;
	while(start<end)
	{
		int mid = (start+(end-start)/2);
		if(mid*mid==x)return x;
		else if(mid*mid<x)start = mid+1;
		else end = mid;
	}
	return start*start;
}
// void createSievee()
// {
// 	for(int i=1;i<=N;i++)
// 	{
// 		sieve[i] = -1;
// 	}
// 	for(int i=2;i*i<=N;i++)
// 	{
// 		if(sieve[i]==-1)
// 		{
// 			for(int j=i;j<=N;j+=i)
// 			{
// 				if(sieve[j]==-1)sieve[j] = i;
// 			}
// 		}
// 	}
// }
bool isPalindromee(string str)
{
	int start = 0;
	int end = str.length()-1;
	while(start<end)
	{
		if(str[start++]!=str[end--])return false;
	}
	return true;
}
vector<int> prefix_kmp(string str)
{
	int n = str.size();
	vector<int>pi(n,0);
	for(int i=1;i<n;i++)
	{
		int j = pi[i-1];
		while(j>0 && str[i]!=str[j])
		{
			j = pi[j-1];
		}
		if(str[i]==str[j])j++;
		pi[i] = j;
	}
	return pi;
}
vector<int> rabin_karp_patternMatch(string s,string t)
{
	vector<int>occurences;
	const int p = 31; 
    int S = s.size(), T = t.size();
 
    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % mod;
 
    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % mod; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % mod; 
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + mod - h[i]) % mod; 
        if (cur_h == h_s * p_pow[i] % mod)
            occurences.push_back(i);
    }
    return occurences;
}
vector<int> z_function(string str)
{
	int n = str.size();
	vector<int>z(n,0);
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)z[i] = min(z[i-l],r-i+1);
		while(i+z[i]<n && str[z[i]]==str[i+z[i]])++z[i];
		if(i+z[i]-1>r)
		{
			l = i;
			r = i+z[i]-1;
		}
	}
	return z;
}
ll compute_hash(string str)
{
	ll hashValue = 0;
	ll p = 31;
	int n = str.size();
	ll pow = 1;
	for(ll i=0;i<n;i++)
	{
		hashValue+=((str[i]-'a'+1)*pow)%mod;
		pow = (pow*p)%mod;
	}
	return hashValue;
}
void check(vector<int>v,int x,bool &flag)
{
	vector<int>z;
	for(auto i:v)if(i!=x)z.push_back(i);
    for (int i = 0; i < (int)z.size(); ++ i)
		if (z[i] != z[z.size()-1- i])
			return;
    flag = true;
    return;
}
void solve(int x)
{
	int n,z;
	cin>>n>>z;
	vector<int>v(n);
	read(v);
	vector<vector<int>>dp(n,vector<int>(z+1,-1));
	for(int i=0;i<=z;i++)
	{
		if(i%v[0]==0)dp[0][i] = i/v[0];
		else dp[0][i] = 1e9;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=z;j++)
		{
			int p = INT_MAX;
			int np = dp[i-1][j];
			if(v[i]<=j)p = 1+dp[i][j-v[i]];
			dp[i][j] = min(p,np);
		}
	}
	if(dp[n-1][z]==1e9)cout<<-1<<endl;
	else cout<<dp[n-1][z]<<endl;
}
int main() 
{
	#ifndef ONLINE_JUDGE
	// for getting input from in
	freopen("input.txt","r",stdin);
	freopen("Error.txt","w",stderr);
	// for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t = 1;
	int x = 1;
	while(t--)
	{
		solve(x);
		x++;
	}
	return 0; 
}