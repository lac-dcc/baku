#include <bits/extc++.h>
#include <bits/stdc++.h>
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define double long double
#define pb push_back
#define sz(x) (int)(x).size()
#define all(v) begin(v),end(v)
#define debug(x) cerr<<#x<<" = "<<x<<'\n'
#define LINE cout<<"\n-----------------\n"
#define endl '\n'
#define VI vector<int>
#define F first
#define S second
#define MP(a,b) make_pair(a,b)
#define rep(i,m,n) for(int i = m;i<=n;++i)
#define res(i,m,n) for(int i = m;i>=n;--i)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define Case() int _;cin>>_;for(int Case = 1;Case<=_;++Case)
#define pii pair<int,int>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template <typename K, typename cmp = less<K>, typename T = thin_heap_tag> using _heap = __gnu_pbds::priority_queue<K, cmp, T>;
template <typename K, typename M = null_type> using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag> using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
template <typename K, typename M = null_type, typename cmp = less_equal<K>, typename T = rb_tree_tag> using _multitree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
const int N = 1e6+5,L = 20,mod = 998244353,inf = 5e18+5;
template<class T>struct SEG{
	int n;
	struct node{
		int l,r;
		T sum,left_sum,right_sum,max_sum;
	};
	vector<node>arr;
	void init(int _n){
		n = _n;
		arr.clear();
		arr.resize(n<<2);
	}
	void pull(int idx){
		arr[idx].sum = arr[idx<<1].sum+arr[idx<<1|1].sum;
		arr[idx].left_sum = max(arr[idx<<1].left_sum,arr[idx<<1].sum+arr[idx<<1|1].left_sum);
		arr[idx].right_sum = max(arr[idx<<1|1].right_sum,arr[idx<<1|1].sum+arr[idx<<1].right_sum);
		arr[idx].max_sum = max(arr[idx<<1].max_sum,max(arr[idx<<1|1].max_sum,arr[idx<<1].right_sum+arr[idx<<1|1].left_sum));
	}
	void build(const vector<T>&v,int r,int l = 1,int idx = 1){
		if(l==r){
			arr[idx].sum = arr[idx].left_sum = arr[idx].right_sum = arr[idx].max_sum = v[l];
			arr[idx].l = arr[idx].r = l;
			return;
		}
		int m = (l+r)>>1;
		build(v,m,l,idx<<1);
		build(v,r,m+1,idx<<1|1);
		arr[idx].l = l,arr[idx].r = r;
		pull(idx);
	}
	void update(int x,T y,int idx = 1){
		if(arr[idx].l>x or arr[idx].r<x)return;
		if(arr[idx].l==arr[idx].r){
			arr[idx].sum = arr[idx].left_sum = arr[idx].right_sum = arr[idx].max_sum = y;
			return;
		}
		int m = (arr[idx].l+arr[idx].r)>>1;
		if(x<=m)update(x,y,idx<<1);
		else update(x,y,idx<<1|1);
		pull(idx);
	}
	int s1 = 0,s2 = 0;
	T query(int l,int r,int idx = 1){
		if(l<=arr[idx].l and arr[idx].r<=r){
			return arr[idx].max_sum;
		}
		int m = (arr[idx].l+arr[idx].r)>>1;
		if(r<=m)return query(l,r,idx<<1);
		else if(l>m)return query(l,r,idx<<1|1);
		return max(query(l,r,idx<<1),query(l,r,idx<<1|1));
	}
};
template<class T>struct BIT{
	int n;
	vector<T>arr;
	void init(int _n){
		n = _n;
		arr.assign(n,0);
	}
	int lowbit(int x){
		return x&(-x);
	}
	int query(int x){
		int ans = 0;
		for(int i = x;i>0;i-=lowbit(i)){
			ans+=arr[i];
		}
		return ans;
	}
	void update(int x,int y){
		for(int i = x;i<=n;i+=lowbit(i)){
			arr[i]+=y;
		}
	}
};
void readfile(){
	freopen("peacefulsets.in","r",stdin);
	freopen("peacefulsets.out","w",stdout);
}
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int>v(n+5);
	SEG<int>seg;
	seg.init(n+5);
	rep(i,1,n){
		cin>>v[i];
	}
	seg.build(v,n);
	while(q--){
		int x,y;
		cin>>x>>y;
		seg.update(x,y);
		cout<<max(seg.query(1,n),0ll)<<endl;
	}
}
signed main(){
	IOS;
	//readfile();
	solve();
	return 0;
}
