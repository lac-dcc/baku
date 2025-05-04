//                            **************************** Prajwal ********************************
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
 
 
using namespace std;
//using namespace __gnu_pbds;
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// ordered_set <int> s;
// s.find_by_order(k); // returns the (k+1)th smallest element
// s.order_of_key(k); //returns the number of elements in s strictly less than k
 
 
// numbers
#define MOD (1000000007)
const int N=200000;
const long long int INF=1000000000000;
//shortforms
#define fast ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(v) int(v.size())
#define ff first
#define ss second 
#define pb push_back
#define pob() pop_back()
#define pf(a) push_front((a))
#define pof() pop_front()
#define nl '\n'
#define all(v) v.begin(),v.end()
//max and min and sum
#define maxv(a) *max_element(all(a))
#define minv(a) *min_element(all(a))
#define sumv(A,a) accumulate(all(A),a)
//for loops
#define fof(i,a,n) for(ll i=a;i<(n);i++)
#define fob(i,n,a) for(ll i=n;i>=a;i--)
//sorting
#define rev(a) reverse(all(a))
#define as(all,A) sort((A).begin(),(A).end())
#define ds(all,A,x) sort((A).begin(),(A).end(),greater<x>())
//permutations
#define nxtp(a,b) next_permutation(a,b);
//input
#define input(A,n) fof(i,0,n){cin>>A[i];}
#define mk_pair(x,y,a,b) insert(pair<x,y >(a,b))
#define mp(x,y) make_pair(x,y)
//output
#define de(a) cerr<<a<<" ";
#define dispve(A,a,n) fof(i,a,n){cout<<A[i]<<" ";}
#define dismp(m) for(auto x : m){ cout<<x.ff<<" "<<x.ss<<"\n"; }
// shortforms 
typedef long long int ll;
#define int ll
//code begins	
int n,m;
vector<int>a;
vector<int>Graph[N];
int ans =0;
vector<int>d(N,0);
void dfs(vector<bool>&visited, int k);
void bfs(vector<bool>&visited, int k);
//priority_queue<pair<int,int>> q;
//int ans = 0;
void solve()
{
	cin>>n;
	for(int i = 0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		Graph[x].pb(y);
		Graph[y].pb(x);
	}
	vector<bool>visited(n,false);
	dfs(visited,0);
	cout<<ans;
}
 
signed main()
{
	fast;
	int T=1;
	//cin >> T;
	cout<< fixed << setprecision(10);
	while(T--){
		solve();
		cout<<nl;
	}
	return 0;
} 
 
void dfs(vector<bool>&visited, int k){
	if(visited[k] == true) return;
	visited[k] = true;
	// node k
	int mx1 = 0, mx2 = 0;
	vector<int>temp;
	for(auto i : Graph[k]){
		if(visited[i] == false){
			dfs(visited,i);
			temp.pb(d[i]);
		}
	}
	ds(all,temp,int);
	if(temp.size()>0)
	mx1 = temp[0];
	if(temp.size()>1)
	mx2 = temp[1];
	ans = max(ans,mx1+mx2);
	d[k] = mx1+1;
}
