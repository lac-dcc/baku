#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef unsigned long long l1;
typedef double db;
#define pi 2 * acos(0.0)
#define sz(x) (x).size()
#define read(x) \
  int x;        \
  cin >> x
#define prDouble(x, y) fixed << setprecision(y) << x
#define lcm(a, b) (a * b) / __gcd(a, b);
#define sortof(x) sort((x).begin(), (x).end());
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define mm(x, v) memset((x), v, sizeof(x));
#define testcase(t, x) \
  int t;               \
  cin >> t;            \
  for (int x = 1; x <= t; x++)
#define nl << "\n"
 
const int MaxN=1e5+5;
vector<int>Graph[MaxN];
int team[MaxN];
bool possible=true;
 
void dfs(int node,int parent)
{
    if(team[parent]!=-1 and team[node]==team[parent])
    {
	possible=false;
	return;
    }
    if(team[node]!=-1)
	return;
    team[node]=team[parent]^1;
    for(int i:Graph[node])
    {
	if(i!=parent)
	    dfs(i,node);
    }
}
 
void solve() {
    int n,m;
    cin>>n>>m;
    while(m--)
    {
	int u,v;
	cin>>u>>v;
	Graph[u].push_back(v);
	Graph[v].push_back(u);
    }
    memset(team,-1,sizeof team);
    team[0]=0;
    for(int i=1;i<=n;i++)
    {
	if(team[i]==-1)
	    dfs(i,0);
	if(possible==false)
	    break;
    }
    if(possible==false)
	cout<<"IMPOSSIBLE" nl;
    else
    {
	for(int i=1;i<=n;i++)
	    if(team[i]==0)
		cout<<2<<" ";
	    else
		cout<<1<<" ";
    }
    cout nl;
}
 
int32_t main() {
  fast_io;
  solve();
  return 0;
}
