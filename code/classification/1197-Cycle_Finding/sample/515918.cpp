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
 
#define fcout cout<<fixed<<setprecision(15)
#define repp(i,j,k) for(int i=j; i<k; ++i)
#define rep(i,j) repp(i,0,j)
#define rrep(i,j,k) for(int i=j; i>=k; --i)
#define all(x) (x).begin(), (x).end()
#define sortr(x) sort(x.begin(), x.end())
#define lb(x,val) lower_bound(x.begin(), x.end(), val)
#define ub(x,val) upper_bound(x.begin(), x.end(), val)
#define pb push_back
 
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
 
void solve(){
	int n,m; cin>>n>>m;
	lli x,y,z;
	vector<tiii> elist;
	rep(i,m){
		cin>>x>>y>>z;
		elist.pb({x,y,z});
	}
	lli f=-1;
	vl dis(n+1, 1e18);
	vl parent(n+1, -1);
	rep(i,n+5){
		f=-1;
		for(auto u:elist){
			tie(x,y,z)=u;
			if(dis[x]+z<dis[y]){
				dis[y]=dis[x]+z;
				parent[y]=x;
				//deb(y, parent[y])
				f=y;
			}
		}
	}
	
	if(f==-1){
		cout<<"NO\n";
	}else{
		vl ans;
		rep(i,n+1) f=parent[f];
		x=f;
		ans.pb(x);
		rep(i,n+5){
			if(x==f and ans.size()>1) break;
			x=parent[x];
			ans.pb(x);
		}
		cout<<"YES\n";
		reverse(all(ans));
		rep(i, ans.size()){
			cout<<ans[i]<<" \n"[i==ans.size()-1];
		}		
	}
	
}
 
int main(){
	fast_io
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif 
	int tc=1;
	//cin>>tc;
	while(tc--){solve();}
	return 0;
}
/*
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
*/
