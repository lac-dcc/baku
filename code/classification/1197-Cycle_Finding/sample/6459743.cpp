		// Don't touch keyboard untilyou have algo in mind 
		//Try atleast 4 test cases of your own before submission
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include<cmath>
#define int long long
#define vi vector<int>
#define vc vector<char>
#define vec(x) vector<x>
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define seti set<int>
#define setc set<char>
#define setstr set<string>
#define set(x) set<x>
#define mii map<int,int>
#define check(x) if(x)cout<<"YES\n"; else cout<<"NO\n";
#define rev(x) reverse(x)
#define all(x) x.begin(), x.end()
#define inp(x) cin>>x;
#define out(x) cout<<x;
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define repin rep(i,0,n)
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define sz(x) (int)(x).size()
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';cout<<endl;
#define di(a) int a;cin>>a;
#define si(a) string a;cin>>a;
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
 
class triplet{
public:
	int first;
	int second;
	int third;
 
};
 
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
vector<int> relaxant;
void bellman_ford(){
	int x;
	for(int i=1;i<=n;i++){
		x=-1;
		for(auto e:edges){
			int u=e.first;
			int v=e.second;
			int w=e.third;
			if(dist[u] + w < dist[v]){
				dist[v]=w+dist[u];
				relaxant[v]=u;
				x=v;
			}
		}
	}
	if(x==-1){
		cout<<"NO"<<endl;
	}else{
		for(int i = 1; i <= n; ++i)
		{
			x = relaxant[x];
		}
		vector<int> cycle;
 
		for(int v = x; ; v = relaxant[v])
		{
			cycle.push_back(v);
			if(v == x and cycle.size() > 1)
				break;
		}
		reverse(cycle.begin(), cycle.end());
 
		cout << "YES" << endl;
		for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	relaxant.resize(n+1);
	edges.resize(m);
 
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		edges[i] = inp;
	}
 
	for(int i = 1; i <= n; ++i)
	{
		relaxant[i] = -1;
	}
	bellman_ford();	
}
