#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("sse4")
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ll long long
#define lp(i, n) for (int i = 0; i < n; i++)
#define clr(v, d) memset(v, d, sizeof(v))
#define vi vector<int>
#define ull unsigned long long
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define fr(i, n) for (int i = 0; i < n; i++)
#define pi pair<int, int>
#define vl vector<ll>
#define all(arr) arr.begin(), arr.end()
#define sz(arr) arr.size()
bool compare(const pair<int, double> &i, const pair<int, double> &j)
{
	return i.second < j.second;
}
 
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
 
void txtINPUT()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
 
bool comparator(const pair<ll, int> &p1, const pair<ll, int> &p2)
{
	if (p1.first != p2.first)
		return p1.first > p2.first;
	else
		return p1.second < p2.second;
}
 
int countBits(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n & 1)
			cnt++;
		n = n >> 1;
	}
	return cnt;
}
const int MOD=1e9+7;
ll mul(const long long v1, const long long v2) {
    return (v1 * v2) % MOD;
}
 
ll fastpower(ll a, ll p) {
    ll res = 1;
    while (p != 0) {
        if (p & 1)
            res = mul(res, a);
        p >>= 1;
        a = mul(a, a);
    }
    return res;
}
//int dx[]={1,1,1,0,0,-1,-1,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
struct dsu
{
	vector<int> parent;
	vector<int> size;
 
	void init(int n)
	{
		parent.resize(n + 1);
		size.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}
 
	int root(int node)
	{
		if (parent[node] == node)
			return node;
		return parent[node] = root(parent[node]);
	}
 
	bool isUnion(int node1, int node2)
	{
		int p1 = root(node1);
		int p2 = root(node2);
		if (p1 == p2)
			return true;
 
		return false;
	}
 
	int getSize(int node)
	{
		int p = root(node);
		return size[p];
	}
 
	void link(int node1, int node2)
	{
		int p1 = root(node1);
		int p2 = root(node2);
 
		if (size[p1] > size[p2])
			swap(p1, p2);
 
		parent[p1] = p2;
		size[p2] += size[p1];
	}
};
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first == b.first;
}
 
/* Topological sort  */
/* bool dfs(int in,vector<int>adj[],vector<int>&v,vector<int>&r,vector<int>&ans){
        if(r[in])return false; // recursion stack
        if(v[in])return true; // visited stack
        v[in]=1;
        r[in]=1;
        for(int i=0;i<adj[in].size();i++) 
            if(!dfs(adj[in][i],adj,v,r,ans))return false;
        ans.push_back(in);
        r[in]=0;
        return true;
    }*/
const int OO = (int)1e8;
const double EPS = (1e-7);
const int maxN = 100000 + 1;
	
 
int main()
{
	FastIO();
	ll n , x , sum , req ; 
	cin >> n >> x ;
	vector<pi> a(n) ;
	for(int i = 0 ;i < n ; i++)
	  cin >> a[i].first , a[i].second = i + 1 ;
	sort(a.begin() , a.end()) ;
   map<int , pi > m ;
   for(int i = 0 ; i < n ; i ++){
       
	   for(int j = i + 1 ; j < n ; j ++){
		   sum = a[i].first + a[j].first ;
		   req = x - sum ;
		   if ( m.find(req) != m.end() ){
			  int ans[4] = {a[i].second,a[j].second,m[req].first,m[req].second} ;
			  sort(ans , ans + 4);
			  cout << ans[0] << " " << ans[1] << " "<< ans[2] <<" " << ans[3] << "\n" ;
			  return 0 ;
		   }
	   }
 
	    // hash all 2 sum from 0 to i 
		   for(int k = 0 ; k < i ; k++)
		   m.insert( { a[k].first + a[i].first , {a[k].second,a[i].second} } ) ;   
   }
   cout << "IMPOSSIBLE\n" ;
	return 0;
}
