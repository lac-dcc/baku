/*
ID: rajiv
TASK: test
LANG: C++14
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>
#include<stack>
#include<iomanip>
#include<sstream>
#include<iterator>
#include<random>
#include<chrono>
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ONLINE_JUDGE
 
using namespace std;
 
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cout << '\n';}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << '[' << *it << " = " << a << "]  ";
    err(++it, args...);
}
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
int rnd(int a, int b){ // including a and b
	return a+(rng()%(b-a+1));
}
 
void usaco(string filename) {
    #ifndef ONLINE_JUDGE
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
	#endif
}
 
#define fcout cout<<fixed<<setprecision(15)
#define repp(i,j,k) for(int i=j; i<k; ++i)
#define rep(i,j) repp(i,0,j)
#define rrep(i,j,k) for(int i=j; i>=k; --i)
#define all(x) (x).begin(), (x).end()
#define sortr(x) sort(x.begin(), x.end())
#define lb(x,val) lower_bound(x.begin(), x.end(), val)
#define ub(x,val) upper_bound(x.begin(), x.end(), val)
#define pb push_back
#define endl '\n'
 
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef tuple<lli, lli> tii;
typedef tuple<lli, lli, lli> tiii;
 
//const lli M=998244353ll;
const lli M=1000000007ll;
const double D=1.0;
 
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
 
lli maxl(lli a, lli b){
	return (a>b)? a: b;
}
 
struct node{
	lli pre,suf, tot, msum;
	node(): pre(0ll), suf(0ll), tot(0ll), msum(0){}
};
 
int n,m,k;
lli pos, val;
vector<node> tree;
 
void combine(int p){
	tree[p].tot=tree[2*p].tot + tree[2*p+1].tot;
	tree[p].msum=maxl(tree[2*p].suf + tree[2*p+1].pre ,maxl(tree[2*p].msum, tree[2*p+1].msum));
	tree[p].pre=maxl(tree[2*p].pre, tree[2*p].tot+tree[2*p+1].pre);
	tree[p].suf=maxl(tree[2*p+1].suf, tree[2*p+1].tot+tree[2*p].suf);
}
 
void solve(){
	cin>>k>>m;
	n=1<<(int)ceil(log2(k));
	tree=vector<node>(2*n);
	
	for(int i=n; i<n+k; ++i){
		cin>>tree[i].msum;
		tree[i].suf=tree[i].pre=tree[i].tot=tree[i].msum;
	}
	for(int i=n-1; i>=1; --i){
		combine(i);	
	}
	while(m--){
		cin>>pos>>val; pos+=(n-1);
		tree[pos].msum=val;
		tree[pos].pre=tree[pos].suf=tree[pos].tot=val;
		for(pos>>=1; pos>=1; pos>>=1){
			combine(pos);
		}
		cout<<maxl(0, tree[1].msum)<<endl;
	}	
}
 
int main(){
	fast_io
	//usaco("");
	int tc=1;
	//cin>>tc;
	while(tc--){solve();}
	return 0;
}
 
/*
5 3
1 2 -3 5 -1
2 6
3 1
2 -2
*/
